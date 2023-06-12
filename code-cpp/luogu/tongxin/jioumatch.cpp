#include <bits/stdc++.h>
using namespace std;

//返回对应的编码中1出现的次数
int getTimes(int num) {
    int cnt = 0;
    int count;
    while (num) {
        count=num%10;
        num/=10;
        //num = num & (num - 1);
        if(count == 1) cnt++;
    }
    return cnt;
}

//奇校验: 当 1 出现的次数为奇数时候在最后面加上 0，否则加 1
void ji_Check(char *str, int times) {
    times & 1 ? strcat(str, "0") : strcat(str, "1");
}

//偶校验：与奇校验相反
void ou_Check(char *str, int times) {
    times & 1 ? strcat(str, "1") : strcat(str, "0");
}

int main() {
    string code;
    char jianyan1[101],jianyan2[101];
    cout<<"输入编码:";
    cin>>code;
    //string转int
    int num=atoi(code.c_str());
    //取得num对应的二进制中1出现的次数
    int times = getTimes(num);
    char str1[101],str2[101]; //存字符串,奇、偶
    //string转char[]
    strcpy(str1,code.c_str());
    strcpy(str2, code.c_str());
        // cout<<sprintf(str,"%d",num)<<endl;
        printf("1出现的个数 : %d\n", times);
    printf("初始编码 : %s\n", str1);
    //奇校验
    ji_Check(str1, times);
    cout<<"请输入奇校验码:";
    cin>>jianyan1;
    if(!strcmp(str1,jianyan1))
        cout<<"正确!"<<endl;
    else cout<<"错误!"<<endl;
    printf("正确的奇校验码 : %s\n", str1);
    
    //偶校验
    ou_Check(str2, times);
    cout << "请输入偶校验码:";
    cin >> jianyan2;
    if (!strcmp(str2, jianyan2))
      cout << "正确!" << endl;
    else
      cout << "错误!" << endl;
    printf("正确的偶校验码: %s\n",str2);
    return 0;
}
