code=str(input())
b=0
if code[0]=='1':
    print("+",end='')
else: print("-",end='')
if code[1]=='0'and code[2]=='0'and code[3]=='0':
    a=0
    cnt=4
    num=8
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='0'and code[2]=='0'and code[3]=='1':
    a=16
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='0'and code[2]=='1'and code[3]=='0':
    a=32
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='0'and code[2]=='1'and code[3]=='1':
    a=64
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='1'and code[2]=='0'and code[3]=='0':
    a=128
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='1'and code[2]=='0'and code[3]=='1':
    a=256
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='1'and code[2]=='1'and code[3]=='0':
    a=512
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
if code[1]=='1'and code[2]=='1'and code[3]=='1':
    a=1024
    cnt=4
    num=a/2
    for i in range(4):
        if code[cnt]=='1':
            b=num+b
        num=num/2
        cnt=cnt+1
print(int(a+b+a/32))
