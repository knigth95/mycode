#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100 /*最大顶点数*/
typedef char VertexType;

struct AOENetworkStruct;
typedef struct AOENetworkStruct *AOENetwork;

typedef struct ENode
{
    int adjVertex;  //边的终点编号
    int weight;     //边权
    int earliest;   //活动最早开始时间
    int latest;     //活动最晚开始时间
    struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode
{
    VertexType data;    //顶点信息/
    int inDegree;       //入度/
    int earliest;       //事件最早发生时间/
    int latest;         //事件最晚发生时间
    ENode *firstEdge; //第一条出边
} VNode;

struct AOENetworkStruct
{
    VNode vexs[MAXVEX];    //点表
    int vertexNum, edgeNum; //顶点数和弧数
};

AOENetwork createGraph(){
    AOENetwork g;
    g=(AOENetworkStruct*)malloc(sizeof(AOENetworkStruct));
    g->edgeNum=0;
    g->vertexNum=0;
    return g;
}
int locateVertex(AOENetwork g, VertexType v){
    for(int i=0;i<g->vertexNum;i++)
        if(v==g->vexs[i].data) return i;
    return -1;
}
ENode* findEdge(AOENetwork g, int i, int j){
    ENode *p;
    p=g->vexs[i].firstEdge;
    while(p!=NULL && p->adjVertex!=j)
        p=p->nextEdge;
    return p;
}
void addVertex(AOENetwork g, VertexType v){
    int k=locateVertex(g,v);
    if(k!=-1) return;
    int n=g->vertexNum;
    g->vexs[n].data=v;
    g->vexs[n].firstEdge=NULL;
    g->vertexNum++;
}
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w){
    ENode *s,*t;
    int k1=locateVertex(g,v1);
    int k2=locateVertex(g,v2);
    if(k1==-1 || k2==-1) return;
    s=findEdge(g,k1,k2);
    if(s!=NULL){
        if(s->weight>w){
            //t=findEdge(g,k2,k1);
            s->weight=w;
            //t->weight=w;
        }
    }
    else{//不存在
        s=(ENode*)malloc(sizeof(ENode));
        s->adjVertex=k2;
        s->weight=w;
        s->earliest=0;
        s->latest=0;    
        s->nextEdge=g->vexs[k1].firstEdge;
        g->vexs[k1].firstEdge=s;
        g->vexs[k2].inDegree++;
        g->edgeNum++;
    }
}

int TopSort(AOENetwork g){
   int cnt=0,x,i,y;
   ENode *p;
   stack<int>out;
   stack<int>in;
   for(i=0;i<g->vertexNum;i++){
       g->vexs[i].earliest=0;
       if(g->vexs[i].inDegree==0) in.push(i);//入度为0的顶点入栈
   }
   while(!in.empty()){
       x=in.top();
       in.pop();
       cnt++;
       out.push(x);
       for(p=g->vexs[x].firstEdge;p!=NULL;p=p->nextEdge){
           y=p->adjVertex;
           g->vexs[y].inDegree--;
            if(g->vexs[y].inDegree==0) in.push(y);
            if(g->vexs[y].earliest<g->vexs[x].earliest+p->weight)
                g->vexs[y].earliest=g->vexs[x].earliest+p->weight;
       }
   }
   if(cnt<g->vertexNum) return 0;
   else return 1;
}

void event(AOENetwork g){//求最早发生时间和最晚发生时间
    int a[MAXVEX],top=0,i,cnt=1,k=0;
    for(i=0;i<g->vertexNum;i++){
    	g->vexs[i].earliest=0;
        g->vexs[i].latest=0;
	}
	a[top]=0;
	while(k<=top){
		ENode *p=g->vexs[a[k]].firstEdge;
		while(p){
			int z=p->adjVertex;
			g->vexs[z].inDegree--;
			if(g->vexs[z].inDegree==0){
				top++;
				a[top]=z;
			}
			if(g->vexs[z].earliest<g->vexs[a[k]].earliest+p->weight)
				g->vexs[z].earliest=g->vexs[a[k]].earliest+p->weight;
			p=p->nextEdge;
		}
		k++;
	}
	for(i=0;i<g->vertexNum;i++) g->vexs[i].latest=g->vexs[g->vertexNum-1].earliest;
	while(top>=0){
		ENode *p2=g->vexs[a[top]].firstEdge;
		while(p2!=NULL){//求最晚发生时间
			int zzm=p2->adjVertex;
			if(g->vexs[a[top]].latest>g->vexs[zzm].latest-p2->weight)
				g->vexs[a[top]].latest=g->vexs[zzm].latest-p2->weight;
			p2=p2->nextEdge;
		}
		top--;
	} 
}

int pathNum(AOENetwork g){
    int a[MAXVEX*MAXVEX];
    int top=0,k=0,cnt=0;
    a[top]=0;
    while(k<=top){
        ENode *p=g->vexs[a[k]].firstEdge;
        while(p!=NULL){//求最晚发生时间
            int z=p->adjVertex;
            if(p->earliest==p->latest){//可以到达
                top++;
                a[top]=z;
            }
            if(z==g->vertexNum-1) cnt++;//到达终点
            p=p->nextEdge;
        }
        k++;
    }
    return cnt;
}

int active(AOENetwork g){
    int sum=0,i;
    for(i=0;i<g->vertexNum;i++){
        ENode *p=g->vexs[i].firstEdge;
        while(p!=NULL){
            p->earliest=g->vexs[i].earliest;
            p->latest=g->vexs[p->adjVertex].latest-p->weight;
            if(p->earliest==p->latest) sum++;
            p=p->nextEdge;
        }
    }
    return sum;
}
int main()
{
    int n,i;
    char s[101];
    struct AOENetworkStruct *g=createGraph();
    cin>>n;
    getchar();
    gets(s);
    for(i=0;i<n;i++) addVertex(g,s[i]);
    while(1){
        char v1,v2;
        cin>>v1>>v2;
        if(v1=='0' && v2=='0') break;
        int w;
        cin>>w;
        //getchar();到底cin与getchar搭配影不影响
        addEdge(g,v1,v2,w);
    }
    event(g);
    int sum=active(g);
    int cnt=pathNum(g);
    cout<<cnt<<endl;
    return 0;
}
