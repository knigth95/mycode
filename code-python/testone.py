a=1
b=2
s=0
for i in range(1,20):
    s=s+a/b
    c=a
    b=a+b
    a=a+c
print('Sum=%.2f'%s)