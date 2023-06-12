#include<cstdio>
#include<iostream>
#include<time.h>
using namespace std;
int graph[100][100], corder[100], bestorder[100], vis[100];
int v, e, cnt, best; 
int isTuan(int index){
	int i;
    for(i=1; i<index; i++){
        if(vis[i] && !graph[i][index]){
            return 0;
        }
    }
    return 1;
}
void backtrace(int index){
	int i;
    if(index>v){
        if(cnt>best){
            best=cnt;
            printf("%d\n",best);
			for(i=1; i<=v; i++){
                if(corder[i]!=0){
                	printf("1 ");                	
                }
                else{
                	printf("0 ");                	
                }
            }
        } 
    }
    if(isTuan(index)){
        cnt++;
        vis[index]=1;
        corder[index]=index;
        backtrace(index+1);
        cnt--;
        vis[index]=0;
        corder[index]=0;
    }
    if(cnt+v-index>best){
        backtrace(index+1);
    }
} 
int main(){
    scanf("%d",&v);
    int i, j;
    for(i=1; i<=v; i++){
        for(j=1; j<=v; j++){
           scanf("%d",&graph[i][j]);
        }
    }
    clock_t time1=clock();
    backtrace(1);
    clock_t time2=clock();
	printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
	return 0;
}