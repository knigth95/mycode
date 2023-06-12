#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k=sqrt(n);
    int i,sum=0,cnt=0;
    int num[k];
    int re=0,p,len;
    for(i=2;i<k+1;i++)
        if(n%i==0) num[cnt++]=i;
    if(cnt==0)
        cout<<'1'<<endl<<n<<endl;
    else if(cnt==1)
        cout<<'1'<<endl<<num[0]<<endl;
    else{
        
        for(i=0;i<cnt-1;i++){
            sum=num[i];
            len=1;
            for(int j=i;j<cnt-1;j++){
                if(num[j+1]-num[j] == 1 && n%(sum*num[j+1])==0){
                    sum=sum*num[j+1];
                    len++;
                }
                else break;
            }
            if(len>re){
                re=len;
                p=i;
            }
        }
        cout<<re<<endl;
        cout<<num[p];
        for(i=p+1;i<(p+re);i++)
            cout<<"*"<<num[i];
        cout<<endl;
    }
    return 0;
}