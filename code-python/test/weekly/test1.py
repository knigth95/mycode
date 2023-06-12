f=open("latex.log")
s,c=0,0
for line in z:
    line=line.strip("\n")
    if line=='':
        continue
    s=s+len(line)
    c=c+1
print(round(s/c))