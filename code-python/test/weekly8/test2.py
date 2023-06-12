s=input()
try:
    if(complex(s)==complex(eval(s))):
        print(eval(s)**2)
except:
    print("输入有误")