def SimpInt(p, r, t):
    if(p<0 or t<0):
        return 0
    else:
        simp= (p*r*t)/100
        return simp
    
def Main():
    print("Enter the details:\n")
    p= int(input("Principal: "))
    r= int (input("Rate: "))
    t= int(input("Duration in years: "))

    print(SimpInt(p,r,t))
    print("\nTotal Amount= ", SimpInt(p,r,t)+p)

if __name__=="__main__":
    Main()
