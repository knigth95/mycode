#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum[11]={0};
    char str[1001];
    cin>>str;
    int len=strlen(str),cnt,i;
    for(i=0;i<len;i++){
        cnt=str[i]-'0';
        sum[cnt]++;
    }
    for(i=0;i<=10;i++){
        if(sum[i]==0) continue;
        else printf("%d:%d\n",i,sum[i]);
    }
    return 0;
}