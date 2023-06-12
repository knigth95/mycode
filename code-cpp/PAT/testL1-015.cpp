#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,cow;
    char str;
    cin>>n>>str;
    if(n<3 or n>21) return 0;
    if(n%2==0) cow=n/2;
    else cow=n/2+1;
    
    for(i=0;i<cow;i++){
        for(j=0;j<n;j++){
            cout<<str;
        }
        cout<<endl;
    }
    return 0;
}