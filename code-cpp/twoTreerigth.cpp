#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}*BTree,BTNode;

BTree NewNode(char x){
	BTNode *p=(BTree)malloc(sizeof(BTNode));
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
int Find(char in[],int start,int end,char x){
	int i;
	for(int i=start;i<=end;i++)
		if(in[i]==x)
			return i;
	return -1;
}
BTree create(char pre[],int s1,int e1,char in[],int s2,int e2){
    int k;
    BTree root=NewNode(pre[s1]);
	k=Find(in,s2,e2,pre[s1]);
	if(k!=s2)
		root->lchild=create(pre,s1+1,s1+k-s2,in,s2,k-1);
	if(k!=e2)
		root->rchild=create(pre,s1+k-s2+1,e1,in,k+1,e2);
	return root;
}
void postOrder(BTree rt){
	if(rt==NULL) return;
	postOrder(rt->lchild);
	postOrder(rt->rchild);
	printf("%c",rt->data);
}


int main(){
	char zzm[100],kao[100];
    gets(zzm);
    gets(kao);
	int len1=strlen(zzm);
	int len2=strlen(kao);
	BTree rt=create(zzm,0,len1-1,kao,0,len2-1);
	postOrder(rt);
    cout<<endl;
}
