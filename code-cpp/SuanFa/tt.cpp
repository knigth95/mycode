#include<stdio.h>
int main()
{
 int n,b,i,c;
 char a[100];
 scanf("%d",&n);
 while(n>0) //记录行数 
 {
    for(int k=0;k<n;k++){
        char c;
        while(scanf("%c",&c)&&c!='\n'){
            if() {}
            else if(){}
        }




    }



     for(i=1;a[i-1]<='z'&&a[i-1]>='a'||a[i-1]<='Z'&&a[i-1]>='A';i++){ //判断输入并输出 
         scanf("%d",&a[i]);
      if(a[i]<='z'&&a[i]>='a'){  //小写字符加密 
          b=a[i]-96;
          printf("%c\n",a[i]);
          printf("%d",b);
         }
         else if(a[i]<='Z'&&a[i]>='A'){  //大写字符加密 
          b=a[i]-64+26;
          printf("%d",b);
         }
        }
      if(a[i]==32){   //输出空格 
          printf(" ");
         }
         else{
          printf("%c",a[i]);   //输出标点
       printf("\n");   //换行
      }
     
  n--;   //出循环 
 }
 return 0;
}