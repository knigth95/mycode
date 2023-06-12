#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c=(a-a%100)/100;
    int d=(b-b%100)/100;
    int time1=d-c;
    int time2=0;
    if(b%100-a%100<0){
        time2=60-a%100+b%100;
        time1-=1;
    }else time2=b%100-a%100;
        printf("%02d:%02d",time1,time2);
        //不可直接用字符0替代小于10的小时数
    return 0;
}