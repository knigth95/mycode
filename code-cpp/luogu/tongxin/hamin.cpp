#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

bool judge(int str_a[], int r[]) {
    if (str_a[6] == r[0] && str_a[5] == r[1] && str_a[3] == r[2])
        return true;
    else
        return false;
}

int func(int str_a[], int r[]) {
    int i=0;
    if (str_a[6] != r[0] && str_a[5] != r[1] && str_a[3] == r[2]) i=1;

    else if (str_a[6] != r[0] && str_a[5] == r[1] && str_a[3] != r[2]) i=2;

    else if (str_a[6] == r[0] && str_a[5] != r[1] && str_a[3] != r[2]) i=3;
    return i;
}


int main() {
  char stra[11] ,str[11];
  int r[11], a[11]={0},cnt=3;
  cout << "信息位为:"; // 4位
  cin >> stra;

  for (int i = 0; i <4; i++){
    a[i] = int(stra[cnt]) - 48;
    cnt--;
  }
  cout << "你输入的汉明码为:";
  
  cin >> str;
  int str_a[11];
  for (int i = 0; i < 7; i++){
    str_a[i] = int(str[i]) - 48;
  }
  cout<<endl;
  
  // int str[0]=atoi(str);
  //  cout<<a[3]<<" "<<a[2]<<" "<<" "<<a[1]<<" "<<a[0]<<endl;
  r[2] = a[3] ^ a[2] ^ a[1];
  r[1] = a[3] ^ a[2] ^ a[0];
  r[0] = a[3] ^ a[1] ^ a[0];
  cout << "监督位:" << r[2] << r[1] << r[0] << endl;
  //cout << a[3] << a[2] << a[1] << endl;
  judge(str_a, r);
  
  if (judge(str_a, r))
    cout << "输入正确!" << endl;
  else {
    cout << "输入不正确!" << endl;
    printf("信息位第%d位输入错误!\n", func(str_a, r));

    }
    printf("正确汉明码为:");
    //cout<<str_a[6]<<r[0]<<endl;
    //cout<<endl;
    cout << a[3] << a[2] << a[1] << r[2] << a[0] << r[1] << r[0] << endl;
    return 0;
}