#include <bits/stdc++.h>
using namespace std;

struct person{
    char name[10];
    int num;
    int sign;
};

int juedui(int n){
    if(n<0) return -n;
    else return n;
}

int main(){
    int i,n,sum=0;
    cin>>n;
    struct person people[n+2],pre[n],k;
    for(i=0;i<n;i++){
        cin>>people[i].name>>people[i].num;
        sum=sum+people[i].num;
    }
    int average=sum/n/2;
    for(i=0;i<n;i++){
        pre[i].num=people[i].num-average;
        pre[i].num=juedui(pre[i].num);
        pre[i].sign=i;
    }
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(pre[j].num > pre[j+1].num){
                k=pre[j];
                pre[j]=pre[j+1];
                pre[j+1]=k;
            }
        }
    }
    printf("%d %s\n",average,people[pre[0].sign].name);
    return 0;
}