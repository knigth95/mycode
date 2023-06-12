#include <bits/stdc++.h>
using namespace std;

struct Node{
    char name[10];
    char id[20];
    int gra;
};

int main(){
    int n,i,max,min;
    cin>>n;
    struct Node student[n];
    for(i=0;i<n;i++){
        cin>>student[i].name>>student[i].id>>student[i].gra;
    }
    max=student[0].gra;
    min=student[0].gra;
    for(i=0;i<n;i++){
        if(student[i].gra >= max)
            max=student[i].gra;
        if(student[i].gra <= min)
            min=student[i].gra;
    }
    for(i=0;i<n;i++){
        if(student[i].gra==max )
            cout<<student[i].name<<" "<<student[i].id<<endl;
    }
    for(i=0;i<n;i++){
        if(student[i].gra==min )
            cout<<student[i].name<<" "<<student[i].id<<endl;
    }
    return 0;
}