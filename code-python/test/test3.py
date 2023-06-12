''''
def dayup(ab):
    dayor=1.0
    for i in range(365):
        if(i%7) in [6,0]:
            dayor=dayor*(1-0.01)
        else:
            dayor=dayor*(1+ab)
    return dayor

ab=0.01
while dayup(ab)<37.78:#每天都努力的365模式为37.78
    ab=ab+0.001
print("工作日的努力参数是:{: .3f}".format(ab))

a=eval(input())#返回数值（可整数或浮点）
print("{:-^20}".format(pow(a,3)))
'''

'''
n=int(input())
for i in range(1,n+1,2):#range里是小于，所以要+1
    print("{0:^{1}}".format("*"*i,n))#对引导的槽进行格式化，现在是对0槽{1}是占位符的大小，如果format里有数字就会代入
'''
str = input()
t = ""
for c in str:
    if 'a' <= c <= 'z': 
        t += chr( ord('a') + ((ord(c)-ord('a')) + 3 )%26 )
    elif 'A' <= c <= 'Z':
        t += chr( ord('A') + ((ord(c)-ord('A')) + 3 )%26 )
    else:
        t += c
print(t)