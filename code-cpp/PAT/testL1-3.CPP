#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
   char str[10];
   scanf("%s", str);
   int len = strlen(str); 
   //cout<<len<<endl;
   //cout<<str[0]<<" "<<str[1]<<endl;
   int i=int(str[0]-'0')*10+int(str[1]-'0');
   //cout<<i<<endl;
    if(len == 4 ){ 
        int year = 0; 
        if(i<22) 
            year = 20; 
        else 
            year = 19; 
        printf("%d%c%c-%c%c\n", year, str[0], str[1], str[2], str[3]); 
    }else if(len == 6){ 
        printf("%c%c%c%c-%c%c\n", str[0], str[1], str[2], str[3], str[4], str[5]); 
    } 
    return 0; 
}