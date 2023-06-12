#include <stdio.h>
#include <time.h>
#include <numeric>
using namespace std;
int cap, n, a[40]; // D 型数据，cap 最大装载限量，n 物品数(0 开始)，a 物品重量
int maxLoad;       // T 型数据，最大装载量（问题所求）
int curLoad;       // C 型数据，当前装载量
int cr;
int x[40], bestx[40];
void dfs(int t)
{ // 接口：计算第 0~t-1 件物品已决策完毕、第 t 件物品取遍各种决策的最优结果
    if (t == n)
    { // 递归出口
        if (curLoad <= cap && curLoad > maxLoad)
        {
            maxLoad = curLoad; // 收集或更新结果数据(T 型)
            for (int i = 0; i < n; i++)
                bestx[i] = x[i];
        }
        return;
    }
    // a[t]不装
    cr -= a[t];
    x[t] = 0;
    if (curLoad + cr > maxLoad) // 剪枝
        dfs(t + 1);
    // a[t]装
    curLoad += a[t]; // 更新当前数据(C 型)
    x[t] = 1;
    if (curLoad <= cap) // 剪枝
        dfs(t + 1);
    curLoad -= a[t]; // 恢复当前数据(C 型)
    cr += a[t];
}
int main()
{
    clock_t time1, time2;
    scanf("%d%d", &n, &cap);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    maxLoad = -1; // T 型初始化
    curLoad = 0;  // C 型初始化
    cr = accumulate(a, a + n, 0);
    time1 = clock();
    dfs(0);
    time2 = clock();
    printf("%d\n", maxLoad);
    
    for (int i = 0; i < n; i++)
        printf("%d%c", bestx[i], i == n - 1 ? '\n' : ' ');
    
    printf("n=%d    运行时间为：%.10lfms   21211835102+曾振铭\n",n,(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}