#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    cin>>a>>b;
    long long c=a+b;
    string str=to_string(c);
    int cnt=1,k=0;
    
    for(int i=str.length();i>0;i--){
        cnt++;
        if(cnt%3==0 && i!=str.length()){
            str.insert(i+1,",");//双引和单引还不一样
        }
        
    }
    for(int i=0;i<str.length()-1;i++){
        cout<<str[i];
    }
    
    cout<<endl;
}