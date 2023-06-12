#include<bits/stdc++.h>
using namespace std; 
int str[1000100],ptr[10001];
int after[10001];
//寻找子串在模板中的首次出现位置
int n,m;
void gtafter()
{
	int k=-1;
	int j=0;
	while(j<m)
	{
		if(k==-1||ptr[j]==ptr[k])
		{
			++j;++k;
			if(ptr[j]!=ptr[k])//优化after，使kmp更加快一点 
				after[j]=k;
			else after[j]=after[k];
		}
		else k=after[k];
	}
	return ;
}

int kmp()
{
	int i=0;int j=0;
	while(i<n&&j<m)
	{
		if(j==-1||str[i]==ptr[j])
		{
			i++;
			j++;
		}
		else j=after[j];
		if(j==m) return i-j+1;
	}
	return -1;
 } 

int main()
{
	int t;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=0; i<n; i++) cin>>str[i];
			
			for(int j=0; j<m; j++) cin>>ptr[j];
            clock_t time1=clock();
			after[0]=-1;
			gtafter();
			cout<<kmp()<<endl;
            clock_t time2=clock();
            printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
		}	
	}
 } 
