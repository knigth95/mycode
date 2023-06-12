#include <bits/stdc++.h>
using namespace std;
int t; // 矩阵的阶
int p;
int a[100][100], r[100][100], m[100][100];


struct JuZhen{
    //int n;
    int x[100][100];
    JuZhen(int a=0){
        for (int i = 0; i < t; i++){
            for (int j = 0; j < t; j++){
                r[i][j] = (i == j ? a : 0); // r 是计算结果,初始化为单位矩阵
            }
        }
    }  
};
//JuZhen c,a,b;

JuZhen operator * (JuZhen a,JuZhen b){
    JuZhen c;
    //int t=a.n;
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++) {
            c.x[i][j] = 0;
            for (int k = 0; k < t; k++)
                c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % p;
        }
    }
    return c;
}
void JuZhenChengFa(int m1[][100], int m2[][100])
{
// 矩阵乘法运算 M1 × M2, 结果存回 M1
    int r[100][100];
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++) {
            r[i][j] = 0;
            for (int k = 0; k < t; k++)
                r[i][j] = (r[i][j] + m1[i][k] * m2[k][j]) % p;
        }
    }
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++){
            m1[i][j] = r[i][j];
        }
    }
}

int main()
{
    int n,cnt;
    cin >> t >> n >> p;
    cnt=n;
    clock_t time1=clock();
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++){
            r[i][j] = (i == j ? 1 : 0); // r 是计算结果,初始化为单位矩阵
        }
    }
    if (n > 0) {
        //m=a;/ 保存 a 的 2 整数次幂的幂 , 初值 m=a
        for (int i = 0; i < t; i++){
            for (int j = 0; j < t; j++){
                m[i][j] = a[i][j];
                
            }
        }
        while (n) {
            if (n & 1){
                //r=r*m;
                JuZhenChengFa(r, m);
            }
            n >>= 1;
            //m=m*m;
            JuZhenChengFa(m, m);
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) 
            cout << r[i][j] << ' ';
        cout << endl;
    }
    clock_t time2=clock();
    cout<<"指数n="<<cnt<<endl;
    printf("花费时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}