#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 1000 //最大顶点数
typedef char VertexType;

typedef struct ENode
{
    int adjVertex;  //该边所指的顶点编号
    int weight;     //边权
    struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode
{
    VertexType data;   //顶点信息
    int visited; //遍历标记. 1:已遍历  0:未遍历
    ENode *firstEdge; //第一条出边
} VNode;

typedef struct
{
    VNode vexs[MAXVEX];
    int vertexNum,edgeNum; //点数和边数
}AdjGraph,*Graph;

Graph createGraph(){
    AdjGraph *g;
    g=(AdjGraph*)malloc(sizeof(AdjGraph));
    g->edgeNum=0;
    g->vertexNum=0;
    return g;
}

int locateVertex(Graph g, VertexType v){
    int i;
    for(i=0;i<g->vertexNum;i++)
        if(v==g->vexs[i].data) return i; 
    return -1;
}
void addVertex(Graph g, VertexType v){
    int k=locateVertex(g,v);
    if(k!=-1) return ;
    int n=g->vertexNum;
    g->vexs[n].data=v;//插入最后
    g->vertexNum++;
    g->vexs[n].visited=0;
    g->vexs[n].firstEdge=NULL;
}
ENode* findEdge(Graph g, int i, int j){
    ENode *p;
    p=g->vexs[i].firstEdge;
    while (p!=NULL && p->adjVertex!=j)
        p=p->nextEdge;
    return p;
}
void addEdge(Graph g, VertexType v1, VertexType v2, int w)
{
	ENode *s, *t;
	int i,j;
	i=locateVertex(g,v1);
	j=locateVertex(g,v2);
	if(j==-1 || j==-1){
		return;
	}
	s=g->vexs[i].firstEdge;
	while(s!=NULL && s->adjVertex!=j){
		s=s->nextEdge;
	}
	if(s!=NULL){
		if(s->weight>w){
			t=g->vexs[j].firstEdge;
			while(t!=NULL && t->adjVertex!=i){
				t=t->nextEdge;
			}
			s->weight=w;
			t->weight=w;
		}
	}
	else{
		s=(ENode *)malloc(sizeof(ENode));
		s->adjVertex=j;
		s->weight=w;
		s->nextEdge=g->vexs[i].firstEdge;
		g->vexs[i].firstEdge=s;
		
		t=(ENode *)malloc(sizeof(ENode));
		t->adjVertex=i;
		t->weight=w;
		t->nextEdge=g->vexs[j].firstEdge;
		g->vexs[j].firstEdge=t;
		g->edgeNum++;
	}
} 
int degree(Graph g, VertexType v){
    ENode *p;
    int cnt=0;
    int k=locateVertex(g,v);
    p=g->vexs[k].firstEdge;
    while(p!=NULL){
        cnt++;
        p=p->nextEdge;
    }
    return cnt;
}
int connect(Graph g, VertexType x, VertexType y){
    int kx,ky;
    kx=locateVertex(g,x);
    ky=locateVertex(g,y);
    if(kx==-1 ||ky==-1) return 0;
    for(int i=0;i<g->vertexNum;i++)
        g->vexs[i].visited=0;
    DFS(g,kx);
    if(g->vexs[ky].visited==1) return 1;
    else return 0;
}
int connectedComps(Graph g){
    int i,j,cnt=0;
    for(i=0;i<g->vertexNum;i++)
        g->vexs[i].visited=0;
    for(i=0;i<g->vertexNum;i++){
        if(g->vexs[i].visited==0){
            cnt++;
            DFS(g,i);
        }
    }
    return cnt;
}
int deledge(Graph g,VertexType i,VertexType j)
{
	ENode *pre,*p,*temp;
	p=g->vexs[i].firstEdge;
	if(p!=NULL)
	{
		if(p->adjVertex==j)
		{
			temp=p;
			g->vexs[i].firstEdge=p->nextEdge;
			free(temp);
			return 1;
		}
		else
		{
			pre=p;
			p=p->nextEdge;
			while(p!=NULL&&p->adjVertex!=j)
			{
				pre=p;
				p=p->nextEdge;
			}
			if(p!=NULL)
			{
				pre->nextEdge=p->nextEdge;
				free(p);
				return 1;
			}
		}
	}
    return 0;
}
void delEdge(Graph g,VertexType x,VertexType y)
{
	int i,j;
	i=locateVertex(g,x);
	j=locateVertex(g,y);
	if(i==-1||j==-1||i==j) return;
	int k=deledge(g,i,j);
	deledge(g,j,i);
	if(k==1)
		g->edgeNum--;
}
void delVertex(Graph g, VertexType v){
    int i,j,k=locateVertex(g,v);
    ENode *p;
    if(k==-1) return;
    p=g->vexs[k].firstEdge;
    while(p!=NULL){
        j=p->adjVertex;
        p=p->nextEdge;
        delEdge(g,v,g->vexs[j].data);
    }
    g->vexs[k].firstEdge=g->vexs[g->vertexNum-1].firstEdge;
    g->vexs[k].data=g->vexs[g->vertexNum-1].data;
    for(i=0;i<g->vertexNum;i++){
        for(p=g->vexs[i].firstEdge;p!=NULL;p=p->nextEdge)
            if(p->adjVertex==g->vertexNum-1)
            p->adjVertex=k;
    }
    g->vertexNum--;
}
void DFS(Graph g, int i){
    g->vexs[i].visited=1;
    ENode *p=g->vexs[i].firstEdge;
    while(p!=NULL){
        if(g->vexs[p->adjVertex].visited==0)
            DFS(g,p->adjVertex);
        p=p->nextEdge;
    }
}
void BFS(Graph g, int i){
    queue<int>Q;
    g->vexs[i].visited=1;
    ENode *p;
    int k;
    Q.push(i);
    while(!Q.empty()){
        k=Q.front();
        Q.pop();
        p=g->vexs[k].firstEdge;
        while(p!=NULL){
            if(g->vexs[p->adjVertex].visited==0){
                g->vexs[p->adjVertex].visited=1;
                Q.push(p->adjVertex);
            }
            p=p->nextEdge;
        }
    }
}
int Prim(Graph g, VertexType u, Graph t){
    int lowcost[1001]={0};
	int parent[1001];
	int k=locateVertex(g,u);
	ENode *sk=g->vexs[k].firstEdge;
	while(sk!=NULL){
        lowcost[sk->adjVertex]=sk->weight;
        parent[sk->adjVertex]=k;
        sk=sk->nextEdge; 
        
    }
    for(int i=0;i<g->vertexNum;i++){
    	if(lowcost[i]==0)	lowcost[i]=INT_MAX;
    }
    addVertex(t,u);
    lowcost[k]=0;
    parent[k]=-1;
    
    int sum=0;
    for(int i=1;i<g->vertexNum;i++){
        int a=-1;
    	int min=INT_MAX;
    	for(int j=0;j<g->vertexNum;j++){
	    	if(lowcost[j]!=0 && min>lowcost[j]){
	    		a=j;
	    		min=lowcost[j];
	    	}
	    }
	    if(a==-1) return -1;
    	addVertex(t,g->vexs[a].data);
    	addEdge(t,g->vexs[a].data,g->vexs[parent[a]].data,lowcost[a]);
    	sum=sum+lowcost[a];
    	lowcost[a]=0;
    	sk=g->vexs[a].firstEdge;
    	while(sk!=NULL){
    		if(lowcost[sk->adjVertex]!=0&&lowcost[sk->adjVertex]>sk->weight){
		    	lowcost[sk->adjVertex]=sk->weight;
		    	parent[sk->adjVertex]=k;
		    }
            sk=sk->nextEdge; 
        }
    }
	return sum;
}
void BFS(Graph g, int i)
{
	int v;
	ENode *p;
	queue<int>Q;
	g->vexs[i].visited=1;
	Q.push(i);
	while(!Q.empty()){
		v=Q.front();
		Q.pop();
		p=g->vexs[v].firstEdge;
		while(p!=NULL){
			if(g->vexs[p->adjVertex].visited==0){
				g->vexs[p->adjVertex].visited=1;
				Q.push(p->adjVertex);
			}
			p=p->nextEdge;
		}
	}
}

int Kruskal(Graph g){
	int lowcost[1001]={0};
	int parent[1001];
	int k=0;
	ENode *sk=g->vexs[k].firstEdge;
	while(sk!=NULL){
        lowcost[sk->adjVertex]=sk->weight;
        parent[sk->adjVertex]=k;
        sk=sk->nextEdge; 
        
    }
    for(int i=0;i<g->vertexNum;i++){
    	if(lowcost[i]==0){
	    	lowcost[i]=INT_MAX;
	    }
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
    	sk=g->vexs[a].firstEdge;
    	while(sk!=NULL){
    		if(lowcost[sk->adjVertex]!=0&&lowcost[sk->adjVertex]>sk->weight){
		    	lowcost[sk->adjVertex]=sk->weight;
		    	parent[sk->adjVertex]=k;
		    }
            sk=sk->nextEdge; 
        }
    	
    }
	return sum;
}

int Kruskal(Graph g, Graph t)
{
	int lowcost[1001]={0};
	int parent[1001];
	int k=0;
	ENode *sk=g->vexs[k].firstEdge;
	while(sk!=NULL){
        lowcost[sk->adjVertex]=sk->weight;
        parent[sk->adjVertex]=k;
        sk=sk->nextEdge; 
        
    }
    for(int i=0;i<g->vertexNum;i++){
    	if(lowcost[i]==0){
	    	lowcost[i]=INT_MAX;
	    }
    }
    addVertex(t,g->vexs[0].data);
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
    	addVertex(t,g->vexs[a].data);
    	addEdge(t,g->vexs[a].data,g->vexs[parent[a]].data,lowcost[a]);
    	sum=sum+lowcost[a];
    	lowcost[a]=0;
    	sk=g->vexs[a].firstEdge;
    	while(sk!=NULL){
    		if(lowcost[sk->adjVertex]!=0&&lowcost[sk->adjVertex]>sk->weight){
		    	lowcost[sk->adjVertex]=sk->weight;
		    	parent[sk->adjVertex]=k;
		    }
            sk=sk->nextEdge; 
        }
    	
    }
	return sum;
}


int main()
{
    return 0;
}
