#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i=0,cnt=0;
    cin>>n;
    getchar();
    char str[10001],ch;
    while(scanf("%c",&ch) && ch!='\n'){
        str[cnt++]=ch;
    }
    
    int h=cnt/n;
    if(cnt%n !=0){
        h++;
        for(i=cnt;i<n*h;i++) str[i]=' ';
    }
    for(i=0;i<n;i++){
        for(int j=n*h-n+i;j>=0;){
            cout<<str[j];
            j=j-n;
        }
        cout<<endl;
    }
    return 0;
}