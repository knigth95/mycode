#include <bits/stdc++.h>
using namespace std;
long long C(int n){
    if(n==0) return 1;
    long long sum(0);
    for(int i=0;i<n;i++) sum+=C(i)*C(n-1-i);
    return sum;
}
int main(){
    int zzm1;
    while(cin>>zzm1){
        clock_t time1=clock();
        long long zzm2=C(zzm1);
        clock_t time2=clock();
        cout<<zzm2<<endl;
        printf("花费时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
        //这个宏的单位为秒,要ms需要乘1000,除以这个宏可以跨平台使用
    }
}