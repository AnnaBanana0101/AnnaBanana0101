def Prime(x, y):
    list= []
    while(y>x):
        for n in range(x,y):
            if n==0 or n==1:
                continue
            else:
                for i in range (2, int(n/2)+1):
                    if(n%i==0):
                        break
                else:
                    list.append(n)

    return list


def main():
    #print("Enter the range: \n")
    #x= int(input())
    #y= int(input())

    print("The prime numbers in the range:\n")
    lst= Prime(1,10)
    print(lst)

if __name__=="__main__":
    main()