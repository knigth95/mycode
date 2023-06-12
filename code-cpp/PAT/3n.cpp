#include<bits/stdc++.h>
using namespace std;

bool jiou(int n){
    if(n%2==0) return true;
    return false;
}
int main(){
    int n,cnt=0;
    cin>>n;
    while(n!=1){
        if(jiou(n)){
            n=n/2;
            cnt++;
        }
        else{
            n=(3*n+1)/2;
            cnt++;
        } 
    }
    cout<<cnt<<endl;
    return 0;
}