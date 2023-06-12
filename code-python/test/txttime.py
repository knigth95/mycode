import time
from tracemalloc import start
scale=50
print("------执行开始------".center(scale//2,"-"))
start=time.perf_counter()
for i in range(scale+1):
    a="*"*i
    b="."*(scale-i)
    c=(i/scale)*100
    d=time.perf_counter()-start
    print("{:^3.0f}%[{}->{}]".format(c,a,b,d),end="")
    time.sleep(0.1)
print("\n"+"-----执行结束-----".center(scale//2,"-"))