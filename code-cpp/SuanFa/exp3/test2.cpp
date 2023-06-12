#include <bits/stdc++.h>
using namespace std;
void Dijkstra(int n,int v,int d[],int p[],int c[][100]){
    bool s[100];
    int i,j;
    for(i=1;i<=n;i++){
        d[i]=c[v][i];
        s[i]=0;
        if(d[i]==999999) p[i]=0;
        else p[i]=v;
    }
    d[v]=0;
    s[v]=1;
    for(i=1;i<=n;i++){
        int temp=999999;
        int u=v;
        for(j=1;j<=n;j++){
            if(!s[j] && d[j]<temp){
                u=j;
                temp=d[j];
            }
        }
        s[u]=1;
        for(j=1;j<=n;j++){
            if(!s[j] && c[u][j]<999999){
                int d1=d[u]+c[u][j];
                if(d1<d[j]){
                    d[j]=d1;
                    p[j]=u;
                }
            }
        }
    }
}

int main(){
    int n,j,i;
    int d[100],p[100],c[100][100];
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]==-1) c[i][j]=999999;
        }
    }
    clock_t time1=clock();
    int v=1;
    Dijkstra(n,v,d,p,c);
    clock_t time2=clock();
    for(i=1;i<=n;i++) cout<<d[i]<<" ";
    cout<<endl;
    cout<<"1"<<endl;
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(time2-time1));
    stack<int>q;
    int ver=v;
    for(i=2;i<=n;i++){
        if(d[i]!=0 && d[i]!=999999){
            v=i;
            q.push(v);
            do{
                v=p[v];
                q.push(v);
            }while(v!=ver);
            while(!q.empty()){
                cout<<q.top()<<" ";
                q.pop();
            }
            cout<<endl;
        }
        clock_t time3=clock();
        printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(time2-time1));
    }
    return 0;
}