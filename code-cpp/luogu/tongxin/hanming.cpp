#include <bits/stdc++.h>
using namespace std;
//输入二进制数
void in_bin(int bin[]) {
    char binary[100];
    int i = 0;
    printf("请输入要的海明码：");
    scanf("%s", binary);
    while (binary[i]) {
        bin[i + 1] = binary[i] - 48;
        i++;
    }
    bin[0] = i; // bin[0]记录输入的个数
}

//输出二进制数
void out_bin(int bin[]) {
    printf("输入要传送的二进制数：");
    for (int i = 1; i <= bin[0]; i++) {
        printf("%d", bin[i]);
    }
    printf("\n");
}

//输出汉明码位上的数
void out_p(int p[]) {
    printf("汉明码位上的数为：");
    for (int i = 1; i <= p[0]; i++) {
        printf("%d", p[i]);
    }
    printf("\n");
}

//输出汉明码
void out_haiming(int bin[], int p[], int place = 0) {
    printf("汉明码为：");
    int i, n = 1;
    int pp = 1, pb = 1;
    for (i = 1; i <= bin[0] + p[0]; i++)
    if (i == n) {
        printf("%d", p[pp++]);
        n = n * 2;
    } else {
        printf("%d", bin[pb++]);
    }
    cout<<endl;
}

//找到汉明码检测小组中的各个位
int pos(int i) { //找到汉明码检测小组中的各个位
    int c = 0;
    int pos = 2, n = 4;
    while (c < i) {
        pos++;
        if (pos == n)
            n *= 2, c--;
            c++;
    }
    return pos;
}

//计算汉明码检测位上的值
    void in_p(int p[], int bin[]) {
    int i, j;
    p[0] = 1;
    while (1 << p[0] < p[0] + bin[0] + 1)
    p[0]++; //此语句求新增添的检测位的个数：公式->2^k>=n+k+1
            //	<< 左移运算符，
    // 1<<p[0]相当于把1的二进制值左移p[0]位，左移1位相当于乘以2,那么左移n位就是乘以2的n次方了
    //	p[0]记录汉明码的个数；
    //     printf("汉明码个数：%d\n",p[0]);//输出汉明码的个数
    for (i = 1; i < 100; i++)
    p[i] = 0; //初始化
    for (i = 1; i <= p[0]; i++) {
    for (j = 1; j <= bin[0]; j++) {
        //            printf("%d ",pos(j)&(1<<(i-1)));
        //            //确定k位检测位分别安插的代码位的编号
        if (pos(j) & (1 << (i - 1))) {
        //            	printf("%d",j);
        //				printf("%d",pos(j));
        //				printf("%d",1<<(i-1));
        p[i] = (p[i] + bin[j]) % 2;
        // printf("%d",pos(j));
        // printf("%d",j);
        }
        // printf("\n%d",i);
    }
    }
    }

//输入接收到的汉明码
void in_reacice(int r[]) {
  char recive[100];
  int i = 0;
  scanf("%s", recive);
  while (recive[i]) {
    r[i + 1] = recive[i] - 48;
    i++;
  }
  r[0] = i; // r[0]记录输入的二进制数的个数
}

//校验接收到的汉明码是否出错
void checkHanming(int p[], int r[], int q[]) {
    int i, j, k;
    int flag[100];
    int bins[100];
    for (i = 0; i < 100; i++) q[i] = 0; //初始化

    k = 1;
    for (i = 0; i < p[0]; i++) {
        flag[k] = 1 << i;  //记录汉明码检测位的位置
        q[k] = r[flag[k]]; //记录汉明码检测位所在的值
        k++;
        flag[0]++;
        q[0]++;
    }
    int c = 0;
    k = 1;
    bins[0] = 0;
    for (i = 1; i <= r[0]; i++) {
        c = 0;
        for (j = 1; j <= flag[0]; j++) {
            if (i == flag[j]) c = 1;
        }
        if (c == 0) {
            bins[k] = r[i]; //把汉明码的检测位与实际传入的二进制数进行分离
            k++;
            bins[0]++;
        }
    }
    //纠错
    for (i = 1; i <= q[0]; i++) {
        for (j = 1; j <= bins[0]; j++) {
            if (pos(j) & (1 << (i - 1))) {
                q[i] = (q[i] + bins[j]) % 2;
            }
        }
    }
    int y = q[0] - 1;
    int s = 0;
    for (i = q[0]; i > 0; i--) {
        s += (1 << y) * q[i]; //计算最后出现错误的位置
        y--;
    }
    if (s == 0) {
        cout<<"检测未出现错误"<<endl;
    } 
    else {
        printf("汉明码的第%d位出现错误!\n", s);

        if (r[s] == 1) {
            r[s] = 0;
        } else {
            r[s] = 1;
        }
        cout<<"纠错后的汉明码为：";
        for (i = 1; i <= r[0]; i++) {
            cout<<r[i];
        }
        cout<<endl;
    }
}

int main() {
    int bin[100];
    int p[100];
    int r[100];
    int q[100];

    in_bin(bin);
    in_p(p, bin);
    out_bin(bin);
    out_p(p);
    out_haiming(bin, p);
    printf("-----------------------------\n");
    printf("请输入接收到的汉明码：");
    in_reacice(r);
    checkHanming(p, r, q);

    return 0;
}
