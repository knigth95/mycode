#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int  a[100], c = 0, d = 0, i, n, t;
 scanf("%d", &n);
 while (n > 0) {
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
   cin>>a[i];
  }
  for (i = 0; i < t; i++) {
   if (a[i]%2 == 0) {
        c+=a[i];
   }
   else {
    d = d + a[i];
   }
  }
  printf("%d %d\n", d, c);
  d = 0, c = 0;
  n--;
 }
 return 0;
}