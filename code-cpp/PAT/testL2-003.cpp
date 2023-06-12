#include<bits/stdc++.h>
using namespace std;
struct smoon{
	double weight;//吨数
	double piece;//价格
	double dan;//单价
};
bool cmp(smoon a,smoon b)
{
	return a.dan>b.dan;//按单价排序
}
int main()
{
	int n,i;
    double m;
    struct smoon z[2003];
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>z[i].weight;
	
	for(i=0;i<n;i++){
		cin>>z[i].piece;
		z[i].dan=1.0*z[i].piece/z[i].weight;
	}
	sort(z,z+n,cmp);
	double sum=0;
	i=0;
	for(i=0;i<n;i++){
        if(m==0) break;
        else if(m>= z[i].weight){
            m-=z[i].weight;
            sum+=z[i].piece;
        }
        else if(m< z[i].weight){
            sum+=m*z[i].dan;
            m=0;
        }
    }
	printf("%.2lf\n",sum);//保留2位小数
	return 0;
}