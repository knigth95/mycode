#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
	ElementType *array;
	int front;      //队首位置
	int rear;       //尾指下一个位置
	int length;     //长度
	int capacity;   //总容量
}SeqQueue;

SeqQueue* createQueue(int capacity){
    SeqQueue *L;
    L=(SeqQueue*)malloc(sizeof(SeqQueue));
    L->front=0;
    L->length=0;
    L->capacity=capacity;
    L->rear=0;
    L->array=(ElementType*)malloc(capacity*sizeof(ElementType));
    return L;
}
int empty(SeqQueue *Q){//判空
    if(Q->front==Q->rear) return 1;
    else return 0;
}
ElementType front(SeqQueue *Q){//返回队首数据
    return Q->array[Q->front];
}
int full(SeqQueue *Q){//判满
    if(Q->length==Q->capacity) return 1;
    return 0;
}
int push(SeqQueue *Q, ElementType x){//入队
    if(Q->length==Q->capacity) return 0;
    Q->array[Q->rear]=x;
    Q->length++;
    Q->rear=Q->length;
    return 1;
}
int pop(SeqQueue *Q, ElementType *x){
    if(Q->front==Q->rear) return 0;
    *x=Q->array[Q->front];
    Q->front=(Q->front+1)%Q->capacity;
    Q->length--;
    return 1;
}
void clearQueue(SeqQueue *Q){
	while(Q->front!=Q->rear){
		Q->front=(Q->front+1)%Q->capacity;
		Q->length--;
	}
}
void destroyQueue(SeqQueue *Q){
    while(Q->front!=Q->rear){
		Q->front=(Q->front+1)%Q->capacity;
		Q->length--;
	}
    free(Q->array);
}



int main()
{
    
    return 0;
}