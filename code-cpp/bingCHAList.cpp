#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
    int * parent;
    int size;
}SNode,* Set;

Set createSet(int size){
    SNode *big;
    big=(SNode*)malloc(sizeof(SNode));
    big->parent=(ElementType*)malloc(size*sizeof(ElementType));
    big->size=size;
    for(int i=1;i<=size;i++) big->parent[i]=i;
    return big;
}

void initSet(Set S){
    for(int i=0;i<S->size;i++) S->parent[i]=-1;   
}

int findSet(Set S,int x){
    int t=x;
    while(S->parent[t]!=-1) t=S->parent[t];//查找根节点
    int k;
    while(S->parent[x]!=-1){//交换压缩路径
        k=S->parent[x];
        S->parent[x]=t;
        x=k;
    }   
    return t;
}

void unionSet(Set S,int x,int y){
    int t1=x;
    while(S->parent[t1]!=-1)  t1=S->parent[t1];
    int k1;
    while(S->parent[x]!=-1){
        k1=S->parent[x];
        S->parent[x]=t1;
        x=k1;
    }
    int rx=t1;
    int t2=y;
    while(S->parent[t2]!=-1) t2=S->parent[t2];
    int k2;
    while(S->parent[y]!=-1){
        k2=S->parent[y];
        S->parent[y]=t2;
        y=k2;
    }
    int ry=t2;
    if(rx!=ry) S->parent[rx]=ry;
}
void destroySet(Set S){
    if(S!=NULL) free(S->parent);
}


int main()
{
    return 0;
}



