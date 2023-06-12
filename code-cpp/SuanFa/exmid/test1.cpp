#include <stdio.h>
#define p 998244353
long long a[10];
int main()
{
	int t, n;
	scanf("%d", &t); 
	while (t--) {
		for (int i = 0; i < 10; i++)
			scanf("%lld", &a[i]);
		scanf("%d", &n);
		for (int i = 10; i < n; i++) {
			long long sum = 0;
			for (int j = 1; j <= 10; j++)
				sum = (sum + j*a[(i-j)%10]) % p;
			a[i%10] = sum * sum % p;
		}
		printf("%lld\n", a[(n-1)%10]);
	}
	return 0;
}
