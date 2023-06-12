#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;
void printfTree(BTree root);
int getNum(BTree root);
BTree create();
int getNum(BTree root){
	int cnt=0;
	if(root!=NULL){
		cnt++;
		cnt=cnt+getNum(root->lchild);
		cnt=cnt+getNum(root->rchild);
	}
	return cnt;
}

void printfTree(BTree root){
    if(root!=NULL){
        cout<<root->data<<"["<<getNum(root)<<"]";
        if(root->lchild!=NULL || root->rchild!=NULL){
            cout<<"(";
            printfTree(root->lchild);
            cout<<",";
            printfTree(root->rchild);
            cout<<")";
        }
    }
}

BTree create(){
	BTNode *root;
	char ch;
	ch=getchar();
	if(ch=='.')	return NULL;
	else{
		root=(BTNode *)malloc(sizeof(BTNode));
		root->data=ch;
		root->lchild=create();
		root->rchild=create();
		return root;
	}
}

int main(){
	BTNode *root;
	int cnt=0;
	root=create();
	printfTree(root);
	cout<<endl;
    return 0;
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
void printfTree(BTree root);
int getNum(BTree root);
BTree create();

int main()
{
	BTNode *root;
	int layer=0;
	root=create();
	printfTree(root);
	printf("\n");
    return 0;
}
void printfTree(BTree root)
{
	if(root!=NULL){
		printf("%c[%d]",root->data,getNum(root));
		if(root->lchild!=NULL || root->rchild!=NULL){
			printf("(");
			printfTree(root->lchild);
			printf(",");
			printfTree(root->rchild);
			printf(")");
		}
	}
} 
int getNum(BTree root)
{
	int k=0;
	if(root!=NULL){
		k++;
		k+=getNum(root->lchild);
		k+=getNum(root->rchild);
	}
	return k;
}

