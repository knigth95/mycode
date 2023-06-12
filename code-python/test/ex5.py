
a,b=eval(input())
BMI=b/a/a
print("BMI数值为:{:.2f}".format(BMI))
print("BMI指标为:",end='')
if(BMI<18.5):
    print("国际'偏瘦',",end='')
elif(BMI<25 and BMI>=18.5):
    print("国际'正常',",end='')
elif(BMI>=25 and BMI<30):
    print("国际'偏胖',",end='')
elif(BMI>=30):
    print("国际'肥胖',",end='')
if(BMI<18.5):
    print("国内'偏瘦'")
elif(BMI<24 and BMI>=18.5):
    print("国内'正常'")
elif(BMI>=24 and BMI<28):
    print("国内'偏胖'")
elif(BMI>=28):
    print("国内'肥胖'")