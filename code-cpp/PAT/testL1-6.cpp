#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string name;
    string goal1 = "qiandao";
    string goal2 = "easy";
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++){
		getline(cin,name);
		if (name.find(goal1) !=-1 || name.find(goal2) !=-1)
			continue;
		else if (m == 0){
			cout << name;
			return 0;
		}
		m--;
	}
	cout << "Wo AK le";
	return 0;
}
