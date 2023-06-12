#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node{
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
}BSTNode, *BSTree;
#define N 2000000

BSTree createTree(char str[]);
BSTree insert(BSTree bst, ElementType x);
void output(BSTree root);

int main()
{
	bool p;
    int n,o,k,x,a;
    BSTree root;
    char data[N];
    gets(data);
    root=createTree(data);
	scanf("%d",&x);
	while(x--){
		scanf("%d",&a);
		insert(root,a); 
	}
	output(root);
	printf("\n");
    return 0;
}


BSTree createTree(char str[])
{
	BSTNode *s[100],*p;
	int k=0,i,top;
	int o;
	top=0;
	if(strlen(str)==1){
		p=(BSTNode*)malloc(sizeof(BSTNode));
		p->data=str[0]-'0';
		p->lchild=NULL;
		p->rchild=NULL;
		s[1]=p;
	}
	else{
		for(i=0;str[i]!='\0';i++){
			o=0;
			while(str[i]>='0'&&str[i]<='9'){
				o=o*10+str[i]-'0';
				i++;
			}
			if(o!=0){
				p=(BSTNode*)malloc(sizeof(BSTNode));
				p->data=o;
				p->lchild=NULL;
				p->rchild=NULL;	
					
					
				if(k==1){
					s[top]->lchild=p;
				}
				if(k==2){
					s[top]->rchild=p;
				}	
			}
			if(str[i]=='('){
				top++;
				s[top]=p;
				k=1;
			}
			else if(str[i]==','){
				k=2;
			}
			else if(str[i]==')'){
				top--;
			}	
		}		
	}	
	return s[1];
}

BSTree insert(BSTree bst, ElementType x){
	BSTNode *p;
	if(bst==NULL){
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->data=x;
		p->lchild=NULL;
		p->rchild=NULL;
		bst=p;
	}
	else if(x<bst->data){
		bst->lchild=insert(bst->lchild,x);
	}
	else if(x>bst->data){
		bst->rchild=insert(bst->rchild,x);
	}
	return bst;
}

void output(BSTree root){
	if(root!=NULL){
		printf("%d",root->data);
		if(root->lchild!=NULL || root->rchild!=NULL){
			printf("(");
			output(root->lchild);
			printf(",");
			output(root->rchild);
			printf(")");
		}
		
	}
}


bool isBST(BSTree root)
{
    if(root!=NULL){
    	if(!isBST(root->lchild)){
    		return false;
    	}
    	if(!isBST(root->rchild)){
    		return false;
    	}
    	if(root->lchild!=NULL && root->data<root->lchild->data){
    		return false;
    	}
    	if(root->rchild!=NULL && root->data>root->rchild->data){
    		return false;
    	}
    }
    return true;
}

void select(BSTNode *root,int x){
	BSTNode *p;
	p=root;
	while(p!=NULL){
		if(p->data==x){
			break;
		}
		else if(p->data<x){
			p=p->rchild;
		}
		else if(p->data>x){
			p=p->lchild;
		}
	}
	if(p!=NULL){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
}