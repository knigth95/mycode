
BTree createTree(char s[])
{
	int k=0,i;
	BTNode *q[101], *p;
	int top=0;
	for(i=0; s[i]!='\0'; i++){
		if(isalpha(s[i])){
			p=(BTNode *)malloc(sizeof(BTNode));
			p->data=s[i];
			p->lchild=NULL;
			p->rchild=NULL;
			if(k==1){
				q[top]->lchild=p;
			}
			if(k==2){
				q[top]->rchild=p;
			}
		}
		else if(s[i]=='('){
			top++;
			q[top]=p;
			k=1;
		}
		else if(s[i]==','){
			k=2;
		}
		else if(s[i]==')'){
			top--;
		}
	}
	if(i==1){
		q[1]=p;
	}
	return q[1];
} 

void destroyTree(BTree bt){
	if(bt!=NULL){
		free(bt);
		destroyTree(bt->rchild);
		destroyTree(bt->lchild);
	}  
}

void printTree(BTree bt){//广义表输出
	if(bt!=NULL){
		printf("%c",bt->data);
		if(bt->rchild!=NULL || bt->lchild!=NULL){
			printf("(");
			printTree(bt->lchild);
			printf(",");
			printTree(bt->rchild);
			printf(")");
		}
	}
	
}

BTree createTree(char s[],int left,int right){//递归的创建
	int k=0,i;
	BTNode *q[101], *p;
	int top=0;
	for(i=left; i<=right; i++){
		if(isalpha(s[i])){//判断是否为英文字母
			p=(BTNode *)malloc(sizeof(BTNode));
			p->data=s[i];
			p->lchild=NULL;
			p->rchild=NULL;
			if(k==1){
				q[top]->lchild=p;
			}
			if(k==2){
				q[top]->rchild=p;
			}
		}
		else if(s[i]=='('){
			top++;
			q[top]=p;
			k=1;
		}
		else if(s[i]==','){
			k=2;
		}
		else if(s[i]==')'){
			top--;
		}
	}
	if(i==1){
		q[1]=p;
	}
	return q[1];
}

void layerOrder(BTree rt){
	queue<BTree>Q;//适配器
	BTNode *p;
	Q.push(rt);//根节点入队
	while(!Q.empty()){
		p=Q.front();
		Q.pop();
		printf("%c",p->data);
		if(p->lchild!=NULL){
			Q.push(p->lchild);
		}
		if(p->rchild!=NULL){
			Q.push(p->rchild);
		}
	}	
}


void visit(BTree root){
	printf("%c",root->data);
}

void postOrder(BTree root){//后序遍历
	if(root!=NULL){
		postOrder(root->lchild);
		postOrder(root->rchild);
		printf("%c",root->data);
	}
}

void preOrder(BTree root){//先序遍历
	if(root!=NULL){
		printf("%c",root->data);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

void inOrder(BTree root){//中序遍历
	if(root!=NULL){
		inOrder(root->lchild);
		printf("%c",root->data);
		inOrder(root->rchild);
	}
}

#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

BTree createTree(char s[]);

int main()
{
    return 0;
}