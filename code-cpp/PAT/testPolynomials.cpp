#include <bits/stdc++.h>
using namespace std;

struct exp{
    double zhi;
    double xi;
    bool sign=1;
};

int main(){
    int m,n,i;
    struct exp shizi[30001],k_shizi;
    cin>>m;
    for(i=0;i<m;i++){
        scanf("%lf %lf",&shizi[i].zhi,&shizi[i].xi);
    }
    
    cin>>n;
    for(i=m;i<m+n;i++){
        scanf("%lf %lf",&shizi[i].zhi,&shizi[i].xi);
    }
    int cnt=m+n;
    for(i=0;i<m+n;i++){
        for(int j=i+1;j<m+n;j++){
            if(shizi[i].zhi == shizi[j].zhi){
                shizi[i].xi=shizi[i].xi+shizi[j].xi;
                cnt--;
                shizi[j].sign=-1;
            }
        }
    }
    for(i=0;i<cnt-1;++i){
        for(int j=0;j<cnt-i-1;++j){
            if(shizi[j].zhi<shizi[j+1].zhi){
                k_shizi=shizi[j];
                shizi[j]=shizi[j+1];
                shizi[j+1]=k_shizi;
            }
        }
    }
    cout<<cnt<<' ';
    for(i=0;i<cnt;i++){
        if(shizi[i].sign== 1 && i==0)
            printf("%.1lf %1lf",shizi[i].zhi,shizi[i].xi);
            
        else if(shizi[i].sign==1 && i!=0)
            printf(" %.1lf %.1lf",shizi[i].zhi,shizi[i].xi);
    }
    cout<<endl;
    return 0;
}