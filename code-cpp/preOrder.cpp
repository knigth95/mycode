#include <bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct CSNode
{
    ElementType data;
    struct CSNode * child;
    struct CSNode * sibling;
}CSTNode,*CSTree;

void preOrder(CSTree root){//先序遍历
    CSTree p;
    if(root!=NULL){
        cout<<root->data;
        preOrder(root->child);
        if(root->child!=NULL){
            for(p=root->child->sibling;p!=NULL;p=p->sibling)
                preOrder(p);
        }
    }
}

void postOrder(CSTree root){//后序遍历
    CSNode *p;
    if(root!=NULL){
        postOrder(root->child);
        if(root->child!=NULL){
            for(p=root->child->sibling;p!=NULL;p=p->sibling)
                postOrder(p);
        }
        cout<<root->data;
    }
}
int main()
{
  
    return 0;
}
