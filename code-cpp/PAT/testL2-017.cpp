#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int m=n/2;
    //升序，按分类，偶数与奇数不影响结果
    int sum1=0,sum2=0;
    for(i=0;i<m;i++) sum1=sum1+a[i];
    for(;i<n;i++) sum2=sum2+a[i];
    printf("Outgoing #: %d\n",n-m);
    printf("Introverted #: %d\n",m);
    printf("Diff = %d\n",sum2-sum1);
    
    return 0;
}