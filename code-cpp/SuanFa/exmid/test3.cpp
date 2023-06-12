#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN=1005;
struct node {
    int p,q;
    node(int _p,int _q){p=_p,q=_q;}
};

map<string,int> mp;
vector<node> vt[MAXN];
int cont;
int n, sum;
bool judge(int t)
{
    int sum1=0;
    int flag=0;
    int num=0;
    for(int i=1; i<cont; i++) {
        int tmp=1000010;
        for(int j=0; j<vt[i].size(); j++) {
            if(vt[i][j].q >= t)
                tmp=min(vt[i][j].p,tmp);                
        }
        if(tmp != 1000010)
            num++;
        sum1 += tmp;
    }
    return (sum1<=sum) && num==(cont-1);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        cin>>n>>sum;
        cont=1;
        int l=0;
        int r=-1;
        for (int i=0; i<n; i++)
            vt[i].clear();
        for (int i=0; i<n; i++) {
            string name1,name2;
            int q,p;
            cin>>name1>>name2>>p>>q;
            if(!mp[name1]) {
				mp[name1]=cont,cont++;	}
            vt[mp[name1]].push_back(node(p,q));
            r=max(r,q);
        } 
        while (l<=r) {
            int mid=(l+r)/2;
            if(judge(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        cout<<(l+r)/2<<endl;
    }
    return 0;
}