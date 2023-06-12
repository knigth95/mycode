#include<bits/stdc++.h>
using namespace std;


int isprime(int n){
    int i;
    for(i=2;i<=sqrt(n);i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int main(){
    int m,n;
    cin>>m>>n;
    int sum[10000];
    sum[0]=2;
    int cnt=1;
    for(int i=3;i<10000;i++){
        int k=isprime(i);
        if(k==1){
            sum[cnt]=i;
            cnt++;
        } 
    }
    int j=1;
    for(int i=m-1;i<n;i++){
        if((i-m+1)%10==0) cout<<sum[i];
        else cout<<" "<<sum[i];
        if(j%10==0) cout<<endl;
        j++;
    }
    cout<<endl;
    return 0;
}