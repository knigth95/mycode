#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node{
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
}BSTNode, *BSTree;

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

BSTree insert(BSTree tree,ElementType x){
    BSTree p;
    if(tree==NULL){
        p=(BSTNode*)malloc(sizeof(BSTNode));
        p->data=x;
        p->lchild=NULL;
        p->rchild=NULL;
        tree=p;
    }
    else if(x<tree->data) tree->lchild=insert(tree->lchild,x);
    else if(x>tree->data) tree->rchild=insert(tree->rchild,x);
    return  tree;
}

void output(BSTree tree){
    if(tree!=NULL){
        cout<<tree->data;
        if(tree->lchild!=NULL || tree->rchild!=NULL){
            cout<<"(";
            output(tree->lchild);
            cout<<",";
            output(tree->rchild);
            cout<<")";
        }
    }
}

void select(BSTree tree,int x){
    BSTree p;
    p=tree;
    while(p!=NULL){
        if(p->data==x) break;
        else if(p->data<x) p=p->rchild;
        else if(p->data>x) p=p->lchild;
    }
    if(p!=NULL) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

int main(){
	bool p;
    int n,x,k;
    BSTree tree;
    char data[2000000];
    gets(data);
    tree=createTree(data);
	cin>>n;
    /*while(n--){
        cin>>x;
        insert(tree,x);
    }
    output(tree);
    cout<<endl;*/
    while(n--){
        cin>>x;
        select(tree,x);
    }
    return 0;
}