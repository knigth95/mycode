#include <bits/stdc++.h>
using namespace std;


int main(){
    char xinxi[101];
    int cnt=0,n=0,i;
    for(i=0;xinxi[i]!='\0';i++) {
        cin>>xinxi[i];
        n=i;
    }
    for (i = 0; i < n; i++) {
      if (xinxi[i] == '1'){
            cnt++;
      }
    }
    cout<<cnt<<endl;
    if (cnt % 2 == 0) {
      cout << "偶校验：";
      for (i = 0; i < n; i++) {
        cout << xinxi[i] << " ";
      }
      cout << '0' << endl;
    } else {
      cout << "偶校验：";
      for (i = 0; i < n; i++) {
        cout << xinxi[i] << " ";
      }
      cout << '1' << endl;
    }
    return 0;
}