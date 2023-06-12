#include<stdio.h>
#include<math.h>
#include<time.h>
int b[1000]={0};
void cg(int i)
{
	int t=0;
	while(i>0){
        b[t] = i % 2; 
        t++;
        i = i/2;  
    }
}
void func(int f[],int n,int c)
{

	int u;
	int max=0;
	for(int i=0;i<pow(2,n);i++)
	{	
		int Sum=0;
		cg(i);
		for(int j=0;j<n;j++)
		{
			Sum+=b[j]*f[j];
		}
		if(Sum<=c && Sum>max){
			u=i;
			max=Sum;
		}	
	}
	printf("%d\n",max);
	cg(u);
	for(int i=0;i<n;i++)
		printf("%d ",b[i]);
	
	printf("\n");
}
int main()
{
	int n,l;
	scanf("%d %d",&n,&l);
	int f[10000];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
	}
    clock_t time1=clock();
	func(f,n,l);
	clock_t time2= clock();
	printf("n=%d    运行时间为：%.10lfms   21211835102+曾振铭\n",n,(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
	return 0;
}