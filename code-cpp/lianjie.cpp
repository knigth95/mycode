#include<bits/stdc++.h>
using namespace std;

typedef int ElemntType;
typedef struct Node{
    ElemntType date;
    struct Node *next;
}Node,*LinkStack;

LinkStack createStack(){
    Node *top;
    top=(Node*)malloc(sizeof(Node));
    top->next=NULL;
    return top;
}
int empty(LinkStack S){
    if(S->next==NULL) return 1;
    else return 0;
}
int pop(LinkStack S){
    Node *L=S->next;
    if(L->next!=NULL) return 0;
    else {
        L->next=S->next;
        free(S);
        return 1;
    }
}

int main(){
    return 0;
}