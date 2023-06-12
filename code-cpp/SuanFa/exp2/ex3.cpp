#include <bits/stdc++.h>
using namespace std;
int DP(char a[],int b,int c){
    int len=b+c;

	if(c-b<0) return 1;
	else if(c-b==0)
	{
 		if(a[b]==48) return 0;
		else return 1;
	}
	else{
		int half=len/2;
		if(a[half]==48 ||a[half]>50 || (a[half]==50 && a[half+1]>54))
            return DP(a,b,half)*DP(a, half+1,b);
		else
            return DP(a, b,half)*DP(a,half+1,c)+DP(a,b,half-1)*DP(a,half+2, c);
	}
}


int main()
{
	char code[500];
	int i;
    while(cin>>code && code[0]!=48){
        clock_t time1=clock();
        i=0;
        while(code[i]>47 && code[i]<58 ) i++;
        cout<<"Alphacode种数为:"<<DP(code,0,--i)<<endl;
        clock_t time2=clock();
        printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    }
	
	return 0;
}