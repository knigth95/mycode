#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}BTNode,*BTree;
BTree createTree(){
	BTree bt;
    char c;
	scanf("%c",&c);
	if(c=='.')
		return NULL;
	else{
		BTree p=(BTree )malloc(sizeof(BTNode));
		p->data=c;
		p->lchild=createTree();
		p->rchild=createTree();
		return p;
	}
}
void outPut(BTree rt,int depth){
	if(rt==NULL)
		return;
	outPut(rt->rchild,depth+1);
	for(int i=0;i<depth;i++)
		printf("-");
	printf("%c\n",rt->data);
	outPut(rt->lchild,depth+1);
}
int getNum(BTree rt){
	int cnt=0;
	if(rt!=NULL){
		cnt++;
		cnt=cnt+getNum(rt->lchild);
		cnt=cnt+getNum(rt->rchild);
	}
	return cnt;
}
void leafNode(BTree rt){
	if(rt!=NULL){
		if(rt->lchild==NULL && rt->rchild==NULL) cout<<rt->data;
		leafNode(rt->lchild);
		leafNode(rt->rchild);
	}
}

int getDepth(BTree rt){
	int l,r,high;
	if(rt!=NULL){
		l=getDepth(rt->lchild);
		r=getDepth(rt->rchild);
		high=l>r?l:r;//三目运算
		return high+1;
	}else return 0;
}
int getLeafNum(BTree rt){
	int cnt=0;
	if(rt!=NULL){
		if(rt->lchild==NULL && rt->rchild==NULL) cnt++;
		cnt=cnt+getLeafNum(rt->rchild);
		cnt=cnt+getLeafNum(rt->lchild);
	}
	return cnt;
}

int main(){
	BTree bt=createTree();
	outPut(bt,0);
	return 0;
}