#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
    ElementType *array; //存放栈数据
    int top;	 		//栈顶
    int capacity;  		//容量
} SeqStack;

SeqStack* createStack(int capacity);

SeqStack* createStack(int capacity){
    SeqStack *s;
    s=(SeqStack*)malloc(sizeof(SeqStack));
    s->top=-1;
    s->capacity=capacity;
    s->array=(ElementType*)malloc(capacity*sizeof(ElementType));
    return s;
}

int empty(SeqStack *S){//判空
    if(S->top==-1) return 1;
    else return 0;
}

int full(SeqStack *S){//判满
    if(S->top==S->capacity-1) return 1;
    else return 0;
}

void clearStack(SeqStack *S){//清空
    while(S->top!=-1) S->top--;//或直接S->top=-1;

}

int push(SeqStack *S, ElementType x){//入栈
    if(S->top==S->capacity-1) return 0;
    else{
        S->top++;
        S->array[S->top]=x;
        return 1;
    }
}

int pop(SeqStack *S){//出栈
    if(S->top==-1) return 0;
    else S->top--;
    return 1; 
}

ElementType top(SeqStack *S){//栈顶数据
    return S->array[S->top];
}

void destroyStack(SeqStack *S){//销毁
    if(S->array!=NULL)     free(S->array);
    S->top=-1;
    S->capacity=0;
    S->array=NULL;
}

int main(){
    return 0;
}
