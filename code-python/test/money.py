money=input("")

if money[0:3] in ["RMB","rmb"]:
    
    d=eval(money[3:])/6.78
    print("USD{:.2f}".format(d))
elif money[0:3] in ["USD","usd"]:
    u=eval(money[3:])*6.78
    print("RMB{:.2f}".format(u))