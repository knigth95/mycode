#include <iostream>
#include <cstdio>
using namespace std;
#define MAXSIZE 99
int n;								//第一行符号个数
int a[MAXSIZE][MAXSIZE];	//符号三角形矩阵，矩阵最左侧一列不用
int count;							//满足条件的符号三角形个数
int half;							//符号总数的一半
int amount;							//符号总数

int Count(int k, int count)
{
	//printf("sign[%d] %d ", k, signTriangle[0][k]);
	int i, j;
	for (i=0,j=k;i<k;i++,j--)
	{
		count =count+a[i][j];
		if (a[i][j-1] == a[i][j])
		{
			a[i+1][j-1] = 1;
		}
		else
		{
			a[i+1][j-1] = 0;
		}
	}
	//printf("number of plus signs: %d\n", count);
	return count;
}

void Backtrack(int k, int plusSigns)
{
	if (k > n)
	{
		count++;
		//printf("%d %d\n", plusSigns, count);
	}
	else
	{
		int i;
		for (i=0; i<2; i++) //i为0代表减号，为1代表加号
		{
			a[0][k] = i;
			//统计新增最右侧一条边后，加号的数量
			int temp = Count(k, plusSigns);
			//加号和减号的数量均不能超过总符号数的一半
			if (temp <= half && (k*(k+1))/2 - temp <= half)
			{
				Backtrack(k+1, temp);
			}
		}
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		count = 0;
		clock_t time1=clock();
        amount = n*(n+1) / 2;
		//printf("amount: %d\n", amount);
		if (amount % 2 == 0)
		{
			half = amount / 2;
			Backtrack(1, 0);
		}
		printf("%d\n", count);
        clock_t time2=clock();
        printf("n=%d  运行时间为：%.10lfms   21211835102+曾振铭\n",n,(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
	}
	return 0;
}