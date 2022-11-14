from myMathMath import *

class Person:
    count=0

    def __init__(self, name, age):
        self.name=name
        self.age=age
        Person.count+=1

    def display(self):
        print("My name is "+self.name)

class Shape:
    def __init__(self, x, y):
        self.x=x
        self.y=y
        

class Square(Shape):
    def __init__ (self, side=1, x=0, y=0):
        super().__init__(x,y)
        self.side=side
    def area(self):
        return self.side*self.side
class Circle(Shape):
    def __init__(self, r=1, x=0, y=0):
        super().__init__(x,y)
        self.r=r


sq=Square(2, 3, 4)
print(sq.area())

print(pi)
print(__doc__)
    

