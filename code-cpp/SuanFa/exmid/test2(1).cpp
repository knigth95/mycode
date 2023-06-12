#include <algorithm>
#include <iostream>
using namespace std;
long long x[100000];
int main()
{
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> x[i];
		sort(x, x + n);
		long long ans = 0;
		for (int i = 0; i < k; i++)
			ans += x[i] * (k-i);
		cout << ans << endl;
	};
	return 0;
}
