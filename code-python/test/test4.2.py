sum = 0
for i in range(2,100):
    for k in range(2,i):
        if i % k == 0:
            break
    else:                  
            sum += i
print(sum)