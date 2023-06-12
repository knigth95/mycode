#include <bits/stdc++.h>
using namespace std;

struct shizi{
    int xi;
    int zhi;
};

int main(){
    int zhi,xi,cnt=0;
    while(scanf("%d %d",&xi,&zhi)!=EOF){
        if(zhi!=0){
            xi=zhi*xi;
            zhi--;
            if(cnt) cout<<" ";
            cout<<xi<<" "<<zhi;
            cnt++;
        }
    }
    if(cnt==0) cout<<"0 0";
    cout<<endl;
    return 0;
}