#include<bits/stdc++.h>
using namespace std;
typedef char zzm;
zzm data[100];
int i=0;
typedef struct Node{
    zzm data;
    struct Node *Left;
    struct Node *Rigth;
    int high;
}BtNode,*Btree;
Btree create(){
    BtNode*root;
    char ch;
    ch=getchar();
    if(ch=='.') return NULL;
    else{
        root=(BtNode*)malloc(sizeof(BtNode));\
        root->data=ch;
        root->Left=create();
        root->Rigth=create();
        return root;
    }
}

void inOrder(Btree root){
    if(root!=NULL){
        inOrder(root->Left);
        data[i]=root->data;
        i++;
        inOrder(root->Rigth);
    }
}
void afterOrder(Btree root){
    BtNode *q;
    int time=0,x=0,pre1=0;
    int high=100,pre2=1;
    queue<Node*>s;
    s.push(root);
    while(!s.empty()){
        q=s.front();
        s.pop();
        if(high==q->high) x=pre1+1;
        else{
            if(time!=0) cout<<endl;
        }
        while(q->data!=data[x]){
            cout<<"-";
            x++;
        }
        pre1=x;
        x=0;
        if(high==q->high) cout<<q->data;
        else cout<<q->data;
        high=q->high;
        if(q->Left!=NULL) s.push(q->Left);
        if(q->Rigth!=NULL) s.push(q->Rigth);
        time++; 
    }
    cout<<endl;
}
void inithigh(Btree root,int high){
    if(root!=NULL){
        root->high=high;
        inithigh(root->Left,high+1);
        inithigh(root->Rigth,high+1);
    }
}

int main(){
    int high=0;
    Btree root;
    root=create();
    inithigh(root,0);
    inOrder(root);
    int len=strlen(data);
    afterOrder(root);
    return 0;
}