#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000

int d[2][NMAX + 2];
// d[i%2][j]:s1 的 i-前缀与 s2 的 j-前缀的编辑距离
char s1[NMAX + 2], s2[NMAX + 2];

int min(int a, int b, int c)
{
    int t = a;
    if (b < t)
        t = b;
    if (c < t)
        t = c;
    return t;
}
/*
int EditDistance(char *s1, char *s2)
{
    // 使用动态规划算法计算串 s1 与 s2 的编辑距离, s1, s2 从下标 0 开始存储字符串。
    int n1, n2;
    int i, j;
    n1 = strlen(s1);
    n2 = strlen(s2);
    for (j = 0; j <= n2; j++)
        d[0][j] = j;
    for (i = 1; i <= n1; i++)
    {
        d[i % 2][0] = i;
        for (j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                d[i % 2][j] = d[(i - 1) % 2][j - 1];
            else
                d[i % 2][j] = min(d[(i - 1) % 2][j], d[i % 2][j - 1], d[(i - 1) % 2][j - 1]) + 1;
        }
    }
    return d[n1 % 2][n2];
}
*/
int minDistance(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);

    if(m==0 || n==0){
        return (m > n) ? m : n;
    }
    int **dp = (int**)malloc(m*sizeof(int*));

    for(int i=0; i<m; ++i){
        dp[i] = (int*)malloc(n*sizeof(int));
    }

    // 初始化第0行
    for(int i=0; i<n; ++i){
        if(word1[0]==word2[i]){
            dp[0][i] = i;
        }else if(i==0){
            dp[0][0] = 1;
        }else{
            dp[0][i] = dp[0][i-1] + 1;
        }
    }

    // 初始化第0列
    for(int i=1; i<m; ++i){
        if(word1[i]==word2[0]){
            dp[i][0] = i;
        }else{
            dp[i][0] = dp[i-1][0] + 1;
        }
    }

    for(int i=1; i<m; ++i){
        for(int j=1; j<n; ++j){
            if(word1[i]==word2[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
        }
    }

    int res = dp[m-1][n-1];

    // free
    for(int i=0; i<m; ++i){
        if(dp[i]){
            free(dp[i]);
        }
    }
    if(dp){
        free(dp);
    }
    return res;
}




int main(){
    cin>>s1>>s2;
    clock_t time1=clock();
    cout<<minDistance(s1,s2)<<endl;
    //cout<<EditDistance(s1,s2)<<endl;
    clock_t time2=clock();
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}