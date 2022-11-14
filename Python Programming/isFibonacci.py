import math

def isPerfectSqr(n):
    s=int(math.sqrt(n))
    if s*s==n:
        return 1


def isFib(n):
    return isPerfectSqr(5*n*n +4) or isPerfectSqr(5*n*n -4)


def main():
    n= int(input("Enter:\n"))
    if(isFib(n)==True):
        print("Fib")
    else:
        print("Not fib")

if __name__=="__main__":
    main()