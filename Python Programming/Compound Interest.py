def CompInt(p, r, t):
    TA= p*pow((1+r/100),t)
    comp=TA-p
    return comp

def main():
    p= int(input("Principal: "))
    r= int(input("Rate: "))
    t= int(input("Time= "))

    print(CompInt(p, r, t))

if __name__=="__main__":
    main()