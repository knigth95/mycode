#include <bits/stdc++.h>
using namespace std;

struct Program{//节目�?
    int ts,te;//开始与结束
    bool arange=0;//是否安排
};
bool operator<(Program a, Program b)//运算符重�?
{
    return a.te<b.te;
}

int main(){
    int n,c;
    Program p[100];
    do{
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>p[i].ts>>p[i].te;
        }
        clock_t time1=clock();
        sort(p,p+n);
        c=0;
        int j=0;
        for(int i=1;i<n;i++){
            if(i==1){//Ĭ�ϵ�һ��������
                c=1;
                p[i].arange=1;
            }
            if(p[i].ts>p[j].te){
                c++;
                p[i].arange=1;
                j=i;
            }
        }
        cout<<c<<endl;
        for(int i=1;i<=n;i++) cout<<p[i].arange<<" ";
        clock_t time2=clock();
        printf("����ʱ��Ϊ��%.10lfms   21211835102+������\n",(time2-time1));
    }while(1);
    return 0;
}