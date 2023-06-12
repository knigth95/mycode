#include <bits/stdc++.h>
using namespace std;
int fun(int x,int y){
    if(x<=0) return 0;
    if(x==1) return y;
    return fun(x-1,y)+y+fun(x-2,y);
}
int main()
{
    int y;
    cin>>y;
    //cout<<fun(5,y)<<endl;
    cout<<fun(8,y)<<endl;
    
}