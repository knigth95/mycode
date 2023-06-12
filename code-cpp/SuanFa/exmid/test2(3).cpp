#include <algorithm>
#include <iostream>
using namespace std;

int n, k;
#define NN 100000
long long x[NN+1], sum[NN+1], g[NN+1];

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			sum[i] = sum[i-1] + x[i];
		}
		g[1] = 0;
		for (int j = 1; j <= k; j++)
			g[1] += j*x[j];
		for (int i = 2; i <= n-k+1; i++)
			g[i] = g[i-1] + k*x[i+k-1] - sum[i+k-2] + sum[i-2];
		cout << *min_element(g+1, g+n-k+2) << endl;
	};
	return 0;
}
