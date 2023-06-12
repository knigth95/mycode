#include <bits/stdc++.h>
using namespace std;
int fun(int n){
    if(n<101) return 91;
    else return n-10;
}
int main(){
    int n;
    cin>>n;
    if(n==0) return 0;
    printf("f91(%d) = %d\n",n,fun(n));
    main();
}