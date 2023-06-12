#include <algorithm>
#include <iostream>
using namespace std;

#define NN 100000
int n, k;
long long x[NN+1];
long long d[NN+1][2], mind[NN+1][2];

long long dp()
{
	mind[0][1] = 0x7fffffff;
	for (int i = 1; i <= n; i++) {
		d[i][1] = x[i];
		mind[i][1] = min(d[i][1], mind[i-1][1]);
	}
	for (int j = 2; j <= k; j++) {
		mind[j][j%2] = d[j][j%2] = d[j-1][(j-1)%2] + j * x[j];
		for (int i = j+1; i <= n; i++) {
			d[i][j%2] = mind[i-1][(j-1)%2] + j * x[i];
			mind[i][j%2] = min(d[i][j%2], mind[i-1][j%2]);
		}
	}
	return mind[n][k%2];
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		cout << dp() << endl;
	};
	return 0;
}
