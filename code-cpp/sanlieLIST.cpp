#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct
{
    ElementType key; //关键数字
    int flag;        //状态标志：USED(槽已用)或EMPTY(空闲)
}Cell;

typedef struct
{
    Cell *cells;  //散列表槽指针
    int capacity; //散列表容量
    int size;     //散列表大小
}HashTable;
bool isPrime(int n){
    if(n<2) return false;
    else if(n==2 ||n==3) return true;
    else if(n%6==1 || n%6==5){
        double p=sqrt(n);
        for(int i=2;i<=p;i++){
            if(n%i==0) return false;
            return true;
        }
    }
    else return false;
}
int nextPrime(int n){
    if(isPrime(n)) n++;
    while(!(isPrime(n) && n%4==3)) n++;
    return n;
}

HashTable * create(int capacity){
    HashTable *h=(HashTable*)malloc(sizeof(HashTable));
    //h->capacity=nextPrime(capacity);
    h->capacity=capacity;
    h->size=0;
    h->cells=(Cell*)malloc(capacity*sizeof(Cell));
    for(int i=0;i<h->capacity;i++){
        h->cells[i].flag=EMPTY;
        h->cells[i].key=NULL;
    }
    return h;
}
int hash(HashTable * h,ElementType key){
    return key%h->capacity;
}
int find(HashTable * h,ElementType key){
    int k,n,z=0;
    n=k=hash(h,key);
    //if(h->cells[n].flag==EMPTY) return n;
    //这段if冗余,但是就没有例外情况嘛
    while(h->cells[n].flag!=EMPTY && h->cells[n].key!=key){
        if(++z%2!=0){//之前除4是为了确保n在范围内
            n=k+(z+1)*(z+1)%h->capacity;//k作为查找标记
            while(n>=h->capacity) n=n-h->capacity;
        }
        else{
            n=k-z*z%h->capacity;//k保证它不重复0处找
            while(n<0) n=n+h->capacity;
        }
    }
    return n;
}
void insert(HashTable * h,ElementType key){
    int n=find(h,key);
    if(h->cells[n].key==key) return;
    int z=0,k;
    while(h->cells[n].flag!=EMPTY){
        if(++z%2!=0){
            k=n+(z+1)*(z+1)%h->capacity;
            while(k>=h->capacity) k=k-h->capacity;
        }
        else{
            k=n-z*z%h->capacity;
            while(k<0) k=k+h->capacity;
        }
        if(h->cells[k].key==key) return;
        n=k;
    }
    h->cells[n].key=key;
    h->cells[n].flag=USED;
    h->size++;
}
void rehash(HashTable * h){
    HashTable *g=(HashTable*)malloc(sizeof(HashTable));
    g->capacity=h->capacity*2;
    g->size=h->size;
    g->cells=(Cell*)malloc(g->capacity*sizeof(Cell));
    for(int i=0;i<g->capacity;i++){
        g->cells[i].flag=EMPTY;
        g->cells[i].key=NULL;
    }
    for(int i=0;i<h->capacity;i++){//将原散列表中的数据插入新散列表
        if(h->cells[i].flag==USED){
            insert(g,h->cells[i].key);
        }
    }
    free(h->cells);
    //必须先释放原来的槽后放新槽,不然就超出内存
    h->cells=g->cells;
    //更新槽指针,不释放行不行,别问我,不释放就10分
    h->capacity=g->capacity;
    free(g);
}
/*
void insert(HashTable * h,ElementType key){
    int n=find(h,key);
    if(h->cells[n].flag==USED) return;
    else{
        h->cells[n].key=key;
        h->cells[n].flag=USED;
        h->size++;
        if(h->size>h->capacity*0.5) rehash(h);
    }   
}
*/
void destroy (HashTable * h){
    free(h);
}


int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a/b<<endl;
    return 0;
}