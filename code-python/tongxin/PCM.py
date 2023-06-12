n=eval(input())
ma=[]
duanluoma={0,16,32,64,128,256,512,1024}

if n>0 :
   ma.append(1)
else :
    n=0-n
    ma.append(0)
if 0<=n<16:
    ma.append(0)
    ma.append(0)
    ma.append(0)
    cnt=16
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
elif 16<=n<32:
    ma.append(0)
    ma.append(0)
    ma.append(1)
    n=n-16
    cnt=32
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
elif 32<=n<64:
    ma.append(0)
    ma.append(1)
    ma.append(0)
    n=n-32
    cnt=64
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
elif 64<=n<128:
    ma.append(0)
    ma.append(1)
    ma.append(1)
    n=n-64
    cnt=128
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
elif 128<=n<256:
    ma.append(1)
    ma.append(0)
    ma.append(0)
    n=n-128
    cnt=256
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
elif 256<=n<512:
    ma.append(1)
    ma.append(0)
    ma.append(1)
    n=n-256
    cnt=512
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
elif 512<=n<1024:
    ma.append(1)
    ma.append(1)
    ma.append(0)
    n=n-512
    cnt=1024
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)
else:
    ma.append(1)
    ma.append(1)
    ma.append(1)
    n=n-1024
    cnt=1024
    for i in range(4):
        cnt=cnt/2
        if n>=cnt:
            ma.append(1)
            n=n-cnt
        else : ma.append(0)         
print(ma)    