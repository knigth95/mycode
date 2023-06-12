#include <bits/stdc++.h>
using namespace std;
#define N 30
int n;
int a[N + 2][N + 2];
int minlen;
int minedge[N + 2];
int bestperm[N + 2];

struct Node
{
    int len;
    int perm[N + 2];
    int cl;
    int lbound;
    bool operator<(const Node &b) const
    {
        return cl + lbound > b.cl + b.lbound;
    } // 下界越小越优先
};

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void bfs()
{
    priority_queue<Node> q;
    Node cn;
    cn.len = 1;
    cn.cl = 0;
    cn.lbound = 0;
    for (int i = 1; i <= n; i++)
    {
        cn.perm[i] = i;
        cn.lbound += minedge[i];
    }
    q.push(cn);
    while (!q.empty())
    {
        cn = q.top();
        q.pop();
        Node nn = cn;
        nn.len = cn.len + 1;
        if (cn.len >= n)
        {
            if (cn.len > n)
                break;
            nn.cl = cn.cl + a[cn.perm[n]][1];
            nn.len++;
            nn.lbound = 0;
            q.push(nn);
            if (cn.cl + a[cn.perm[n]][1] < minlen)
            {
                minlen = cn.cl + a[cn.perm[n]][1];
                copy(cn.perm + 1, cn.perm + n + 1, bestperm + 1);
            }
            continue;
        }
        for (int i = cn.len + 1; i <= n; i++)
        {
            int k = cn.perm[i];
            swap(nn.perm[cn.len + 1], nn.perm[i]);
            nn.cl = cn.cl + a[cn.perm[cn.len]][k];
            nn.lbound -= minedge[k];
            q.push(nn);
            swap(nn.perm[cn.len + 1], nn.perm[i]);
            nn.lbound += minedge[k];
        }
    }
}

int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }
    clock_t time1=clock();
    for(int i=1;i<=n;i++){
        minedge[i]=0x7fffffff;
        for(int j=1;j<=n;j++){
            if(j!=i && a[i][j] < minedge[i])
                minedge[i]=a[i][j];
        }
    }
    minlen = 0x7fffffff;
    bfs();
    cout << minlen << endl;
    copy(bestperm+1, bestperm+n+1, ostream_iterator<int>(cout, " "));
    clock_t time2=clock();
    cout << endl;
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    
    return 0;
}