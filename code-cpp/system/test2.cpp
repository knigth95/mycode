#include <bits/stdc++.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
using namespace std;
sem_t zzm_empty;//初始为1，表示为空
sem_t apple;//初始为0，表示盘里没苹果
sem_t banana;//初始为0,表示盘里没香蕉

void *dad(void *arg){
    while(1){
        sem_wait(&zzm_empty);//放入苹果
        cout<<"dad-->apple\n"<<endl;
        sem_post(&apple);
        sleep(rand()%10);//随机休眠
    } 
}
void *mom(void *arg){
    while(1){
        sem_wait(&zzm_empty);
        //放入香蕉
        cout<<"mom-->banana"<<endl;
        sem_post(&banana);
        sleep(rand()%10);
    }
}
void *son(void *arg){
    while(1){
        sem_wait(&apple);//apple为1时做减法，0则不做
        cout<<"son-->apple"<<endl;
        //把盘子信号量释放，表示盘子为空，信号量+1
        sem_post(&zzm_empty);
        sleep(rand()%10);
    }
}
void *daughter(void *arg){
    while(1){
        sem_wait(&banana);
        cout<<"daughter-->banana"<<endl;
        sem_post(&zzm_empty);
        sleep(rand()%10);
    }
}
int main(){
    pthread_t father,mother,son1,daughter1;
    //初始化
    sem_init(&zzm_empty,0,1);
    sem_init(&banana,0,0);
    sem_init(&apple,0,0);
    //创建
    pthread_create(&father,NULL,dad,NULL);
    pthread_create(&mother,NULL,mom,NULL);
    pthread_create(&son1,NULL,son,NULL);
    pthread_create(&daughter1,NULL,daughter,NULL);
    pthread_join(father,NULL);
    pthread_join(mother,NULL);
    pthread_join(son1,NULL);
    pthread_join(daughter1,NULL);
}