#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    //三重枚举
    int a,b,c,sum=0;
    for(a=n;a<n+4;a++){
        for(b=n;b<n+4;b++){
            for(c=n;c<n+4;c++){
                if(a!=b && a!=c && b!=c){
                    cout<<a<<b<<c;
                    sum++;//控制格式
                    if(sum%6==0) cout<<endl;
                    else cout<<" ";
                }
            }
        }
    }
    return 0;
}