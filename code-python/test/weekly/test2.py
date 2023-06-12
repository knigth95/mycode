f=open("data.csv")
ls=f.readlines()
ls=ls[::-1]
lt=[]
for item in ls:
    item=item.strip("\n")
    item=item.replace(" ","")
    lt=item.split(",")
    lt=lt[::-1]
    print(";".join(lt))
f.close()