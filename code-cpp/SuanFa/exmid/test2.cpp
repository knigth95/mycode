#include <bits/stdc++.h>
using namespace std;

const int EquNum(4);
// 已知准确解是 x[0~3]=(0.1, 0.8, 0.5, 0.6)
double fL1(double *x)
{
    double l = x[0] * 2 + x[1];
    double r = 1;
    return (l - r) * (l - r) / (l * l + r * r);
}

double fL2(double *x)
{
    double l = 3.0 * asin(x[2]);
    double r = 2.0 * atan((x[2] + x[3]) / (x[0] * 3 + x[1]));
    return (l - r) * (l - r) / (l * l + r * r);
}
double fL3(double *x)
{
    double l = (x[0] + x[1] + x[2] + x[3]) / 4;
    double r = 0.5;
    return (l - r) * (l - r) / (l * l + r * r);
}
double fL4(double *x)
{
    double l = x[1] * x[1] + x[3] * x[3];
    double r = 1.0;
    return (l - r) * (l - r) / (l * l + r * r);
}
double Evaluate(double *x)
{
    return fL1(x) + fL2(x) + fL3(x) + fL4(x);
}
void Output(double *x, int sn, double step)
{
    printf("sn=%d,step=%f, x[0~3]=%f,%f,%f,%f, ", sn, step, x[0], x[1], x[2], x[3]);
    printf("Err=%.7f\n", Evaluate(x));
}

int main()
{
    double err, minerr = 12345;
    double initstep(0.01), step(0.01);
    double dx[EquNum], bestx[EquNum], xprev[EquNum];
    double x[4] = {0.5, 0.5, 0.5, 0.5};
    int sn(0), mm(0), TotalSteps(500); // 迭代步数,失败搜索上限,步数上限
    double epsilon = 1e-6;
    srand(1000);
    //
    clock_t time1 = clock();
    printf("================ Initial value ================\n");
    Output(x, 0, 1.0);
    //
    printf("================ Iterative value ================\n");
    bool success;
    while (minerr > epsilon && step >= epsilon && sn < TotalSteps)
    {
        int rr;
        do
        {
            rr = 0;
            for (int i = 0; i < EquNum; i++)
            {
                dx[i] = rand() - 16384;
                rr += dx[i] * dx[i];
            }
        } while (rr >= 16384 * 16384);
        // 保证各向同性
        rr = sqrt((double)rr);
        for (int i = 0; i < EquNum; i++)
            dx[i] *= step / rr;
        // 包含归一化
        for (int i = 0; i < EquNum; i++)
            x[i] += dx[i];
        err = Evaluate(x);
        if (err < minerr)
        {
            minerr = err;
            sn++;
            step = min(0.1, step * 2);
            // 成功,步长扩大
            for (int i = 0; i < EquNum; i++)
                xprev[i] = x[i] - dx[i];
            mm = 0;
            Output(x, sn, step);
        }
        else
        {
            mm++;
            for (int i = 0; i < EquNum; i++) // 失败,不前进
                x[i] -= dx[i];
            if (mm > 50)
            {
                for (int i = 0; i < EquNum; i++) // 连续失败 50 次,退回到前一点继
                    x[i] = xprev[i];
                minerr = Evaluate(xprev);
                mm = 0;
                step = max(1e-5, step / 2.5); // 连续失败 50 次,步长缩小
            }
        }
    }
    printf("\n");
    printf("%d rounds complete normally.\n", sn);
    printf("The solution is (%f, %f, %f, %f).\n", x[0], x[1], x[2], x[3]);
    printf("Error=%.8f\n", minerr);
    clock_t time2 = clock();
    printf("运行时间为：%.10lfms   21211835102+曾振铭\n",(double)(time2-time1)/(double)CLOCKS_PER_SEC*1000);
    return 0;
}