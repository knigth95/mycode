#include<stdio.h>
int main(){
    char ch;
    char map[20][30];
    FILE *ft=fopen("C:/Users/king/Desktop/Projects/snake/snakeMove(CFREE)/map2.txt","r");
    if(ft==NULL){
        printf("shibai\n");
        return 0;
    } 
    
    for(int i=0;i<20 &&!feof(ft);i++){
        int k=1;
        for(int j=0;j<30 &&!feof(ft) ;j++){
                ch=getc(ft);
                if(ch=='1' || ch=='0')
                    map[i][k++]=ch;         
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<30;j++){
          printf("%c",map[i][j]);
        }
        printf("\n");
    }
    fclose(ft);
    return 0;
}