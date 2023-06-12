#include<stdio.h>
#include<stack>
using namespace std;
/*
int solve(char str[])
{
        stack<int>s;//设置一个栈 
        int i,a,b,r;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]>='0' && str[i]<='9') s.push(str[i]-'0');
            if(str[i]=='+'||str[i]=='-'||str[i]=='*'||
            str[i]=='/') {
            b=s.top(); s.pop();
            a=s.top();s.pop();
            if(str[i]=='-') r=a-b;
            else if(str[i]=='+') r=a+b;
            else if(str[i]=='*') r=a*b;
            else if(str[i]=='/') r=a/b;
            s.push(r);
            }
        }
        return s.top();
}
*/
int compare(char top,char now)
{
 if(now=='+'||now=='-'){
  if(top =='*' ||top =='/'||top =='+'||top == '-')
   return 1;//出栈
  return 0;//入栈  
 }
 if(now=='*'||now=='/') {
  if(top=='*'||top=='/')
  return 1;//出栈
 return 0;//入栈  
 } 
} 

void change(char str[]) 
{
    stack<char>s;
    char temp[101];
    int j = 0;
    for(int i=0;str[i]!='\0';i++)
    {
    if(str[i]>='0' && str[i]<='9')//如果读的是运算符,则直接输出 
    {
    temp[j++] = str[i];
    }
    if(str[i]=='('||str[i]=='['||str[i]=='{') s.push(str[i]);//如果读的是左括号,则将其压入栈中
    if(str[i]==')'||str[i]==']'||str[i]=='}') //读入的为右括号,将栈顶的运算符输出,直到遇见左括号 
    {
    while(s.top()!='('||s.top()!='['||s.top()!='{')
    {
        temp[j++] = s.top();
        s.pop();
    }
    s.pop();//左括号也出栈,但不输出  
    }
    if(str[i]=='+'||str[i]=='-'||str[i]=='*'||
    str[i]=='/')//top<now,则入栈,反之top输出,直到Top<now,str入栈 
    {
    while(!compare(s.top(),str[i])){
        temp[j++] = s.top();
        s.pop();
    }
    s.push(str[i]);
    } 
    }
    if(!s.empty())//不是空的 
    {
    while(s.top()!=NULL)
    {
    temp[j++] = s.top();
    s.pop(); 
    }  
    }
    for(int i=0;i<j;i++)//输出转换好的 
    {
    printf("%c",temp[i]);
    }
    printf("\n");
}

int main()
{
    char str[100];
    gets(str);

    solve(str);
 }