""""def factorial(n):
    return 1 if (n==0 or n==1) else n*factorial(n-1)"""

def factorial(n):
    fact=1
    if(n==1 or n==0):
        return 1
    else:
        while(n>1):
            fact=fact*n
            n=n-1
        return fact



def Main():
    a= int(input("Enter the number:\n"))
    print(factorial(a))

if __name__=="__main__":
    Main()


