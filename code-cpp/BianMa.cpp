#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef struct
{
    KeyType value;
    int weight;
} Node;

typedef struct HTNode
{
    KeyType value; //节点数值
    int weight;  //节点权
    HTNode * lchild;
    HTNode * rchild;
    int depth;
    bool operator < (const HTNode &a)const
    {
        return weight < a.weight||(weight==a.weight&&value < a.value);
    }
} HTNode, *HuffmanTree;

typedef HuffmanTree ElementType;
typedef struct
{
    ElementType * data; //数据
    int size;	 		//大小
    int capacity;  		//容量
} HNode, *Heap;
void heapify(Heap H,int i);
void huffmanCode(HuffmanTree HT,int code[],int depth);
void initHeap(Heap H,Node data[],int n);
void push(Heap H,ElementType x);
ElementType front(Heap H);
void pop(Heap H);
Heap createHeap(int n);
HuffmanTree createHuffmanTree(Node data[],int n);
void initDepth(HuffmanTree HT,int depth);
int getWPL(HuffmanTree HT);
void swap(Heap H,int temp,int j);
void destroyHeap(Heap H);
const int N=1e5+10;
int n;
int code[N],cnt;
Node fa[N];
int main()
{
    cin>>n;
    while(n--){
    	int a,b;cin>>a>>b;
    	fa[++cnt]={a,b};
    }
    HuffmanTree H=createHuffmanTree(fa,cnt);
    huffmanCode(H,code,0);
	return 0;
}
void huffmanCode(HuffmanTree HT,int code[],int depth){
	if(HT->lchild!=NULL){
		code[depth]=0;
		huffmanCode(HT->lchild,code,depth+1);
	}
	if(HT->rchild!=NULL){
		code[depth]=1;
		huffmanCode(HT->rchild,code,depth+1);
	}
	if(HT->lchild==NULL&&HT->rchild==NULL){
		cout<<HT->value<<":";
		for(int i=0;i<depth;i++){
			cout<<code[i];
		}
		cout<<endl;	
	}
}
void heapify(Heap H,int i){	
	int temp=i;
	for(int j=i<<1;j<=H->size;j<<=1){
		if(j<H->size&&(*H->data[j|1])<(*H->data[j])){
			j++;
		}
		if((*H->data[temp])<(*H->data[j])) break;
		swap(H,temp,j);
		temp=j;
	}
}
void swap(Heap H,int i,int j){
	swap(H->data[i],H->data[j]);
}
void initHeap(Heap H,Node data[],int n){
	for(int i=1;i<=n;i++){
		ElementType k=(ElementType)malloc(sizeof(HTNode));
		k->value=data[i].value;
		k->weight=data[i].weight;
		k->lchild=k->rchild=NULL;
		H->data[i]=k;
	}
	H->size=n;
	for(int i=n/2;i;i--){
		heapify(H,i);
	}
	
}
void push(Heap H,ElementType x){
	H->data[++H->size]=x;
	H->data[0]=x;
	int i=H->size;
	while(*x<*H->data[i/2]){
		H->data[i]=H->data[i>>1];
		i>>=1;
	}
	H->data[i]=x;
}
ElementType front(Heap H){
	return H->data[1];
}
void pop(Heap H){
	H->data[1]=H->data[H->size--];
	heapify(H,1);
}
HuffmanTree createHuffmanTree(Node data[],int n){
	Heap H = createHeap(n);
	 initHeap(H,data,n);
	 while(H->size>1){
	 	HuffmanTree a,b,c;
	 	c=(HuffmanTree)malloc(sizeof(HTNode));
	 	a=front(H);pop(H);
	 	b=front(H);pop(H);
	 	c->lchild=a;c->rchild=b;
	 	c->value=min(a->value,b->value);
	 	c->weight=a->weight+b->weight;
	 	push(H,c);
	 }
	 HuffmanTree h=front(H);
	 destroyHeap(H);
	 return h;
}
void initDepth(HuffmanTree HT,int depth){
	if(HT!=NULL){
		HT->depth=depth;
		initDepth(HT->lchild,depth+1);
		initDepth(HT->rchild,depth+1);
	}
} 
int getWPL(HuffmanTree HT){
	if(HT->lchild==NULL&&HT->rchild==NULL) return HT->depth*HT->weight;
	int ans=0;
	if(HT->lchild!=NULL) ans+=getWPL(HT->lchild);
	if(HT->rchild!=NULL) ans+=getWPL(HT->rchild);
	return ans;
}
Heap createHeap(int n){
	Heap g=(Heap)malloc(sizeof(HNode));
	g->data=(ElementType*)malloc(sizeof(ElementType)*(n+1));
	g->capacity=n;g->size=0;
	return g;
}
void destroyHeap(Heap H){
	free(H);
} 