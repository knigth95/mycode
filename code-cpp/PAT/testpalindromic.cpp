#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,a[100],i=0;
    cin>>n>>k;
    while(n){
        a[i]=n%k;
        n=n/k;
        i++;
    }
    if(i==0){
        cout<<"Yes"<<endl;
        cout<<"0";
        return 0;
    }
    int sign=0;
    for(int j=0;j<i/2;j++){
        if(a[j]!=a[i-j-1])  sign=1;
        break;
    }
    if(sign==1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    for(int j=i-1;j>=0;j--){
        if(j==0) cout<<a[j];
        else cout<<a[j]<<" ";
    }
    
    cout<<endl;
    return 0;
}