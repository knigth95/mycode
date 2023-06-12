#include <bits/stdc++.h>
using namespace std;

int main(){
    int num[1000000],k;
    cin>>k;
    int i=0;
    while(1){
        cin>>num[i];
        if(num[i] < 0) break;
        i++;
    }
    if(k>i) cout<<"NULL"<<endl;
    else cout<<num[i-k]<<endl;
    return 0;
}

/*
#include<stdio.h>
#include<malloc.h>
typedef struct Node{
    int data;
    Node *next;
}Node,*List;
int main()
{
    int k;
    scanf("%d",&k);
    Node *L,*p;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    int a;
    while(scanf("%d",&a)&&a>=0)
    {
        p = (Node *)malloc(sizeof(Node)); // 生成新结点
        p->data = a;
        p->next = L->next;    // 插入到表头
        L->next = p;
    }
    for(int i = 0;i<k;i++)
    {
        L = L->next;
    }
    if(L)
        printf("%d\n",L->data);
    else
        printf("NULL\n");
    return 0;
}
*/