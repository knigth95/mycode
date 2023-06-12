#include<bits/stdc++.h>
using namespace std;
#include<queue>
priority_queue<int,vector<int>,greater<int> > q;
int main(){
    
    int n,v,w,i;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v>>w;
        q.push(w);
    }
    int x,y,sum=0;
    for(i=1;i<n;i++){
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        sum=sum+x+y;
        q.push(x+y);
    }
    cout<<sum<<endl;
    return 0;
}