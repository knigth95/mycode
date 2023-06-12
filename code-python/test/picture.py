import turtle
import random 
turtle.pensize(4)
for i in range(4):
    turtle.seth(90*i)
    turtle.fd(100)
    turtle.right(90)
    turtle.circle(-150,45)
    turtle.goto(0,0)


'''
turtle.pensize(4)
for i in range(9):
    turtle.fd(100)
    turtle.left(80)
'''    
'''
turtle.setup(500,500,300,300)
turtle.penup()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(30)
turtle.pencolor("green")
turtle.seth(-50)#转向，参数为绝对角度，只转向不行动
for i in range(5):
    turtle.circle(40,80)
    turtle.circle(-40,80)
turtle.circle(40,80/2)
turtle.fd(50)
turtle.circle(16,180)#参数：半径，弧度
turtle.fd(40*2/3)
turtle.done()
'''
