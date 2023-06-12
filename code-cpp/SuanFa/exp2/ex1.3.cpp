#include <bits/stdc++.h>
using namespace std;
int n,a[110][110],d[110][110];

int memoir(int i,int j){//备忘录方法
    if(d[i][j]>=0) return d[i][j];
    if(i==n) return d[i][j]=a[i][j];
    return d[i][j]=max(memoir(i+1,j),memoir(i+1,j+1))+a[i][j];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            d[i][j]=-1;
        }
    }
    clock_t time1=clock();
    memoir(1,1);
    clock_t time2=clock();
    cout<<d[1][1]<<endl;
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}