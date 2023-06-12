#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node{
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
}BSTNode, *BSTree;

BSTNode* findMax(BSTree bst){//查找最大值
    if(bst)
        while(bst->rchild) bst=bst->rchild;
    return bst;   
}
BSTNode* findMin(BSTree bst){
    if(!bst) return NULL;
    while(bst->lchild) bst=bst->lchild;
    return bst;
}
BSTNode* find(BSTree bst, ElementType x){//查找
    while(bst){
        if(bst->data<x) bst=bst->rchild;
        else if(bst->data>x) bst=bst->lchild;
        else return bst;
    }
    return NULL;
}

BSTree destroyBSTree(BSTree bst){//销毁
    if(bst){//递归到一个没有左右结点的,free;
        destroyBSTree(bst->lchild);
        destroyBSTree(bst->rchild);
    }   
    free(bst);
    return NULL;
}
BSTree insert(BSTree bst, ElementType x){//插入数据
    if(!bst){//原树为空
        bst=(BSTNode*)malloc(sizeof(BSTNode));
        bst->data=x;
        bst->lchild=bst->rchild=NULL;
    }else
        if(bst->data<x) bst->rchild=insert(bst->rchild,x);
        else if(bst->data>x) bst->lchild=insert(bst->lchild,x);
    return bst;
}

BSTree deleteNode(BSTree bst, ElementType x){//删除结点
    BSTree tmp;
    if(!bst) return bst;
    else if(x>bst->data) bst->rchild=deleteNode(bst->rchild,x);
    else if(x<bst->data) bst->lchild=deleteNode(bst->lchild,x);
    else {//找到要删除的点
        if(bst->lchild && bst->rchild){
            tmp=findMin(bst->rchild);//在右子树中找最小的结点
            /*tmp=bst->rchild;
            while(tmp->lchild!=NULL){
                tmp=tmp->lchild;
            }*/
            bst->data=tmp->data;
            bst->rchild=deleteNode(bst->rchild,bst->data);
            //删除右子树结点中最小的元素
        }
        else{
            tmp=bst;
            if(!bst->lchild)//有一个右孩子或无孩子
                bst=bst->rchild;
            else if(!bst->rchild)//有左或无
                bst=bst->lchild;
            free(tmp);    
        }
    }
    return bst;
}
void inOrder(BSTree bst){
    if(bst){
        inOrder(bst->lchild);
        cout<<bst->data<<" ";
        inOrder(bst->rchild);
    }
}


int main()
{
    return 0;
}