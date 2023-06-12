#include <bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct CSNode
{
    ElementType data;
    struct CSNode * child;
    struct CSNode * sibling;
}CSTNode,*CSTree;

CSTree createTree(char *str){
    CSTree s[101],p,q;
    int k=0,top=-1;//k是标记
    for(int i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            p=(CSTNode*)malloc(sizeof(CSTNode));
            p->data=str[i];
            p->child=NULL;
            p->sibling=NULL;
            
            if(k==0) s[0]=p;
            else if(k==1) s[top]->child=p;
            else if(k==2){ 
                q=s[top]->child;
                while(q->sibling!=NULL) q=q->sibling;
                q->sibling=p;
           }          
        }
        else{
            if(str[i]=='('){
                s[++top]=p;
                k=1;
            }
            if(str[i]==',') k=2;
            if(str[i]==')') top--;
        } 
    }
    return s[0];
}

int main()
{
    
    return 0;
}
CSTree createTree(){
    char str[101],ch;
    scanf("%c",&ch);
    getchar();
    CSTree root=(CSTNode*)malloc(sizeof(CSTNode));
    root->data=ch;
    root->child=NULL;
    root->sibling=NULL;
    CSTree p,s,r;
    queue<CSTree>q;
    q.push(root);
    while(!q.empty()){
        s=q.front();
        q.pop();
        gets(str);
        if(str[0]=='#') continue;
        
        p=(CSTNode*)malloc(sizeof(CSTNode));
        p->data=str[0];
        p->child=NULL;
        p->sibling=NULL;
        q.push(p);
        s->child=p;
        
        //记住转移孩子树时一定要压入数据
        for(int i=1;str[i]!='#';i++){
            p=(CSTNode*)malloc(sizeof(CSTNode));
            p->data=str[i];
            p->child=NULL;
            p->sibling=NULL;
            q.push(p);//入
            //记得转移孩子树前要先压入数据
            r=s->child;
            while(r->sibling!=NULL) r=r->sibling;
            r->sibling=p;
        }
    }
    return root;
}