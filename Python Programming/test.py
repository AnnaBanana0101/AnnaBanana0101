
def isUp(str):
    a=[]
    a= list(str)
    print(a)
    up=0
    low=0
    for i in a:
        if i.isupper()==True:
            up=up+1
        elif i.islower()==True:
            low=low+1
    
    print("The number of upper case characters: ")
    print(up)
    print("\nThe number of lower case characters: ")
    print(low)


A=input()
isUp(A)
    
