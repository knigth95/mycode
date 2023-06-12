#include<bits/stdc++.h>
using namespace std;

 
int main(){
	int n,i;
	cin>>n;
	long long id[n];  
	int jikao[n][2];
	
	for(i=0; i<n; i++)
		cin>>id[i]>>jikao[i][0]>>jikao[i][1];
	 
	int k; 
    cin>>k;
	int num;
	for(i=0; i<k; i++){
		cin>>num;
		for(int j=0; j<n; j++){
			if(num==jikao[j][0]){
				cout<<id[j]<<" "<<jikao[j][1]<<endl;
				break; 
			}
		}
	}
	return 0;
}