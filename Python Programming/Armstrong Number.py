def number(n):
    N=n 
    count=0
    while(N!=0):
        N=N//10
        count=count+1
    return count

def isArmstrong(n):
    sum=0
    N=n
    x=number(n)
    while(N!=0):
        rem=N%10

        
        sum= sum + pow(rem, x)
        N=N//10
    
    return 1 if(sum==n) else 0

def main():
    n=int(input("Enter the number: \n"))

    if(isArmstrong(n)==1):
        print("It is an Armstrong Number\n")
    else:
        print("Not an Armstrong Number\n")


if __name__=="__main__":
    main()