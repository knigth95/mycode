#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
long long x[5001];
long long d[5001][5001], mind[5001][5001];
long long dp()
{
	mind[0][1] = 0x7fffffff;
	for (int i = 1; i <= n; i++) {
		d[i][1] = x[i];
		mind[i][1] = min(d[i][1], mind[i-1][1]);
	}
	for (int j = 2; j <= k; j++) {
		mind[j][j] = d[j][j] = d[j-1][j-1] + j * x[j];
		for (int i = j+1; i <= n; i++) {
			d[i][j] = mind[i-1][j-1] + j * x[i];
			mind[i][j] = min(d[i][j], mind[i-1][j]);
		}
	}
	return mind[n][k];
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
