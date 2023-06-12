#include <bits/stdc++.h>
using namespace std;

struct student{
    char id[30];
    int dei;
    int cai;
    bool sign=1;
};

int main(){
    int N,L,H,i;
    cin>>N>>L>>H;
    struct student students1[10000],students[20000],k_stu,stu[20000];
    for(i=0;i<N;i++){
        cin>>students1[i].id>>students1[i].dei>>students1[i].cai;
    }
    
    int cnt=0;
    for(i=0;i<N;i++){
        if(L<= students1[i].dei && L<= students1[i].cai){
            students[cnt++]=students1[i];
        }
    }
    //第一类
    int cnt0=0;
    for(i=0;i<cnt;i++){
        if(students[i].dei>=H && students[i].cai>=H && students[i].sign==1){
            students[i].sign=0;
            stu[cnt0++]=students[i];
        }
    }
    int cnt1=cnt0;
    for(i=0;i<cnt0-1;++i){
        for(int j=0;j<cnt0-i-1;++j){
            if((stu[j].dei+stu[j].cai) < (stu[j+1].dei+stu[j+1].cai) ){
                k_stu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=k_stu;
            }
        }
    }
    //第二类
    for(i=0;i<cnt;i++){
        if(students[i].dei>=H && students[i].cai<H &&students[i].sign==1){
            students[i].sign=0;
            stu[cnt1++]=students[i];
        }
    }
    int cnt2=cnt1;
    for(i=cnt0;i<cnt1-1;++i){
        for(int j=cnt0;j<cnt1-i-1;++j){
            if((stu[j].dei+stu[j].cai) < (stu[j+1].dei+stu[j+1].cai) ){
                k_stu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=k_stu;
            }
        }
    }
    //第三类
    for(i=0;i<cnt;i++){
        if(students[i].dei < H && students[i].cai<H && students[i].sign==1 && students[i].dei> students[i].cai){
            students[i].sign=0;
            stu[cnt2++]=students[i];
        }
    }
    int cnt3=cnt2;
    for(i=cnt1;i<cnt2-1;++i){
        for(int j=cnt1;j<cnt2-i-1;++j){
            if((stu[j].dei+stu[j].cai) < (stu[j+1].dei+stu[j+1].cai)){
                k_stu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=k_stu;
            }
        }
    }

    //第四类
    for(i=0;i<cnt;i++){
        if(students[i].sign==1){
            students[i].sign=0;
            stu[cnt3]=students[i];
            cnt3++;
        }
    }
    for(i=cnt2;i<cnt3-1;++i){
        for(int j=cnt2;j<cnt3-i-1;++j){
            if((stu[j].dei+stu[j].cai) < (stu[j+1].dei+stu[j+1].cai)){
                k_stu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=k_stu;
            }
        }
    }
    cout<<cnt<<endl;
    for(i=0;i<cnt;i++){
        cout<<stu[i].id<<" "<<stu[i].dei<<" "<<stu[i].cai<<endl;
    }
    
}