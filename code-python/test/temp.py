#temstr=input("请输入带有符号的温度值：")
temstr=input("")
#字符串序号：
#正向递增：由左向右，从0开始
#反向递减：由右向左，从-1开始
#索引：返回字符串中单个字符   <字符串>[M]
    #"请输入带有符号的温度值:"[0] 或 temstr[0:-1]
#切片：返回字符串中一段字符的子串  <字符串> [M:N]
   #"请输入带有符号的温度值:"[1:3] 或者 temstr[0:-1]
if temstr[0] in ['F','f']:
    #[]为列表，in判断元素是否在列表中
    c=(eval(temstr[1:])-32)/1.8
    print("C{:.2f}".format(c))
    #eval()去掉参数最外侧引号并执行余下语句的函数
    #print("转换后的温度是{:.2f}C".format(c))
elif temstr[0] in ['C','c']:
   
    f=1.8*eval(temstr[1:])+32
    print("F{:.2f}".format(f))
    #print("转换后的温度是{:.2f}F".format(f))
    #{}表示槽，后续变量填充到槽中，此语句中表示将c填充到这个位置是取小数点后两位
    
else:
    print("输入格式错误")