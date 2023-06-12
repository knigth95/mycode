#include<bits/stdc++.h>
using namespace std;
int main(){
    int dui[100][100];
    int n,m,k,x,y;
    cin>>n>>m;
    int i=0,j=0;
    while(m--){
        cin>>x>>y;
        if(find1(x,y)==1){
            dui[i][j]=x;
            dui[i][j+1]=y;
            j=j+2;
        }
        if(find1(x,y)==0){
            j=0;
            i=i+1;
            dui[i][j]=x;
            dui[i][j+1]=y;
            j=j+2;
        }
    }
}