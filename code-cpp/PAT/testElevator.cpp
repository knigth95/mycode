#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,now=0,sum=0,i;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>i;
        if(i>now){
            sum=sum+(i-now)*6;
            now=i;
        }
        else{
            sum=sum+(now-i)*4;
            now=i;
        }
    }
    sum=sum+n*5;
    cout<<sum<<endl;
    return 0;
}