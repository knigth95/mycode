#include "sampling.h"
#include "stm32f4xx_hal.h"
#include <string.h>

#define DRDY_PORT GPIOC
#define DRDY_PIN GPIO_PIN_5
#define CS_PORT GPIOC
#define CS_PIN GPIO_PIN_4
#define SYNC_PORT GPIOA
#define SYNC_PIN GPIO_PIN_7

#define ADS131M04_CS_HIGH HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET)
#define ADS131M04_CS_LOW HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET)
#define ADS131M04_SYNC_HIGH HAL_GPIO_WritePin(SYNC_PORT, SYNC_PIN, GPIO_PIN_SET)
#define ADS131M04_SYNC_LOW                                                     \
  HAL_GPIO_WritePin(SYNC_PORT, SYNC_PIN, GPIO_PIN_RESET)

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

extern SPI_HandleTypeDef hspi2;
uint8_t spi_tx_buf[18], spi_rx_buf[18], ad_results[12];
uint16_t ads131m04_read_reg(uint8_t addr);
void ads131m04_write_reg(uint8_t addr, uint16_t val);

uint8_t sample_cplt_flag = 0, sample_running_flag = 0;
uint16_t sample_nCycles = 625;
uint16_t cycles = 0;
int64_t result_sum[4] = {0, 0, 0, 0};
uint16_t adc12_results[2];
uint32_t adc12_result_sum[2] = {0, 0};

int32_t get_sampling_value(uint8_t *p) {
  int32_t rtn = 0;
  uint8_t *ptr = (uint8_t *)(&rtn);
  *(ptr + 3) = *p;
  *(ptr + 2) = *(p + 1);
  *(ptr + 1) = *(p + 2);
  return (rtn >> 8);
}

void sampling_start(uint16_t period) {
  if (period >= 25) {
    sample_nCycles = period;
    cycles = 0;
    sample_running_flag = 1;
    result_sum[1] = 0;
    result_sum[2] = 0;
    result_sum[3] = 0;
    adc12_result_sum[0] = 0;
    adc12_result_sum[1] = 0;
  }
}

void sampling_stop(void) { sample_running_flag = 0; }

void start_ad_conversion(void) {}

void ads131m04_access_frame(uint8_t cnt) {
  ADS131M04_CS_LOW;
  HAL_SPI_TransmitReceive(&hspi2, spi_tx_buf, spi_rx_buf, cnt, 10);
  ADS131M04_CS_HIGH;
}

uint16_t ads131m04_read_reg(uint8_t addr) {
  while (HAL_GPIO_ReadPin(DRDY_PORT, DRDY_PIN) != RESET)
    ;
  spi_tx_buf[0] = ((0x5 << 5) | (addr >> 1));
  spi_tx_buf[1] = (addr << 7);
  ads131m04_access_frame(18);
  spi_tx_buf[0] = 0x0;
  spi_tx_buf[1] = 0x0;
  while (HAL_GPIO_ReadPin(DRDY_PORT, DRDY_PIN) != RESET)
    ;
  ads131m04_access_frame(18);
  return *((uint16_t *)spi_rx_buf);
}

void ads131m04_write_reg(uint8_t addr, uint16_t val) {
  while (HAL_GPIO_ReadPin(DRDY_PORT, DRDY_PIN) != RESET)
    ;
  spi_tx_buf[0] = ((0x3 << 5) | (addr >> 1));
  spi_tx_buf[1] = (addr << 7);
  spi_tx_buf[3] = (val >> 8);
  spi_tx_buf[4] = (val & 0xff);

  ADS131M04_CS_LOW;
  DMA1_Stream3->NDTR = 6;
  DMA1_Stream4->NDTR = 6;
  DMA1_Stream3->CR |= DMA_SxCR_EN;
  DMA1_Stream4->CR |= DMA_SxCR_EN;
  while ((DMA1->LISR & DMA_LISR_TCIF3) == 0)
    ;
  DMA1->LIFCR = (DMA_LIFCR_CTCIF3);
  DMA1->HIFCR = (DMA_HIFCR_CTCIF4);
  ADS131M04_CS_HIGH;
  spi_tx_buf[0] = 0;
  spi_tx_buf[1] = 0;
  spi_tx_buf[3] = 0;
  spi_tx_buf[4] = 0;
}

void ads131m04_init(void) {
  HAL_NVIC_DisableIRQ(DMA1_Stream3_IRQn);
  HAL_NVIC_DisableIRQ(DMA1_Stream4_IRQn);

  DMA1_Stream3->PAR = (uint32_t)(&(SPI2->DR));
  DMA1_Stream4->PAR = (uint32_t)(&(SPI2->DR));
  DMA1_Stream3->M0AR = (uint32_t)spi_rx_buf;
  DMA1_Stream4->M0AR = (uint32_t)spi_tx_buf;

  SPI2->CR1 |= SPI_CR1_SPE;
  SPI2->CR2 |= (SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);

  DMA1_Stream3->CR &= ~DMA_SxCR_EN;
  DMA1_Stream4->CR &= ~DMA_SxCR_EN;

  DMA1->LIFCR = (DMA_LIFCR_CTCIF3);
  DMA1->HIFCR = (DMA_HIFCR_CTCIF4);

  ads131m04_write_reg(0x3, 0xF06);

  HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void ads131m04_start_read(void) {
  ADS131M04_CS_LOW;
  DMA1_Stream3->NDTR = 18;
  DMA1_Stream4->NDTR = 18;
  DMA1_Stream3->CR |= (DMA_SxCR_TCIE | DMA_SxCR_EN);
  DMA1_Stream4->CR |= DMA_SxCR_EN;
}

void ads131m04_complete_read(void) {
  uint8_t i;
  DMA1->LIFCR = (DMA_LIFCR_CTCIF3);
  DMA1->HIFCR = (DMA_HIFCR_CTCIF4);
  ADS131M04_CS_HIGH;
  // ads131m04平均值滤波
  for (i = 0; i < 4; i++) {
    result_sum[i] += get_sampling_value(spi_rx_buf + 3 + 3 * i);
  }

  //采集完所要的数据
  if (++cycles >= sample_nCycles) {
    cycles = 0;
    int32_t val;

    for (i = 0; i < 4; i++) {
      val = result_sum[i] / sample_nCycles;
      val <<= 8;
      uint8_t *ptr = (uint8_t *)(&val);
      ad_results[3 * i] = *(ptr + 3);
      ad_results[3 * i + 1] = *(ptr + 2);
      ad_results[3 * i + 2] = *(ptr + 1);
      result_sum[i] = 0;
    }
    adc12_results[0] = adc12_result_sum[0] / sample_nCycles;
    adc12_results[1] = adc12_result_sum[1] / sample_nCycles;
    adc12_result_sum[0] = 0;
    adc12_result_sum[1] = 0;
    if (sample_running_flag)
      sample_cplt_flag = 1;
  }
}

void led_toggle(void) {
  static uint16_t cnt = 0;
  if (++cnt == 16000) {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
    cnt = 0;
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  if (GPIO_Pin == GPIO_PIN_5) {
    // adc12平均值滤波
    adc12_result_sum[0] += (0xfff & HAL_ADC_GetValue(&hadc1));
    adc12_result_sum[1] += (0xfff & HAL_ADC_GetValue(&hadc2));
    ads131m04_start_read();
    HAL_ADC_Start(&hadc1);
    HAL_ADC_Start(&hadc2);
    if (sample_running_flag)
      led_toggle();
  }
}

uint8_t sampling_read_results(uint8_t *buf) {
  if (sample_cplt_flag) {
    sample_cplt_flag = 0;
    __disable_irq();
    memcpy(buf, ad_results, 12);
    memcpy(buf + 12, (uint8_t *)adc12_results, 4);
    __enable_irq();
    return 1;
  } else
    return 0;
}
