#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int maxz[101][101];
int n;

int Max(int a, int b){
    return (a>b ? a : b);
}

int maxSum(){
    int i = 0;
    int j = 0;
    int max1, max2;
    for(i = n-1; i>=0; i--){
        for(j = 0; j<=i; j++){
            if(i == (n-1)){
                maxz[i][j]=a[i][j];
                continue;
            }
            max1 = maxz[i+1][j];
            max2 = maxz[i+1][j+1];
            maxz[i][j] = Max(max1, max2) + a[i][j];

        }
    }
    return maxz[0][0];    
}

int main(){
    int i = 0, j = 0;
    cin>>n;
    clock_t time1=clock();
    for(i = 0; i<n; i++){
        for(j = 0; j<=i; j++){
            cin >> a[i][j];
            maxz[i][j] = -1;
        }
    }

    cout << maxSum()<<endl;
    clock_t time2=clock();
    printf("n=%d    运行时间为：%.10lfms   21211835102+曾振铭\n",n,(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}
