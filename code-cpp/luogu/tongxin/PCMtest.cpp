#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    char str[9];
    cin>>n;
    if(n>0){
        str[0]=1;
    }else if(n<0){
        str[0]=0;
    }
    if(0<=n<16){
        str[1]=0;
        str[2]=0;
        str[3]=0;
    }else if(16<=n<32){
        str[1]=0;
        str[2]=0;
        str[3]=1;
    }
    for(int i=0;i<4;i++) cout<<str[i];
    return 0;
}