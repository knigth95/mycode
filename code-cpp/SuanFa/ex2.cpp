#include <bits/stdc++.h>
using namespace std;

int a(int n) {
    if (n <= 3) return (n < 3 ? 0 : 1);
    return a(n / 2) + a((n + 1) / 2);
}
int main() {
    int n;
    while (cin >> n){
        clock_t time1=clock();
        cout << a(n) << endl;
        clock_t time2=clock();
        printf("花费时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
        //这个宏的单位为秒,要ms需要乘1000,除以这个宏可以跨平台使用
    }
    return 0;
}