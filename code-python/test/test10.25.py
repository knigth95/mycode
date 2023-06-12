def cmu(a,*b):
    m=a
    for i in b:
        m=m*i
        return m
printf(eval(cmu(a,*b)))