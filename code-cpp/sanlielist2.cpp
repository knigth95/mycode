#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;

typedef struct HashNode
{
    ElementType key;
    struct HashNode * next;
}HashNode,* List;

typedef struct
{
    int size;
    List * lists;//槽指针,所有链表均有头结点
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

HashTable * create(int size){
    HashTable * h=(HashTable*)malloc(sizeof(HashTable));
    h->size=nextPrime(size);
    h->lists=(List*)malloc(h->size*sizeof(List));
    for(int i=0;i<h->size;i++){
        h->lists[i]=(List)malloc(sizeof(HashNode));
        h->lists[i]->next=NULL;
    }
    return h;
}

int hash(HashTable * h,ElementType key){
    return key%h->size;
}
HashNode * find(HashTable * h,ElementType key){
    int i=hash(h,key);
    HashNode* p=h->lists[i]->next;
    while(p!=NULL){
        if(p->key==key) return p;
        p=p->next;
    }
    return NULL;
}
void insert(HashTable * h,ElementType key){
    int i=hash(h,key);
    HashNode * p=h->lists[i];
    while(p!=NULL){
        if(p->key==key) return;
        p=p->next;
    }
    HashNode * q=(HashNode*)malloc(sizeof(HashNode));
    q->key=key;
    q->next=h->lists[i]->next;
    h->lists[i]->next=q;
}

void del(HashTable * h,ElementType key){
    HashNode* pre=findPre(h,key);
    if(pre==NULL) return;
    HashNode* p=pre->next;
    p=p->next;
    free(pre->next);
    h->size--;
}
HashNode * findPre(HashTable * h,ElementType key){
    HashNode *p,*pre;
    int n,z=0;
    n=hash(h,key);
    pre=h->lists[n];
    p=h->lists[n]->next;
    while(p!=NULL){
        if(p->key==key) return pre;
        p=p->next;
        pre=p;
    }
    return NULL;
}
void del(HashTable * h,ElementType key){
    HashNode * pre=findPre(h,key);
    if(pre==NULL) return;
    pre->next=pre->next->next;
    free(pre->next);
    h->size--;
}
void destroy(HashTable * h){
    for(int i=0;i<h->size;i++){
        for(HashNode* j=h->lists[i];j!=NULL;j=j->next)
            free(j);
        h->lists[i]=NULL;    
    }
    free(h->lists);
    h=NULL;
}
void destroy(HashTable * h){
    for(int i=0;i<h->size;i++){
        HashNode* p=h->lists[i];
        while(p!=NULL){
            HashNode* q=p->next;
            free(p);
            p=q;
        }        
        h->lists[i]=NULL;//清空链表与清空槽区分
        //不清空链表会超出内存,也可能是内存泄露的原因
    }
    free(h->lists);
    h=NULL;
}

int main()
{
    return 0;
}