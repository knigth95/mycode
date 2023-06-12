#include <bits/stdc++.h>
using namespace std;
int v,p,X[303];//乡村坐标

int getOnePost(int x,int y){
    //x-y间只设一个邮局的最小总距离
    int mid=(x+y)/2;//选中点
    int result=0;
    for(int i=x;i<=y;i++) result=result+abs(X[i]-X[mid]);
    return result;
}

int DP(){
    int dp[303][40];
    for(int i=1;i<=v;i++) dp[i][1]=getOnePost(1, i);
    //换方向
    for(int j=2;j<=p;j++){ //邮局数
        dp[j][j]=0;//村数等于邮局数
        for(int i=j+1;i<=v;i++){//村数
            dp[i][j]=0x7fffffff;
            for (int k=1;k<=i-j+1;k++) {
                int t=dp[i-k][j-1]+getOnePost(i-k+1,i);
                if(t<dp[i][j]) dp[i][j]=t;
            }
        }
    }
    return dp[v][p];    
}
int main(){
    cin>>v>>p;
    for(int i=1;i<=v;i++) cin>>X[i];
    clock_t time1=clock();
    cout<<DP()<<endl;
    clock_t time2=clock();
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
}