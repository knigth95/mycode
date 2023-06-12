#include <bits/stdc++.h>
using namespace std;
#define time_piece 4 //实验要求，这里以时间片表示
#define advan 2 //优先级
typedef struct PROC{ //进程PCB结构
    char pid;//进程名
    int pri;//优先级
    int cputime;//已用CPUtime,初始为0
    int alltime;//运行所需要的时间
    int state;//状态，1表示运行,0表示完成,-1表示就绪,初始值为-1
}PROC;

typedef struct Node{
    struct PROC data;
    struct Node *next;
}Node,*LinkList;

Node* InitSortedList();//初始化
void insertSortedList(LinkList L,PROC proc);//把高优先级的插入
void reInsert(LinkList L);//进程调度

int main(){
    PROC proclist[9],procz;
    LinkList list=InitSortedList();
    int i;
    for(i=0;i<5;i++){
        proclist[i].pid=(char)(i+65);
        proclist[i].pri=rand()%10;
        proclist[i].alltime=rand()%7;
        proclist[i].cputime=0;
        proclist[i].state=-1;
    }

    for(i=0;i<5;i++){
        if(i==0)
            printf("输入的进程信息为：\n进程名 优先级 cputime alltime 状态\n");
        printf("%c        %d       %d       %d     %d\n",proclist[i].pid,proclist[i].pri,proclist[i].cputime,proclist[i].alltime,proclist[i].state);
        insertSortedList(list,proclist[i]);
    }    
    
    printf("调度完毕:\n");
    printf("进程名 优先级 cputime alltime 状态\n");
    if(&(list->next->data)==NULL){
        cout<<"没有进程"<<endl;
        return 0;
    }
    
    for(LinkList z=list->next;z!=NULL;z=z->next){
        z->data.state=0;
        printf("%c       %d       %d       %d     %d\n",z->data.pid,z->data.pri,z->data.cputime,z->data.alltime,z->data.state);
    }
    for(i=0;i<5;i++) reInsert(list);
    if(&(list->next->data)==NULL){
        cout<<"所有进程完成!"<<endl;
        return 0;
    }
    
    return 0;
}
Node* InitSortedList(){
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next =NULL;
    return head;
}
void insertSortedList(LinkList L,PROC proc){
    LinkList zzm1=L->next;
    LinkList zzm2=(LinkList)malloc(sizeof(Node));
    LinkList zzm3=(LinkList)malloc(sizeof(Node));
    int pri_zzm=proc.pri;
    zzm3->data=proc;
    if(zzm1==NULL){
        L->next=zzm3;
        zzm3->next =NULL;
    }
    else if(zzm1->data.pri >= pri_zzm){
        while(zzm1!=NULL){
            zzm2=zzm1;
            zzm1=zzm1->next ;
        }
        zzm3->next=zzm1;
        zzm2->next=zzm3;
    }
    else{
        if(zzm1!=NULL && zzm1->data.pri >pri_zzm){
            while(zzm1!=NULL && zzm1->data.pri >pri_zzm){
                zzm2=zzm1;
                zzm1=zzm1->next;
            }
            zzm3->next=zzm1;
            zzm2->next=zzm3;
        }
        else{
            zzm3->next=zzm1;
            L->next=zzm3;
        }
    }
}

void reInsert(LinkList L){
    LinkList zzm1=L;
    LinkList zzmList_del=L->next;
    zzmList_del->data.pri -=advan;//优先级-2
    zzmList_del->data.cputime +=time_piece;//cpu时间+4
    if(zzmList_del->data.cputime < zzmList_del->data.alltime)
        insertSortedList(L,zzmList_del->data);
    else 
        L->next=zzmList_del->next;
}


