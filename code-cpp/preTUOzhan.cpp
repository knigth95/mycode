#include<bits/stdc++.h>
using namespace std;
typedef char zzm;
typedef struct Node{
    zzm data;
    struct Node *Left;
    struct Node *Rigth;
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

void preOrder(Btree root){
    if(root!=NULL){
        preOrder(root->Left);
        printf("%c",root->data);
        preOrder(root->Rigth);
    }
}

int main(){
    BtNode *root;
    root=create();
    preOrder(root);
    cout<<endl;
    return 0;
}