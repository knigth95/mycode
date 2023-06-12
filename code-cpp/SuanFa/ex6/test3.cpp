#include <bits/stdc++.h>
using namespace std;

bool judge(int n){
    double cnt=sqrt(n);
    for(int i=2; i<cnt; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    long long n;
    while(cin>>n){
        clock_t time1=clock();
        if(judge(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        clock_t time2=clock();
        printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    }
    return 0;
}