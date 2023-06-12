#include <bits/stdc++.h>
#include <ctime>

using namespace std;
typedef long long LL;
const int maxn=3000+5;
const int mod = 1e9+7;
LL a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
LL res1[maxn],res2[maxn],r1[maxn],r2[maxn],resL,resR;

int main()
{
    srand(unsigned(time(NULL)));
    //freopen("input.in","r",stdin);
    int n;
    while(scanf("%d",&n)==1) {
        clock_t time1=clock();
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%lld",&a[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%lld",&b[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%lld",&c[i][j]);

        bool door=true;
        for(int z =0;z<5;z++)
        {
            memset(res1,0,sizeof(res1));
            memset(res2,0,sizeof(res2));
            for(int i=0;i<n;i++)
            {
                r1[i] = rand();
                r2[i] = rand();
            }
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    res1[i]+=(r1[j]*a[j][i])%mod;
                    res2[i]+=(b[i][j]*r2[j])%mod;
                    res1[i]%=mod;
                    res2[i]%=mod;
                }

            resL=resR=0;
            for(int i=0;i<n;i++)
                resL=(resL+(res1[i]*res2[i])%mod)%mod;

            memset(res1,0,sizeof(res1));
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    res1[i]=(res1[i]+(r1[j]*c[j][i])%mod)%mod;


            for(int i=0;i<n;i++)
                resR=(resR+(res1[i]*r2[i])%mod)%mod;
            if(resL!=resR){
                door=false;
                break;
            }
        }
        if(door)
            printf("YES\n");
        else
            printf("NO\n");
        clock_t time2=clock();
        printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    }
    return 0;
}


