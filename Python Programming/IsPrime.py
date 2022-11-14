def isPrime(n):
    if(n>1):
        for i in range(2, int(n/2)+1):
            if(n%i==0):
                print("Not a prime")
                break
        else:
            print("Prime")
    else:
        print("Not a prime")


def main():
    n= int(input("Enter the number: \n"))
    x= isPrime(n)

    #if(x==0):
       # print("Not a prime")
    #elif(x==1):
    #    print("Prime")
            
            
if __name__=="__main__":
    main()