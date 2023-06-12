#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node, *LinkStack;

int push(LinkStack S, ElementType x){
    Node *L;
    L=(Node*)malloc(sizeof(Node));
    //L=S;//肯定不行,调试就会清楚,此语句只是给指针换了个地址
    printf("%s %s",&L,&S->next);
    //若为L=S,那L就相当于S,
    if(L==NULL){
        return 0;
    } else{
        L->data=x;
        L->next=S->next;
        S->next=L;
        return 1;
    }
    
}
/*int push(LinkStack S, ElementType x)
{
	Node *L;
	L=(Node *)malloc(sizeof(Node));
    if(S==NULL){
		return 0;
	}
	else{
		L->data=x;
		L->next=S->next;
		S->next=L;
		return 1;
	}
}*/

int pop(LinkStack S){
    Node *L;
    L=(Node*)malloc(sizeof(Node));
    if(S->next==NULL) return 0;
    else{
        L=S->next;
        S->next=L->next;
        free(L);
        return 1;
    }
}
ElementType getTop(LinkStack S){//返回栈顶数据
    return S->next->data;
}

void clearStack(LinkStack S){
    S->next=NULL;
}

void destroyStack(LinkStack S){
    Node *L;
    L=S->next;
    while(L!=NULL){
        free(L);
       // L=L->next;
    }
}
int main()
{
    Node *s;
    ElementType x;
    pop(s);
    return 0;
}