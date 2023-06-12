#include<bits/stdc++.h>
using namespace std;
typedef struct st{
	char data;
	struct st *left;
	struct st *right;
}tree,*zzm; 
zzm build(string str){
	stack<zzm>fa;
	for(int i=0;i<str.size();i++){
		zzm ji=(tree*)malloc(sizeof(tree));
		ji->data=str[i];
		ji->left=ji->right=NULL;
		if(!isalpha(str[i])){//判断该字符是否为字母
			ji->right=fa.top();
			fa.pop();
			ji->left=fa.top();
			fa.pop();
		}
		fa.push(ji);
	}
	return fa.top();
}
void preprint(zzm fa){
	if(fa!=NULL){
		cout<<fa->data;
		preprint(fa->left);
		preprint(fa->right);
	}
}
void midprint(zzm fa){
	if(fa!=NULL){
		midprint(fa->left);
		cout<<fa->data;
		midprint(fa->right);
	}
}
int main(){
	string str;
	cin>>str;
	zzm head=build(str);
	preprint(head);
	cout<<endl;
	midprint(head);
	cout<<endl;
	return 0;
}