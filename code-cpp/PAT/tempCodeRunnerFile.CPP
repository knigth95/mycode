#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,i=0,j=0;
    char str;
    cin>>n>>str;
    int cnt=n;
    n--;//中间必为1
    while(n>=2*(i+2)){
        n=n-2*(i+2);
        i=i+2;
    }
    int ceng=i;
    int top=ceng/2+1;
    int sheng=cnt-2*top*top+1;
    for(i=0;i<top;i++){
        for(j=0;j<i;j++) cout<<" ";
        for(j=0;j<2*(top-i)-1;j++) cout<<str;
        cout<<endl;
    }

    for(i=0;i<top-1;i++){
        for(j=1;j<top-i-1;j++) cout<<" ";
        for(j=1;j<ceng;j++) cout<<str;
        ceng=ceng+2;
        cout<<endl;
    }
    if(sheng!=0) cout<<sheng<<endl;
    return 0;
}