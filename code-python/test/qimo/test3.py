s=input()
try:
    dict_1=eval(s)
    dict_2=dict(zip(dict_1.values(),dict_1.keys()))
    print(dict_2)
except:
    print("输入错误")
