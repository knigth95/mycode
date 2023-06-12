#include <bits/stdc++.h>
using namespace std;

#define InstructionCount_zzm 20   // 指令页面数
#define MemPageCount_zzm 3       //内存物理块数

int work_list [InstructionCount_zzm]; //存储作业序列
int num;        //存储要输入的序列的长度
int memory_alloacte [MemPageCount_zzm];   // 现在在进程中的页面序列
int cnt; // 记录已经分配的作业的下标

void input(){
    printf("请输入作业的个数:");
    cin>>num;
    if (num > InstructionCount_zzm)  {
        printf("序列过长\n");
        return;    
    }
    printf("请输入作业序列(采用最佳置换算法)：\n");
    for(int i = 0;i < num; i ++) cin>>work_list[i];
    
    for(int i = 0;i < InstructionCount_zzm ; i ++) memory_alloacte[i] = -1;
    
    for(int i = 0;i < MemPageCount_zzm;i ++){
        memory_alloacte[i] = work_list[i];
        cnt = i;
    }
}

void print(int* work_list,int* memory_alloacte ){
    printf("\t现在进程中的页面序列：");
    for(int i = 0; i < MemPageCount_zzm; i ++){
        printf("%2d\t",*(memory_alloacte+i));
    }
    printf("\t当前剩余的作业序列:");
    for(int i = cnt+1; i < num;i ++){
        printf("%2d",*(work_list+i));
    }
    cout<<endl;
}

int judge(){
    int temp [MemPageCount_zzm];
    //赋值一个临时变量 记录此时物理框中的作业号
    int count = MemPageCount_zzm;
    //记录临时变量物理框中还剩下的个数
    for(int i = 0;i < MemPageCount_zzm; i ++){
        temp[i] = memory_alloacte[i];   
    }   
    int cur = cnt + 1;
    while (cur < num)
    {
       for (int i = 0; i < MemPageCount_zzm; i++)
       {
           if(work_list[cur] == temp[i]){ 
            //剩下的工作序列中 若作业还会调用的话，就将其的值置为-1    
               if(count == 1)  return i;            
               //剩下的那个作业号很久没被调用的
               temp[i] = -1;
               count--;
               break;
           }
       }
       cur++;
    }
    //遍历临时的物理块中作业号的，值不为-1时，没有该作业直接返回。  
    for(int i = 0;i < MemPageCount_zzm;i ++){
        if(temp[i] != -1) return i;
        else continue;
    }
    return 0;
}

void change(){
    int index;
    int flag = 0;
    for (int i = cnt + 1; i < num; i++)
    {   
        for (int j = 0; j < MemPageCount_zzm; j++)          
        //判断下一个作业是否已经在内存中
        {
            if(work_list[i] == memory_alloacte[j]){
                flag = 1;//是的标为1
                break;
            }
        }
        if(flag == 0){//不在内存中，会出现页面中断，要进行换页。
            index = judge();
            if(memory_alloacte[index] != work_list[i]){
                memory_alloacte[index] = work_list[i];
            }
            cnt++;
            print(work_list,memory_alloacte);
        }
        else
        {
            flag = 0;
            cnt ++;
            print(work_list,memory_alloacte);
            continue;
        }
        
    }
}
int main(){
    input();
    change();
    system("pause");
}
/*
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/