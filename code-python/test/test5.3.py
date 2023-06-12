def prime(m):
    flag = 0
    for i in range(2,m):
        if m % i == 0:
            flag = 1
            break 
    return flag

n = eval(input())
a = int(n)           
a = a + 1 if a < n else a    #输出一个比n本身要大的整数,
#a=a+1不可写成a+=1,输出会不对???

count = 5   #质数的计数器
t = ""
while count > 0:
    if prime(a) == 0:
        t += "{},".format(str(a))
        count -= 1           #只有是质数方可减一
    a += 1                   #无论是否是质数均加一
print(t[:-1])

