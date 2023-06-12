#include<bits/stdc++.h>
using namespace std;
#define  N 50
int n,a[N+2][N+2];
int bestn,bestx;

struct Node{
    int deep;
    int cn;
    char x[N+2];
    bool operator < (const Node &b) const {
        return cn+n-deep<b.cn-b.deep;
        //顶点数上限越大越优先
    }
    Node(int de0=0,int cn0=0):deep(de0),cn(cn0){}
};

void bfs(){
    priority_queue<Node> q;
    q.push(Node(0,0));
    while(!q.empty()){
        Node newn=q.top();
        q.pop();
        if(newn.deep==n){//叶节点
            if(newn.cn>bestn) bestn=newn.cn;
            break;
        }
        int i=newn.deep+1;
        bool OK=true;
        for(int j=1;j<i;j++){
            if(newn.x[j]==1 && a[i][j]==0){
                OK=false;
                break;
            }
        }
        Node newq=newn;
        newq.deep=newq.deep+1;
        if(OK){//当前点符合完全图条件
            newq.cn=newn.cn+1;
            newq.x[newq.deep]=1;
            q.push(newq);
            if(newq.cn>bestn) bestn=newq.cn;    
        }
        newq.cn=newn.cn;
        newq.x[newq.deep]=0;
        if(newq.cn+n-newn.deep>bestn)
            q.push(newq);
    }
}


int main(){
    do{
        cin>>n;
        if(n==0) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                 cin>>a[i][j];
        bestn=0;
        bfs();
        cout<<bestn<<endl;
        
    }while(1);
    return 0;
}

