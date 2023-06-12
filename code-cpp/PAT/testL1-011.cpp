#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    int i,j;
    getline(cin,a);
    getline(cin,b);
    int len_a=a.length();
    int len_b=b.length();
    for(i=0;i<len_a;i++){
        for(j=0;j<len_b;j++){
            if(a[i]==b[j]) a[i]='1';
        }
    }
    for(i=0;i<len_a;i++){
        if(a[i]!='1') cout<<a[i];
    }
    cout<<endl;
    return 0;
}