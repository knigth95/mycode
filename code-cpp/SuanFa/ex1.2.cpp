#include <bits/stdc++.h>
using namespace std;
long long FeiDiGui(int n){
    long long a[100];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<n;i++){
        a[i]=0;//防随机值
        for(int j=0;j<i;j++){
            a[i]=a[i]+a[j]*a[n-1-i];
        }
    }
    return a[n];
}
int main(){
    int zzm1;
    while(cin>>zzm1){
        clock_t time1=clock();
        long long zzm2=FeiDiGui(zzm1);
        clock_t time2=clock();
        printf("花费时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    }
    return 0;
}