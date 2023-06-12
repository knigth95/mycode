#include<bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef struct{
	ElementType *array;
	int top;
	int capacity;
}SeqStack;
SeqStack *createStack(int capacity);
int empty(SeqStack *S);
int IsFull(SeqStack *S);
int push(SeqStack *S,ElementType x);
int pop(SeqStack *S);
ElementType top(SeqStack *S);
int IsYSF(char c);
int prior(SeqStack *S,char c); 
SeqStack *createStack(int capacity)
{
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	S->top=-1;
	S->capacity=capacity;
	S->array=(ElementType *)malloc(capacity*sizeof(ElementType));
	return S;
}
int empty(SeqStack *S)
{
	if(S->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int IsFull(SeqStack *S)
{
	if(S->top>=S->capacity-1){
		return 1;
	}
	else{
		return 0;
	}
}
int push(SeqStack *S,ElementType x)
{
	if(IsFull(S)){
		return 0;
	}
	else{
		S->top++;
		S->array[S->top]=x;
		return 1;
	}
}
int pop(SeqStack *S)
{
	if(empty(S)){
		return 0;
	}
	else{
		S->top--;
		return 1;
	}
}
ElementType top(SeqStack *S)
{
	return S->array[S->top];
}
int IsYSF(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/'){
		return 1;
	}
	else{
		return 0;
	}
}
int prior(SeqStack *S,char c)
{ 
	if(S->top==-1){
		return 1; 	//栈顶元素小于str[i];
	} 
	else{
		if((c=='*' || c=='/') && (top(S)=='+' || top(S)=='-')){
			return 1;     
		}
		if(top(S)=='('){
			return 1; 
		} 
		else{
			return 0;
		}
	} 
}
int main()
{
	SeqStack *S;
	S=createStack(1001);
	char str[101];
	int i;
	gets(str);
	int flag=0;
	for(i=0; str[i]!='\0'; i++){
		if(str[i]==' '){
			continue;
		}
		else if(isdigit(str[i])){
			if(flag==0){
				printf("%c",str[i]);	
			}
			else{
				printf(" %c",str[i]);
			}
			flag++;
		}
		else if(str[i]=='('){
			push(S,str[i]);
		}
		else if(str[i]==')'){
			while(top(S)!='('){
				if(IsYSF(top(S))){ 
					printf(" %c",top(S)); 
				} 
				pop(S);
			}
			pop(S); 
		}
		else if(IsYSF(str[i])){
			if(prior(S,str[i])==1){
				push(S,str[i]);
			}
			else{
				while(prior(S,str[i])==0){
					if(IsYSF(top(S))){ 
						printf(" %c",top(S)); 
					} 
					pop(S);
				}
				push(S,str[i]);	
			}
		}
	}
	while(S->top>-1){
		printf(" %c",top(S));
		pop(S);	
	}
	printf("\n"); 
	return 0;	
}