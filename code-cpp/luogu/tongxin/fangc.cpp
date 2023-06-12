#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    float x=51539607552;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=365;j++){
            for(int k=0;k<1000;k++) x=x-1000;
        }
        if(i==1 || i==50 || i==100) printf("第%d年结束的余额：%.10f  21211835102+曾振铭\n",i,x);
    }
}