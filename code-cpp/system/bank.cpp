#include <bits/stdc++.h>
using namespace std;
#define processNum 5  //五个进程
#define resourceNum 3 //三类资源
//关系：need[i,j]=max[i,j]-allocation[i,j]
int p;
int work[resourceNum];
int Request[resourceNum];
bool Finish[processNum];
int Available[resourceNum] ={3, 3, 3};
int Max[processNum][resourceNum] ;
int Need[processNum][resourceNum] ={7, 4, 3, 1, 2, 2, 6, 0, 0, 0, 1, 1, 4, 3, 1};
int Allocation[processNum][3]={0, 1, 0, 2, 0, 0, 3, 0, 2, 2, 1, 1, 0, 0, 2};

void feipei(int n,int j){
    Need[n-1][j]=Need[n-1][j]-Request[j];
    Available[j]=Available[j]-Request[j];
    Allocation[n-1][j]=Allocation[n-1][j]+Request[j];
}

void Input(){
    int i,j;
    cout<<"请输入最大需求矩阵max\n";
    for(i=0; i<processNum; i++)
    {
        for(j=0; j<resourceNum; j++)
        {
            cin>>Max[i][j];
        }
    }
    cout<<"请输入分配矩阵allocation\n";
    for(i=0; i<processNum; i++)
    {
        for(j=0; j<resourceNum; j++)
        {
            cin>>Allocation[i][j];
        }
    }
}

int compare(int m[],int n[]){
    for(int i=0;i<resourceNum;i++){
        if(m[i]<n[i]) return 0;
    }
    return 1;
}

void recycle(int p,int j){//回收资源
    
    Need[p-1][j] += Request[j];
    Available[j] -= Request[j];
    Allocation[p-1][j] += Request[j];
    
    //printf("系统分配资源没有改变\n");
}

int jicheng_safety(){//0安全，1不安全
    int i,j,k,f=0;
    int Finish[processNum];
    int work[resourceNum];
    for(i=0;i<processNum;i++){
        Finish[i] = 0;//为1即表示available满足第i进程的资源需要
    }
    for(i=0;i<resourceNum;i++){
        work[i]=Available[i];
    }
    cout<<"分配序列:"<<endl;
    cout<<"          Allocation           Need           Avilable"<<endl;
    for(k=0;k<processNum;k++){
        for(i=0;i<processNum;i++){
            if(Finish[i]==1) continue;
        
            else{
                if(compare(work,Need[i])){
                    Finish[i]=1;
                    cout<<endl<<"进程"<<i+1<<'\t';
                    f=1;
                    for(j=0;j<resourceNum;j++) printf(" %2d ",Allocation[i][j]);
                    cout<<"      ";
                    for(j=0;j<resourceNum;j++) printf(" %2d ",Need[i][j]);
                    cout<<"      ";
                    for(j=0;j<resourceNum; j++) printf(" %2d ",work[j]+Allocation[i][j]);
                    
                    cout<<endl;
                    for(j=0;j<resourceNum;j++) work[j]=work[j]+Allocation[i][j]; //释放资源
                    break;
                }
            }
            if(f==1) break;
        }
        
    }
    for(i=0; i<processNum; i++)
    {
        if(Finish[i]==0)
            return 1;//不存在安全序列
        
    }
    return 0;//存在安全序列
}

void jicheng_judge(int n){
    int j;
    if(compare(Available,Request) && compare(Need[n-1],Request)){
        for(j=0;j<resourceNum; j++){
            feipei(n,j);
        }
        if(jicheng_safety()) cout<<"允许"<<n<<"进程申请资源"<<endl;
        else{
            cout<<"不允许"<<n<<"进程申请资源"<<endl;
            for(j=0;j<resourceNum;j++){
                recycle(n,j);
            }
        }
    }
    else cout<<"申请资源量太多了"<<endl;
}

int main(){
    int n;
    Input();
    if(jicheng_safety()==1) cout<<"存在安全序列"<<endl;
    else cout<<"不存在安全序列"<<endl;
    cout<<"请输入发出请求向量Request的进程编号:";
    cin>>n;
    cout<<"请输入请求向量Request:";
    for(int i=0;i<resourceNum;i++) cin>>Request[i];
    jicheng_judge(n);
    return 0;
}

/*
请输入最大需求矩阵max
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
请输入分配矩阵allocation
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

*/