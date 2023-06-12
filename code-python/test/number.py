number=("零","一","二","三","四","五","六","七","八","九")
i=input("")
for c in i:
    b=eval(c)
    print(number[b],end="")#单单print默认换行
    