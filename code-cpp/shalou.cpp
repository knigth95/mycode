#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,row=0,cnt=0;
    char ch;
    cin>>n>>ch;
    n--;
    while(n>=2*(row+2)){
       n=n-2*(row+2);
       row=row+2;
    }
    int i=row;
    for(int j=1;j<row+1;j++){
        int m;
        for(m=0;m<=(row-i)/2;m++){
            cout<<" ";
        }
        int k;
        for(k=1;k<=i+1;k++){
            cout<<ch;
        }
        cout<<endl;
        j>row/2?(i=i+2):(i=i-2);

    }

    cout<<n<<endl;
    return 0;
}