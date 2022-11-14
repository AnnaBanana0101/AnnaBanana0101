from collections import Counter
from itertools import combinations

data=[
        ['T100',['I1','I2','I5']],
        ['T200',['I2','I4']],
        ['T300',['I2','I3']],
        ['T400',['I1','I2']],
        ['T500',['I1','I3']],
        ['T600',['I2','I3']],
        ['T700',['I1','I3']],
        ['T800',['I1','I3','I5']],
        ['T900',['I1','I2','I3']]
]

init=[]

for i in data:
    for q in i[1]:
        if(q not in init):
            init.append(q)
init=sorted(init)
print(init)

support=0.4
minsup=int(support*len(init))
c=Counter()

for i in init:
    for d in data:
        if(i in d[1]):
            c[i]+=1
print("C1:")

for i in c:
    print(str([i])+": "+str(c[i]))
print()

l= Counter()

for i in c:
    if(c[i]>=minsup):
        l[frozenset([i])]=c[i]
print("L1:")

for i in l:
    print(str(list(i))+": "+str(l[i]))
print()

#print(list(l))

pl=l
pos=1

for count in range(2,1000):
    nc=set()
    temp= list(l)
    #print(temp)

    for i in range(0, len(temp)):
        for j in range(i+1, len(temp)):
            t= temp[i].union(temp[j])
            if(len(t)==count):
                nc.add(t)
    nc=list(nc)

    c= Counter()

    for i in nc:
        for d in data:
            if(i.issubset(d[1])):
                c[i]+=1
    print("C"+str(count)+":")

    for i in c:
        print(str(list(i))+": "+str(c[i]))
    print() 

    l= Counter()

    for i in c:
        if(c[i]>=minsup):
            l[i]=c[i]
    print("L"+str(count)+":")

    for i in l:
        print(str(list(i))+": "+str(l[i]))
    print()

    if(len(l)==0):
        break
    else:
        pl=l
        pos=count

print("Result: ")
print("L"+str(pos)+": ")

for i in pl:
    print(str(list(i))+": "+str(pl[i]))
print()

for l in pl:
    c= [frozenset(q) for q in combinations(l, len(l)-1)]
    
    for a in c:
        b= l-a
        ab=l
        sa=0
        sb=0
        sab=0

        for q in data:
            temp = set(q[1])
            if(a.issubset(temp)):
                sa+=1
            if(b.issubset(temp)):
                sb+=1
            if(ab.issubset(temp)):
                sab+=1
            
        conf=(sab/sa)*100

       
        print(str(list(a))+" -> "+str(list(b))+" = "+str(sab/sa*100)+"%")
        if(conf>=50):
            print("Chosen")
        else:
            print("Not chosen")

        conf=(sab/sb)*100
        print(str(list(b))+" -> "+str(list(a))+" = "+str(sab/sb*100)+"%")
        if(conf>=50):
            print("Chosen")
        else:
            print("Not chosen")  
print()
print()






