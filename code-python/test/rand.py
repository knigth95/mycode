from random import random, seed
from time import perf_counter

from matplotlib.pyplot import hist


dart=eval(input())
seed(123)
hits=0.0
start=perf_counter()
for i in range(1,dart+1):
    x,y=random(),random()
    dis=pow(x**2+y**2,0.5)
    if dis<=1.0:
        hits=hits+1
pi=4*(hits/dart)
print("{:.6f}".format(pi))

