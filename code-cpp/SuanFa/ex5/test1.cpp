#include <bits/stdc++.h>      
using namespace std;

// 题目中给出的最大宽度和高度
#define MAX_W 20
#define MAX_H 20
// 待输入的宽度和高度以及已走的步数
int W, H;     
int step = 0;
// 待写入的二维数组
char room[MAX_W][MAX_H];
// 顺时针的可走方向
const int direc[4][2] = {
    {0, -1},
    {1,0},
    {0, 1},
    {-1 ,0},
};
int dfs(const int& row, const int& col) {
    // 走过的点
    room[row][col] = '#';
    // 计算步数
    ++step;
    for (int d = 0; d < 4; ++d) {
        int curRow = row + direc[d][1];
        int curCol = col + direc[d][0];
        if (curRow >= 0 && curRow < H && curCol >= 0 && curCol < W && room[curRow][curCol] == '.') {
            dfs(curRow, curCol);
        }
    }

    return step;
}

int main()
{
    bool found;
    while (cin >> W >> H, W > 0) {
        if(W==0 && H==0) return 0;
        step = 0;
        int col, row;
        // 输入

        for (row = 0; row < H; ++row) {
            for (col = 0; col < W; ++col) {
                cin >> room[row][col];
            }
        }
        clock_t time1=clock();
        found = false;
        // 找到起始点
        for (row = 0; row < H; ++row) {
            for (col = 0; col < W; ++col) {
                if (room[row][col] == '@') {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }                   
        }
        // 开始搜索
        cout << dfs(row, col) << endl;
        clock_t time2=clock();
        printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    }
}