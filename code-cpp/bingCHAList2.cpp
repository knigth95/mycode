#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int find(int x){//查
	return a[x]==x?x:a[x]=find(a[x]);
} 
void merge(int x,int y){
	a[find(x)]=find(y);
}
int main(){
    int n;
    cin>>n;
	a.resize(n);//
    for(int i=0;i<n;++i){
    	a[i]=i;
	}	    
    int m;
    cin>>m;
	for(int i=0;i<m;++i){
    	int x,y;
        cin>>x>>y;
    	merge(x,y);
	}
    int k;cin>>k;
    for(int i=0;i<k;++i){
    	int x,y;
        cin>>x>>y;
    	x=find(x);
        y=find(y);
    	puts(x==y?"yes":"no");
	}
    return 0;
}