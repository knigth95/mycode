#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

BTree createTree(char s[]){
    int k=0,i,top=0;
    BTNode *p,*q[101];
    for(i=0;s[i]!='\0';i++){
        if(isalpha(s[i])){//判断是否是字母
            p=(BTNode*)malloc(sizeof(BTNode));
            p->data=s[i];
            p->lchild=NULL;
            p->rchild=NULL;
            if(k==1) q[top]->lchild=p;
            else if(k==2) q[top]->rchild=p;
        }else if(s[i]=='('){
            top++;
            k=1;
            q[top]=p;
        }else if(s[i]==',') k=2;
        else if(s[i]==')') top--;
    }
    if(i==1) q[1]=p;
    return q[1];
}

void preOrder(BTree bt){
    if(bt!=NULL){
        cout<<bt->data;
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }
}
void inOrder(BTree bt){
    if(bt!=NULL){
        inOrder(bt->lchild);
        cout<<bt->data;
        inOrder(bt->rchild);
    }
}
void destroyTree(BTree bt){
    if(bt!=NULL){
        free(bt);
        destroyTree(bt->lchild);
        destroyTree(bt->rchild);
    }
}

BTree createTree(char s[],int left,int right){
    int k=0,i,top=0;
    BTNode *p,*q[101];
    for(i=left;i<=right;i++){
        if(isalpha(s[i])){
            p=(BTNode*)malloc(sizeof(BTNode));
            p->data=s[i];
            p->lchild=NULL;
            p->rchild=NULL;
            if(k==1) q[top]->lchild=p;
            else if(k==2) q[top]->rchild=p;
        }else if(s[i]=='('){
            top++;
            q[top]=p;
            k=1;
        }else if(s[i]==',') k=2;
        else if(s[i]==')') top--;
    }
    if(i==1) q[1]=p;
    return q[1];
}

int main()
{
    return 0;
}