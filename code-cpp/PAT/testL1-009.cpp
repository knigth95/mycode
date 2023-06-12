#include<bits/stdc++.h>
using namespace std;
long long gongyue(long long a, long long b){
	if (a == 0)
		return 0;
	else
		return (b == 0) ? a : gongyue(b, a % b);
}
 
int main(){
	int n;
	cin >> n;
	long long int a, b, c, d,small;//最小公约
	scanf("%lld/%lld",&a,&b);
    //千万不要用cin,因为'/'
	small = gongyue(a, b);
	if (a != 0){
		a = a/small;
		b = b/small;
	}
	for (int i = 1; i < n; i++){
        scanf("%lld/%lld",&c,&d);
		small = b / gongyue(b, d)*d;
		a = a * small / b + c * small / d;
		b = small;
		small = gongyue(a, b);
		if (small != 0){
			a = a / small;
			b = b / small;
		}
	}
	if (a && a / b == 0)
		printf("%lld/%lld\n", a%b, b);
	else if (a%b == 0)
		printf("%lld\n", a / b);
	else
		printf("%lld %lld/%lld\n", a / b, a%b, b);
	return 0;
}