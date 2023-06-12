#include <bits/stdc++.h>
using namespace std;

int main(){
    char num[22];
    int book[22]={0};
    cin>>num;
    int len=strlen(num);
    int cnt=0;
    for(int i=len-1; i>=0; --i){
        
        int k=num[i]-'0';
        book[k]++;
        k=k*2+cnt;//加倍
        num[i]=k%10+'0';
        cnt=k/10;
        //统计数字出现几次
        book[num[i]-'0']--;
    }
    int sign=0;
    for(int i=0;i<10;++i){
        if(book[i]!=0){
            sign=1;
            break;
        }
    }
    //高位进位
    if(cnt || sign) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    if(cnt) cout<<cnt;
    cout<<num<<endl;
    return 0;
}