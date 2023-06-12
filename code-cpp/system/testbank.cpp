#include<stdio.h> 
#include <cstdlib>

int Max[100][100] ={0};//最大需求矩阵 
int Allocation[100][100]={0};//已分配矩阵 
int Need[100][100]={0};//需求矩阵 
int Available[100]={0}; //资源可用情况 
char Name[100]={0};//资源名称
int Work[100]={0};//记录系统中当前各类可用资源的数目 
int Request[100]={0};//系统对各类资源请求的数目 
int Security[100]={0};//保存进程在安全情况下的执行顺序 
int M;//系统中进程的数量
int N;//资源类型的数量 

void init()
{
	int i=0,j=0;
	printf("请输入可用资源的种类数量：");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("请输入第 %d 个可用资源的名称: ",i);
		scanf("%s",&Name[i]);
		printf("请输入初始可用资源 %c 的数量: ",Name[i]);
		scanf("%d",&Available[i]);
	}
	printf("\n");
	printf("请输入进程的数量：");
	scanf("%d",&M);
	printf("请输入进程的Max矩阵：\n");
	for(i=0;i<M;i++){//遍历每一个进程 
		for(j=0;j<N;j++){//输入第i个进程中每种资源的数量 
			scanf("%d",&Max[i][j]);
		}
	}
	printf("请输入进程的Allocation矩阵：\n");
	int temp[100]={0};//为了算新的Available 
	for(i=0;i<M;i++){//遍历每一个进程 
		for(j=0;j<N;j++){//输入第i个进程中每种资源的数量 
			scanf("%d",&Allocation[i][j]);
			//第一个进程需要j类资源的数量：最大需求量-已经分配的 
			Need[i][j]=Max[i][j]-Allocation[i][j];
			temp[j]+=Allocation[i][j]; //统计已经分配的资源量 
		}
	}
	for(j=0;j<N;j++)//更新可用资源数目Available
	{
		Available[j]=Available[j]-temp[j];
	} 
}

void show(){//功能：进行资源及进程相关信息显示
	printf("\t--------------------\n");
	printf("\t系统当前可用的资源矩阵Available：\n");
	int i;
	for(i=0;i<N;i++){
		printf("%c ",Name[i]);
	} 
	printf("\n");
	for(i=0;i<N;i++)
		printf("%d ",Available[i]);
	printf("\n");
	printf("\t系统当前资源分配情况如下： \n");
	printf("\t  Max     Allocation      Need\n");
	printf("进程名  ");
	int j=0;
	for(j=0;j<3;j++)//每个进程名要输出三次
	{
		for(i=0;i<N;i++){//遍历所有的资源名称 
			printf("%c    ",Name[i]);
		}
	 } 
	 printf("\n");
	 for(i=0;i<M;i++){//打印进程
	 	printf("P%d      ",i);
	 	for(j=0;j<N;j++){
	 		printf("%d    ",Max[i][j]);
		 }
		 for(j=0;j<N;j++){
	 		printf("%d    ",Allocation[i][j]);
		 }
		 for(j=0;j<N;j++){
	 		printf("%d    ",Need[i][j]);
		 }
		 printf("\n");
	 }	
}

int safe()
{
	int Finish[100]={0};//Finish：系统是否有足够的资源分配给进程，使之完成运行 
	// 开始时先令Finish[i]=0,当有祖国资源分配给进程时，再令Finish[i]=1 
	int i=0;
	for(i=0;i<N;i++)
	{
		Work[i]=Available[i];//在执行安全算法开始时，Work=Available 
	}
	int j=0,count=0,k=0,m=0;
	for(i=0;i<M;i++)
	{	
		count=0;//遍历完一个进程就将count置为0，对新的i号进程资源达标数进行计数 
		for(j=0;j<N;j++){
			//Finish[i]=0表示未执行 
			if(Finish[i]==0&&Need[i][j]<=Work[j])
			{//如果进程没有执行且资源需求条件满足 
				count++;//统计有多少种资源满足条件 
				if(count==N) //表示对于i号进程所有资源都满足 
				{
					Finish[i]=1;//记录i号进程为可执行 
					for(k=0;k<N;k++)
					{
						Work[k]=Work[k]+Allocation[i][k];
					}
					Security[m]=i;//记录第m个执行的是i号进程
					i=-1;//将i置为-1;通过for循环执行i++后变为0，从第一个进程重新开始找 
					m++;
				} 
			} 
		}
	}
	for(i=0;i<M;i++)
	{
		if(Finish[i]==0)
		{
			printf("系统不安全\n");
			return -1;
		}
	 } 
	 printf("系统时安全的\n");
	 for(i=0;i<M;i++)
	 {
	 	printf("P%d",Security[i]);
	 	if(i<M-1)
	 		printf("-->");
	 }
	printf("\n");
	return 0;
}
bool bank()
{
	printf("请输入希望手动分配资源的进程的编号：");
	int Id,j;
	bool flag=true;
	while(scanf("%d",&Id))
	{
		if(Id < 0 || Id > M-1)
			printf("进程不存在!请重新输入\n请输入希望手动分配资源的进程的编号：");
		else break;
	}
	printf("请输入请求资源数(%d个)：\n",N);
	for(j=0;j<N;j++)
	{
		scanf("%d",&Request[j]);
	}
	printf("开始为进程P%d分配资源：\n",Id);
	
	for(j=0;j<N;j++)
	{
		if(Request[j]>Need[Id][j]){
			printf("进程请求资源数大于所需资源数，无法分配!\n");
			flag=false;
			break;			
		}
		else if(Request[j]>Available[j]){
			printf("进程请求资源数大于可用资源数，无法分配!\n");
			flag=false;
			break;
		}
		else{
			Available[j] -= Request[j];
	        Allocation[Id][j] += Request[j];
	        Need[Id][j] -= Request[j];
		}
		
	}	
	return flag; 
}
int main()
{
	
	init();	
	show();
	safe();
	char choice;
	while(true){
	
		printf("请选择资源分配还是退出");
		scanf("%s",&choice); 
		if(choice=='R'||choice=='r')
		{
			if(bank()){
				safe();	
				show(); 
				//exit(0);
			}else{//说明没有分配资源，不必退出程序。 
				show();
			}				
		}
		else if(choice=='E'||choice=='e')
		{
			exit(0);
		}
		else
			printf("请正确选择"); 
		
	}
	return 0;	
} 
