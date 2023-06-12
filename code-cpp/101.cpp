#include<bits/stdc++.h>
using namespace std;


int main(){
    float f=1.23456789e10;
    int i=1234567890;
    printf("%f %f\n %d %d\n",f,(float)(int)f,(int)(float)i,i);
    cout<<f<<" "<<(float)(int)f<<endl;
    cout<<i<<" "<<(int)(float)i<<endl;
    return 0;
}