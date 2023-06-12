#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} QNode;
typedef struct
{
    QNode *front; //队首
    QNode *rear;  //队尾
} LinkQueue;

ElementType front(LinkQueue *Q){//返回队首数据
    return Q->front->data;
}

void destroyQueue(LinkQueue *Q){//销毁
	QNode *p;
	while(Q->front!=NULL){
		p=Q->front->next;
		free(Q->front);
		Q->front=p;
	}
	free(Q); 
} 

int push(LinkQueue *Q, ElementType x){//入队
	QNode *s;
	s=(QNode*)malloc(sizeof(QNode));
	if(s==NULL){
		return 0;
	}
	else{
		s->data=x;
		s->next=NULL;
	}
	if(Q->front==NULL){
		Q->front=s;
		Q->rear=s;
	}
	else{
		Q->rear->next=s;
		Q->rear=s;
	}
	return 1;
}

int pop(LinkQueue *Q){//出队
	QNode *temp;
	if(Q->front==NULL && Q->rear==NULL){
		return 0;
	}
	else{
		temp=Q->front;
		Q->front=temp->next;
		if(Q->rear==temp){
			Q->rear=Q->front;
		}
		free(temp);
		return 1;
	}
}

void clearQueue(LinkQueue *Q)
{
	QNode *p;
	while(Q->front!=NULL){
		p=Q->front->next;
		free(Q->front);
		Q->front=p;
	}
}


int main()
{
    
    return 0;
}