#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
	ElementType *data; //数据
	int size;	 		//大小
	int capacity;  		//容量
}HNode, *Heap;

int parent(int i){//父节点
    return i/2;
}
Heap createHeap(int capacity){//创建
    Heap p;
    p=(HNode*)malloc(sizeof(HNode));
    p->data=(ElementType*)malloc(capacity*sizeof(HNode));
    p->capacity=capacity;
    p->size=0;
    return p;
}

int left(int i){//左儿子结点
    return 2*i;
}

int right(int i){//右儿子结点
    return 2*i+1;
}
int full(Heap H){//判满
    if(H->size==H->capacity) return 1;
    return 0;
}
int empty(Heap H){//判空
    if(H->size==0) return 1;
    return 0;
}
void swap(Heap H, int i, int j){//交换
    ElementType tmp;
    tmp=H->data[i];
    H->data[i]=H->data[j];
    H->data[j]=tmp;
}
void destroyHeap(Heap H){//销毁
    if(H!=NULL) free(H->data);
    H->capacity=0;
    H->size=0;
    H->data=NULL;
}
int insert(Heap H, ElementType x){//插入最大堆 超时
    if(H->size>=H->capacity) return 0;
	int i;
	H->data[0]=x;
	for(i=H->size;H->data[i/2]<x;i=i/2)
		H->data[i]=H->data[i/2];
	H->data[i]=x;
	return 1;
}

int insert(Heap H, ElementType x){//插入最大堆 AC
	int i;
	if(H->size<H->capacity){
		H->size++;
		H->data[0]=x;
		i=H->size;
		while(H->data[i/2]<x){
			H->data[i]=H->data[i/2];
			i=i/2;
		}
		H->data[i]=x;
		return 1;
	}
	else return 0;
}



int main()
{
    return 0;
}

void increase(Heap H, int i, ElementType x){//增大结点数值
	int k;
	if(x<H->data[i]) return;
	H->data[i]=x;
	k=i/2;
	while(k>=1){
		if(H->data[k]<x) swap(H,k,i);
		i=k;
		k=i/2;
	}
}

void initHeap(Heap H, ElementType data[], int n){//初始化堆
	int temp,k,i;
	for(i=1; i<=n; i++){
		H->data[i]=data[i];
		H->size++;
	}
	for(k=n/2; k>=1; k--){
		temp=H->data[k];
		for(i=2*k; i<=n; i*=2){
			if(i<n && H->data[i]<H->data[i+1]){
				i++;
			}
			if(H->data[i]<=temp){
				break;
			}
			H->data[k]=H->data[i];
			k=i;
		}
		H->data[k]=temp;
	}
}
void heapSort(Heap H){
	int i,k,j,t,f,n;
	n=H->size;
	for(i=n;i>1;i--){
		t=H->data[1];
		H->data[1]=H->data[i];
		H->data[i]=t;
		f=H->data[1];
		k=1;
		for(j=2*k;j<=i-1;j=j*2){
			if(j<i-1 && H->data[j]<H->data[j+1]) j++; 
			if(H->data[j]<=f)	break;
			H->data[k]=H->data[j];
			k=j;
		}
		H->data[k]=f;
	}
}

ElementType front(Heap H){//队首
	return H->data[1];
}

int push(Heap H,ElementType x){//入队
	if(H->capacity==H->size) return 0;
	int t,n,i;
	H->data[0]=x;
	H->size++;
	n=H->size;
	while(H->data[n/2]<x){
		H->data[n]=H->data[n/2];
		n=n/2;
	}
	H->data[n]=x;
	return 1;
}
void pop(Heap H){
	H->data[1]=H->data[H->size];
	H->size--;
	heapify(H,1);
}
