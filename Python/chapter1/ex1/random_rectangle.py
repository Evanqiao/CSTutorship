import turtle
import random

num = int(input("How many rectangles? "))
XMAX=400
YMAX=390
for i in range(num):
	p=turtle.Turtle()
	p.hideturtle()
	p.speed("fastest")
	rcolor=random.choice(["grey","blue","yellow","red","black","green"])
	p.pen(pencolor=rcolor,pensize=3)
	x1=random.randrange(-XMAX,XMAX)
	y1=random.randrange(-YMAX,YMAX)
	x2=random.randrange(-XMAX,XMAX)
	y2=random.randrange(-YMAX,YMAX)
	p.penup()
	p.goto(x1,y1)
	p.pendown()
	p.goto(x1,y2)
	p.goto(x2,y2)
	p.goto(x2,y1)
	p.goto(x1,y1)