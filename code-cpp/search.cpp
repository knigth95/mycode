BSTree destroyBSTree(BSTree bst){
    if(bst!=NULL){
        free(bst);
        destroyBSTree(bst->rchild);
        destroyBSTree(bst->lchild);
    }
    return NULL;
}

BSTree destroyBSTree(BSTree bst)
{
	if(bst!=NULL){
		destroyBSTree(bst->lchild);
		destroyBSTree(bst->rchild);
		free(bst);
	}
	return NULL;
}

#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node{
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
}BSTNode, *BSTree;

BSTree destroyBSTree(BSTree bst);

int main()
{
    return 0;
}