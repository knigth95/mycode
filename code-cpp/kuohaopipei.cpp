#include<bits/stdc++.h>
using namespace std;
typedef char zzm;
typedef struct {
    zzm *array;
    int top;
    int can;
}Node;
Node* create(int can){
    Node *s;
    s=(Node*)malloc(sizeof(Node));
    s->array=(zzm*)malloc(can*sizeof(zzm));//相当给一个可用地址
    //s->array=NULL;//分配好空间后又NULL会导致丢失所得空间
    s->can=can;//以上相当得到一栋房的钥匙,转头扔了
    s->top=-1;
    return s;
}
int bijiao(char a,char b){//符号比较
    if(a=='[' && b==']') return 1;
    if(a=='(' && b==')') return 1;
    if(a=='{' && b=='}') return 1;
    return 0;
}

int main(){
    zzm str[1566];
    char c;
    Node *s;
    int len,i;
    gets(str);
    len=strlen(str);
    s=create(len);
    for(i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s->top++;
            s->array[s->top]=str[i];
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(s->top==-1){
                cout<<"no"<<endl;
                return 0;
            }
            c=s->array[s->top];
            s->top--;
            if(bijiao(c,str[i])==0){
                cout<<"no"<<endl;
                return 0;
            } 
        } 
    }
    if(s->top==-1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    return 0;
}