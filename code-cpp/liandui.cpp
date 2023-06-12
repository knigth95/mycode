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

int push(LinkQueue *Q, ElementType x){
    QNode  *s;
    s=(QNode*)malloc(sizeof(QNode));
    if(Q->rear!=NULL) return 0;
    else {
        s->data=x;
        s->next=NULL;
        Q->rear->next=s;
        Q->rear=s;
        return 1;
    }
}

int main()
{
    return 0;
}