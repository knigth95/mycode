#include<bits/stdc++.h>
using namespace std;
int main(){
    int old,time;
    double sum;
    cin>>old>>time;
    if(time<40){
        if(old<5){
            sum=30*time;
        }else{
            sum=50*time;
        }
        printf("%.2lf",sum);
    }else{
        if(old<5){
            sum=30*40+1.5*30*(time-40);
        }else{
            sum=50*40+1.5*50*(time-40);
        }
        printf("%.2lf",sum);
    }
    return 0;
}