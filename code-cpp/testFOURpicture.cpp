#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
    int vertexNum,edgeNum;
    int visited[MAXVEX];//遍历标记. 1:已遍历  0:未遍历
}MGraph,*Graph;
//边结点
typedef struct ENode{
    int adjVertex;//该边所指的顶点的位置
    int weight;//边的权
    struct ENode *nextEdge;//指向下一条边的指针   
}ENode;

//顶点结点
typedef struct VNode{
    VertexType data;//顶点信息
    ENode *firstEdge;//指向第一条依附该顶点的边的弧指针
}VNode;

typedef struct
{
    VNode vexs[MAXVEX];
    int vertexNum,edgeNum; //点数和边数
}AdjGraph,*Graph;

Graph createGraph(){
    Graph g;
    g=(MGraph*)malloc(sizeof(MGraph));
    g->edgeNum=0;
    g->vertexNum=0;
    return g;
}


void BFS(Graph g, int i){
    queue<int>q;
    int cnt,k;
    g->visited[i]=1;
    q.push(i);
    while(!q.empty()){
        cnt=q.front();
        q.pop();
        for(int i=0;i<g->vertexNum;i++){
            if(g->edge[cnt][k]==1){
                if(g->visited[k]==0){
                    g->visited[k]=1;
                    q.push(k);
                }
            }
        }
    }
}
int locateVertex(Graph g,VertexType v){
    int i;
    for(i=0;i<g->vertexNum;i++){
        if(v==g->vexs[i]) return i;
    }
    return -1;
}
void addVertex(Graph g,VertexType v){
    int k=locateVertex(g,v);
    if(k!=-1) return ;
    int n=g->vertexNum;
    g->vexs[n]=v;//顶点插到最后
    g->vertexNum++;
    for(int i=0;i<g->vertexNum;i++){
        g->edge[i][n]=0;
        g->edge[n][i]=0;
    }
}
void addEdge(Graph g, VertexType x, VertexType y){
    int k1=locateVertex(g,x);
    int k2=locateVertex(g,y);
    if(k1!=-1 && k2!=-1){
        if(g->edge[k1][k2]==0){
            g->edge[k1][k2]=1;
            g->edge[k2][k1]=1;
            g->edgeNum++;
        }
    }
}
void delEdge(Graph g,VertexType x,VertexType y){
    int k1=locateVertex(g,x);
    int k2=locateVertex(g,y);
    if(k1!=-1 &&k2!=-1){
        if(g->edge[k1][k2]==1){
            g->edge[k1][k2]=0;
            g->edge[k2][k1]=0;
            g->edgeNum--;
        }
    }
}
void delVertex(Graph g,VertexType v){
    int k=locateVertex(g,v);
    int cnt=0,i,j;
    if(k!=-1){
        for(i=0;i<g->vertexNum;i++){
            if(g->edge[k][i]==1) cnt++;
        }
        for(i=k;i<g->vertexNum;i++){
            g->vexs[i]=g->vexs[i+1];
            for(j=0;j<g->vertexNum;j++) g->edge[i][j]=g->edge[i+1][j];
        }
        for(i=k;i<g->vertexNum;i++){
            for(j=0;j<g->vertexNum;j++) g->edge[j][i]=g->edge[j][i+1];   
        }
        g->vertexNum--;
        g->edgeNum=g->edgeNum-cnt;
    }
}
int degree(Graph g,VertexType v){
    int k=0,i,j,cnt=0;
    for(i=0;i<g->vertexNum;i++){//找到那个点
        if(g->vexs[i]==v){
            for(j=0;j<g->vertexNum;j++){
                if(g->edge[i][j]==1) cnt++;
            }
        }
    }
    return cnt;
}
void DFS(Graph g, int i){
    g->visited[i]=1;
    for(int j=0;j<g->vertexNum;j++)
        if(g->edge[i][j]==1)//如果存在链接点
            if(g->visited[j]==0) DFS(g,j);
}
void destroyGraph(Graph g){
    free(g);
}
int connect(Graph g, VertexType v, VertexType u){
    DFS(g,locateVertex(g,v));//依次寻找有边的未访问的结点
    return g->visited[locateVertex(g,u)];//v和u顶点所含是否连通
}
int connectedComps(Graph g){
    int n=0;
    for(int i=0;i<g->vertexNum;i++){
        if(g->visited[i]==0){//点未遍历
            DFS(g,i);//深度
            n++;//有一通图
        }
    }
    return n;
}
int findMin(Graph g,int D[],int fin[]){
    int k=-1;
    int min=INT_MAX;
    for(int i=0;i<g->vertexNum;i++){
        if(fin[i]!=1 && min>D[i]){
            min=D[i];
            k=i;
        }
    }
    return k;
}
int distance(Graph g,VertexType v, VertexType u){
    int i,k;
    int v1=locateVertex(g,v);
    int u1=locateVertex(g,u);
    int D[100];
    int fin[100],p[100];
    for(i=0;i<g->vertexNum;i++){
        D[i]=g->edge[v1][i];
        if(D[i]==0) D[i]=100;
        p[i]=i;
        if(D[i]!=0) p[i]=v1;
        fin[i]=0; 
    }
    fin[v1]=1;
    D[v1]=0;
    while(1){
        k=findMin(g,D,fin);
        if(k==-1){
            if(D[u1]<100) return D[u1];
            else return 0;
        }
        fin[k]=1;
        for(i=0;i<g->vertexNum;i++){
            if(g->edge[k][i]==0 || fin[i]==1) continue;
            if(D[i]>(D[k]+g->edge[k][i])){
                D[i]=D[k]+g->edge[k][i];
                p[i]=k;
            }
        }
    }
}

int Prim(Graph g, VertexType u)
{
	int lowcost[1001];
	int parent[1001];
	int k=locateVertex(g,u);
    for(int i=0;i<g->vertexNum;i++){
    	lowcost[i]=g->edge[k][i];
    	parent[i]=k;
    }
    lowcost[k]=0;
    parent[k]=-1;
    
    int sum=0;
    for(int i=1;i<g->vertexNum;i++){
        int a=-1;
    	int min=INT_MAX;
    	for(int j=0;j<g->vertexNum;j++){
	    	if(lowcost[j]!=0&&min>lowcost[j]){
	    		a=j;
	    		min=lowcost[j];
	    	}
	    }
	    if(a==-1){
    		return -1;
    	}
    	sum=sum+lowcost[a];
    	lowcost[a]=0;
    	for(int i=0;i<g->vertexNum;i++){
    		if(lowcost[i]!=0&&lowcost[i]>g->edge[a][i])
    	    lowcost[i]=g->edge[a][i];
    	    parent[i]=a;
        }
    	
    }
	return sum;
}
int Kruskal(Graph g)
{
	int count,sum,t,n,m;
	int parent[MAXVEX*MAXVEX];
	int begin[MAXVEX*MAXVEX];
	int end[MAXVEX*MAXVEX];
	int weight[MAXVEX*MAXVEX];
	int i=0,j=0;
	int num=0;
	while (i<g->vertexNum)
	{
		parent[i]=i;
		i=i+1;
	} 
	i=0;
	while (i<g->vertexNum)
	{
		j=0;
		while (j<g->vertexNum&&j<i)
		{
			if (g->edge[i][j]!=INT_MAX)
			{
				weight[num]=g->edge[i][j];
				begin[num]=j;
				end[num]=i;
				num=num+1;
			}
			j=j+1;
		}
		i=i+1;
	}
	i=0;
	while (i<num)
	{
		j=i+1;
		while (j<num)
		{
			if (weight[i]>weight[j])
			{
				t=weight[i];
				weight[i]=weight[j];
				weight[j]=t;
				t=begin[i];
				begin[i]=begin[j];
				begin[j]=t;
				t=end[i];
				end[i]=end[j];
				end[j]=t;
			}
			j=j+1;
		}
		i=i+1;
	}
	sum=0;
	count=0;
	i=0;
	while (i<num)
	{
		int b=begin[i];
		int e=end[i];
		while (parent[b]!=b)
		{
			b=parent[b];
		}
		n=b;
		while (parent[e]!=e)	e=parent[e];
		m=e;
		if (n!=m)
		{
			parent[n]=m;
			sum=sum+weight[i];
			count=count+1;
		}
		i=i+1;
	}
	if (count==g->vertexNum-1)	return sum;
	else	return -1;
} 

void Dijkstra(Graph g, int s, int D[], int P[]){
    int i,k,final[MAXVEX]={0};
    for(i=0;i<g->vertexNum;i++){
        D[i]=g->edge[s][i];
        P[i]=s;
    }
    final[s]=1;//集合s初始化为s
    D[s]=0;//到自己的距离设置成0
    while(1){
        int k=-1;
        int min=INT_MAX;
        for(i=0;i<g->vertexNum;i++){
            if(min>D[i] && final[i]==0){
                min=D[i];
                k=i;
            }
        }
        if(k==-1)  return;
        final[k]=1;//已经找到了到s的最终的最短距离
        for(i=0;i<g->vertexNum;i++){
            if(g->edge[k][i]<INT_MAX && final[i]==0){
                if(D[i]>(D[k]+g->edge[k][i])){ 
                    D[i]=D[k]+g->edge[k][i];
                    P[i]=k;
                }
            }        
        }
    }
}
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX])
{
    int i,k,j;
    int n=g->vertexNum;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            D[i][j]=g->edge[i][j];
            P[i][j]=i;
        }
    }
    for(k=0;k<n;k++){//k为将要插入的中间点
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){//千万不能用else判断情况
                if(D[i][k]==INT_MAX || D[k][j]==INT_MAX || i==j)
                    continue;
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++) D[i][i]=0;     
}
int findEdgeWeight(Graph g,int i,int j)
{
    ENode *p;
    p = findEdge(g,i,j);
    if(p == NULL)   return INT_MAX;
    else   return p->weight;
}
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX])
{
    int i,k,j;
    int n=g->vertexNum;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            D[i][j]=findEdgeWeight(g,i,j);
            P[i][j]=i;
        }
    }
    for(k=0;k<n;k++){//k为将要插入的中间点
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){//千万不能用else判断情况
                if(D[i][k]==INT_MAX || D[k][j]==INT_MAX || i==j)
                    continue;
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++) D[i][i]=0;     
}
void path(Graph g,int P[][MAXVEX],int i,int j){
    int k;
    cout<<g->vexs[i];
    k=P[i][j];
    while(k!=j){
        cout<<g->vexs[k];
        k=P[k][j];
    }
    cout<<g->vexs[j]<<endl;
}

int findMin(Graph g,int D[],int Final[])
{
    int k = -1;
    int i,min;
    min  = INT_MAX;
    for(i = 0;i < g->vertexNum;i++)
	{
        if(Final[i] != 1 && min > D[i])
		{
            min = D[i];
            k = i;
        }
    }
    return k;
}

void Dijkstra(Graph g, int s, int D[], int P[])
{
    int i,k;
    int Final[MAXVEX];
    for(i = 0;i < g->vertexNum;i++)
	{
        D[i] = findEdgeWeight(g,s,i);
        P[i] = s;//定义父节点
        Final[i] = 0;
    }
    //P[s] = -1;
    D[s] = 0;
    Final[s] = 1;//本身被访问过
    while(1)
	{
        k = findMin(g,D,Final);//找到一个与原节点距离最近的
        if(k == -1)//如果没找到返回
            return ;
        Final[k] = 1;//这个结点已经被访问了
        for(i = 0;i < g->vertexNum;i++)
		{
            if(findEdgeWeight(g,k,i) == INT_MAX || Final[i])  //如果说这个节点被访问过或者不与k节点连接
                continue;
            if(D[i] > D[k] + findEdgeWeight(g,k,i))
			{
                D[i] = D[k] + findEdgeWeight(g,k,i);
                P[i] = k;
            }
        }
    }
}


int main()
{
   
    return 0;
}