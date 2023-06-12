#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,n,k=0,z;
    cin>>n;
    int a[n+2];
    while(n--){
        cin>>z;
        //a[k]=z;
        if(k==0 ||  a[k-1] < z)
            a[k++]=z;
        else{
            int r=k-1,l=0,mid;
            while(l <= r){
                mid=(r-l)/2+l;
                if(a[mid]>z) r=mid-1; 
                else l=mid+1;
            }
            a[l]=z;
        }
    }
    cout<<k<<endl;
    return 0;
}