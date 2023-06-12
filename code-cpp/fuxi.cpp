#include<bits/stdc++.h>
using namespace std;

typedef int zzm;
typedef struct {
    char name[20];
    char id[20];
    char sex;
    double x,y,z;
}student,zzm;

typedef struct Node{
    zzm data;
    struct Node *next;   
}Node,*Link;

Link create(){
    Node *L;
    L=(Node*)malloc(sizeof(Node));
    L->next=NULL;
    return L;
}


int main(){
    char order[10];
    char id[10];
    Node *p;
    Link L;
    L=create();
    return 0;
}