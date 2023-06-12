#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int i=0,j=1,sum=0,cnt=0,sheng,n;
	char str;
    cin>>n>>str;
	while(2*i*i-1<=n){
		i++;
	}
	i--;
	cnt=2*i-1;	
	sheng=n-2*i*i+1;
	while(cnt>0){
		for(i=0;i<sum;i++) cout<<" ";
		for(i=0;i<cnt;i++) cout<<str;
        cout<<endl;
		sum++;
		cnt=cnt-2;
	}
	sum--;
	cnt=cnt+2;
	while(sum>0){
		sum--;
		cnt=cnt+2;
		for(i=0;i<sum;i++) cout<<" ";
		for(i=0;i<cnt;i++) cout<<str;
        cout<<endl;
	}
    cout<<sheng<<endl;
	return 0;
}

