#include<bits/stdc++.h>
using namespace std;

#define InstructionCount_zzm 20   // 指令页面数
#define MemPageCount_zzm 3       //内存物理块数

//初始化队列
void initializeList(int list[],int number){
    for (int i = 0; i < number; i ++) {
        list[i] = -1;
    }
}
//展示队列状态
void showList(int list[], int number){
    for (int i = 0; i < number; i ++) {
        printf("%2d",list[i]);
    }
    cout<<endl;
}

//展示当前内存状态
void showMemoryList(int list[],int phypages){
    printf("内存中的作业号为：");
    for (int i = 0; i < MemPageCount_zzm; i ++) {
        if (list[i] == -1) break;
        printf(" |%d|",list[i]);
    }
    cout<<endl;
}

void informationCount(int missingCount,int replaceCount,int pageNum){
    printf("缺页次数:%d   缺页率:%d/%d\n",missingCount,missingCount,InstructionCount_zzm);
    double result = (double)(InstructionCount_zzm - missingCount)/(double)InstructionCount_zzm;
    printf("置换次数:%d  命中率:%.2f\n",replaceCount,result);
}

//找到该页面下次要访问的位置
int getNextPosition(int currentPage,int currentPosition,int strList[],int pageNum){
    for (int i = currentPosition+1; i < InstructionCount_zzm; i ++) {
        if (strList[i] == currentPage) {
            return i;
        }
    }
    return 10000;//极大数
}


//最近最久未使用置换算法
void pageLRU(int memoryList[],int phyNum,int strList[],int pageNum){
    //置换次数
    int replaceCount = 0;
    //缺页次数
    int missingCount = 0;
    //记录内存中最近一次访问至今的时间
    int timeRecord[phyNum];
    
    initializeList(timeRecord, phyNum);

    //记录当前页面的访问情况: 0 未访问
    int isVisited = 0;
    
    //记录已经在内存中的页面数量
    int pageCount = 0;
    for (int i = 0; i < InstructionCount_zzm; i ++) {
        isVisited = 0;    
        //时间加一
        for (int p = 0; p < pageCount; p ++) {
            if (memoryList[p] != -1) {
                timeRecord[p] ++;
            }
        }
        //是否需要置换
        for (int j = 0; j < phyNum; j ++) {
            if (memoryList[j] == strList[i]) {
                //该页面已经存在内存中
                //修改访问情况
                isVisited = 1;
                //重置访问时间
                timeRecord[j] = -1;
                //printf("%d\n",strList[i]);
                break;
            }
            if (memoryList[j] == -1) {
                //页面不在内存中且内存未满->直接存入
                memoryList[j] = strList[i];
                pageCount ++;
                //修改访问情况
                isVisited = 1;
                //修改访问时间
                timeRecord[j] ++;
                missingCount ++;
                
                printf("有空页，入作业号：%d\n",strList[i]);
                showMemoryList(memoryList, phyNum);
                break;
            }
        }
        if (!isVisited) {
            //需要置换
            //1.遍历时间记录表，寻找最久未访问的页面所在的内存下标
            int max = 0;
            for (int k = 0; k < phyNum; k ++) {
                if (timeRecord[max] < timeRecord[k]) {
                    max = k;
                }
            }
            //2.将该位置的页面换出
            memoryList[max] = strList[i];
            timeRecord[max] = -1;    
            missingCount++;
            replaceCount++;

            printf("置换入的作业号：%d\n",strList[i]);
            showMemoryList(memoryList, phyNum);
            
        }
    }
    informationCount(missingCount, replaceCount, InstructionCount_zzm);
}

//最佳置换算法
void pageOPT(int memoryList[],int phyNum,int strList[],int pageNum){
    int replaceCount = 0;
    int missingCount = 0;
    int nextPosition[phyNum];
    initializeList(nextPosition, phyNum);    
    int isVisited;
    
    for (int i = 0; i < pageNum; i ++) {
        isVisited = 0;
        //判断是否需要置换->内存已满且需要访问的页面不在内存中
        for (int j = 0; j < phyNum; j ++) {
            if (memoryList[j] == strList[i]) {
                //该页面已经存在内存中
                //记录下一次访问它的位置
                nextPosition[j] = getNextPosition(memoryList[j], i, strList, pageNum);
                
                //修改访问情况
                isVisited = 1;
                break;
            }
            if (memoryList[j] == -1) {
                //页面不在内存中且内存未满->直接存入
                memoryList[j] = strList[i];
                nextPosition[j] = getNextPosition(memoryList[j], i, strList, pageNum);
                missingCount ++;
                //修改访问情况
                isVisited = 1;
                printf("有空页，入作业号：%d\n",strList[i]);
                showMemoryList(memoryList, phyNum);
                break;
            }
        }
        if (!isVisited) {
            int max = 0;
            for (int k = 1; k < phyNum; k ++) {
                if (nextPosition[max] < nextPosition[k]) {
                    max = k;
                }
            }   
            //2.将该位置的页面换出
            memoryList[max] = strList[i];
            nextPosition[max] = getNextPosition(memoryList[max], i, strList, pageNum);
            
            missingCount ++;
            replaceCount ++;
            printf("置换入的作业号：%d\n",strList[i]);
            showMemoryList(memoryList, phyNum);
        }
    }
    informationCount(missingCount, replaceCount,pageNum);
}
//先进先出置换算法
void pageFIFO(int memoryList[],int phyNum,int strList[],int pageNum){
    int replaceCount = 0;
    int missingCount = 0;
    //记录当前最早进入内存的下标
    int pointer = 0;
    int isVisited = 0;
    for (int i = 0; i < pageNum; i ++) {
        isVisited = 0;
        for (int j = 0; j < phyNum; j ++) {
            if (memoryList[j] == strList[i]) { 
                isVisited = 1;
                break;
            }
            if (memoryList[j] == -1) {
                memoryList[j] = strList[i];
                isVisited = 1;
                missingCount ++;
                printf("有空页，入作业号：%d\n",strList[i]);
                showMemoryList(memoryList, phyNum);
                break;
            }
        }
        
        if (!isVisited) {
            memoryList[pointer] = strList[i];
            //下标指向下一个
            pointer ++;
            
            //如果到了最后一个，将下标归零
            if (pointer > phyNum-1) {
                pointer = 0;
            }
            
            
            missingCount ++;
            replaceCount ++;
            
            //展示
            printf("%d\n",strList[i]);
            showMemoryList(memoryList, phyNum);
        }
    }
    informationCount(missingCount, replaceCount, pageNum);
}
int main(int argc, const char * argv[]){
    //生成内存队列
    int memoryList[MemPageCount_zzm];
    //初始化内存状态
    initializeList(memoryList, MemPageCount_zzm);
    
    //保存页面号引用
    int InstructionCount_zzmStrList[InstructionCount_zzm];
    printf("请输入要访问的页面号:\n");
    for (int i = 0; i < InstructionCount_zzm; i ++) cin>>InstructionCount_zzmStrList[i];
    
    printf("请选择所要算法(1.LRU 2.FIFO 3.OPT)：");
    int n;
    cin>>n;
    switch(n){
        case 1:
        pageLRU(memoryList, MemPageCount_zzm, InstructionCount_zzmStrList, InstructionCount_zzm);
        break;
        case 2:
        pageFIFO(memoryList, MemPageCount_zzm, InstructionCount_zzmStrList, InstructionCount_zzm);
        break;
        case 3:
        pageOPT(memoryList, MemPageCount_zzm, InstructionCount_zzmStrList, InstructionCount_zzm);
        break;
    }    
    return 0;
}
/*
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/