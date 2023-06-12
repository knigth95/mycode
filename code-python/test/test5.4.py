import random
def passwd(length):
    return random.randint(0,10**(length)-1)+10**(length-1)
length = eval(input())
random.seed(17)
for i in range(3):
    print(passwd(length))