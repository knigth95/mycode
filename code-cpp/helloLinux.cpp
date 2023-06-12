#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
#define out(x) setw(4)<<setfill('0')<<x
#define fill(s) while(s.size()<4) s="0"+s
#define psqr(z) printf("The square of Z is %d.",(z*z))
int main()
{
    string a;
    int z;
    cin>>a;
    cin>>z;
    int ans=-1;
    for(;ans!=0&&ans!=6174;){
        fill(a);
        string b=a;
        sort(a.rbegin(),a.rend());
        sort(b.begin(),b.end());
        ans=stoi(a)-stoi(b);
        //cout<<psqr(z);
        //cout<<out(a);
        //cout<<"-"<<out(b);
        //cout<<"="<<out(ans);
        //cout<<endl;
        cout<<out(a)<<" - "<<out(b)<<" = "<<out(ans)<<endl;
        a=to_string(ans);
    }
    return 0;
}

