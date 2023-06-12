#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

#define INF 0x7fffffff
int n;
int A[110][110];
int dist[110];
struct Node {
  int vi;
  int length;
  Node(int vi0 = 0, int len0 = 0) : vi(vi0), length(len0) {}
  bool operator<(const Node &b) const {
    return length > b.length;
    // length 越小越优先
  }
};

void bfs() {
  priority_queue<Node> Q;
  for (int i = 1; i <= n; i++)
    dist[i] = INF;
  dist[1] = 0;
  Q.push(Node(1, 0));
  do {
    Node E = Q.top();
    Q.pop();
    for (int j = 1; j <= n; j++) {
      if (j != E.vi && A[E.vi][j] != INF && E.length + A[E.vi][j] < dist[j]) {
        dist[j] = E.length + A[E.vi][j];
        Q.push(Node(j, dist[j]));
      }
    }
  } while (!Q.empty());
}

int main(){
    char s[10];
    cin>>n;
    clock_t time1=clock();
    for(int i=1;i<=n;i++) A[i][i]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            cin>>s;
            A[i][j]=A[j][i]=(s[0]=='x'?INF:atoi(s));
        }
    }
    bfs();
    clock_t time2=clock();
    cout<<"最短路径长的最大值："<<*max_element(dist+2,dist+n+1)<<endl;
    cout<<"源到各个点的最短路径长：";
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}
