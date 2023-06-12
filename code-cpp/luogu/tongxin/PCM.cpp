#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#define N 7
int parCode[N]= {16,32,64,128,256,512,1024};//
int parInsideCode[N+1]= {1,1,2,4,8,16,32,64};
int parInsideSart[N+1]= {0,16,32,64,128,256,512,1024};
int flag=-1;
 
void parJudge(string &result,int testNum)
{
    int low=0,high=N,mid;
    for(int i=0; i<3; i++)
    {
        mid=(low+high) / 2;
        if(testNum>=parCode[mid])
        {
            result=result+'1';
            low=mid+1;
            flag=mid;
        }
        else
        {
            result=result+'0';
            high=mid-1;
            flag=mid-1;
        }
    }
}
 
void parInsideJudge(string &result,int testNum,int parStart,int parSpace)
{
    int low=0,high=17,mid=8;
    for(int i=0; i<4; i++)
    {
        int cost=parStart+parSpace*mid;
        if(cost>testNum)
        {
            result=result+'0';
            high=mid;
            mid=(low+high)/2;
        }
        else
        {
            result=result+'1';
            low=mid;
            mid=(low+high)/2;
        }
    }
}
 
int main()
{
    //freopen("Data.in", "r", stdin);
    //freopen("Data.out", "w", stdout);
    int testNum;
    while(cin>>testNum)
    {
 
        string result;
        cout<<"The signal sampling value: "<<testNum<<endl;;
        if(testNum<0)
            result=result+'0';
        else
            result=result+'1';
        testNum=fabs(testNum);//去符号
        parJudge(result,testNum);//判断段码
        //处理段内码
        int parSeq=flag+1;
        int parStart=parInsideSart[parSeq];
        int parSpace=parInsideCode[parSeq];
 
        parInsideJudge(result,testNum,parStart,parSpace);
        cout<<"The a law 13 line code: ";
        cout<<result<<endl;
        //量化误差
        int sum=0;
        int j;
        for(j=4; j<N+1; j++)
            if(result[j]=='1')
                sum=sum+pow(2,7-j);
        int errorNum=fabs((parStart+sum*parSpace+parSpace/2)-testNum);
        cout<<"The quantization error: "<<errorNum<<endl;
        cout<<endl;
    }
    return 0;
}