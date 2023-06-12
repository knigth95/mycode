'''
t=int(input())
str1="Hello World"
if t==0:
    print(str1)
elif t>0:
    for i in range(0,len(str1),2):
        print(str1[i:i+2])
else:
    for j in str1:
        print(j)

s=input()
sum=eval(s)
print("{:.2f}".format(sum))
'''
s=input()
ls=s.split("-")
print("{}+{}".format(ls[0], ls[-1]))