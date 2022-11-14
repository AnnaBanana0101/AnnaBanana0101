import re

def PIDException(Exception):
    pass

dict={}
lst=[]

with open("Pat.txt", "r") as f:
    for line in f:
        lst.append(line)

for i in lst:
    temp=[]
    temp=i.split(" ")
    dict[temp[0]]= temp[1:5]

for i in dict:
    print(i, dict[i])
remove=[]
for i in dict:
    temp=[]
    temp=dict[i]
    for a in temp:
        if(re.search("^#", a)!= None):
            print("Remove:")
            print(i, dict[i])
            remove.append(i)

for i in dict:
    temp=[]
    temp=dict[i]
    for a in temp:
        if(re.search("#$", a)!=None):
            print("Removed:")
            print(i, dict[i])
            remove.append(i)
            
dict2={}

for i,values in dict.items():
    if i not in remove:
        dict2[i]=values

print("Dictionary 2: ")

for i in dict2:
    print(i, dict2[i])

try:
    
    for i in dict:
        if(re.search("[0-99]PID[0-99]",i)==None):
            print("Removed: ")
            print(i, dict[i])
            remove.append(i)
            raise PIDException
except:
    print("InvalidPIDError")
finally:
    print("Moving on")
        
        
        
        

dict3={}

for i, val in dict.items():
    if i not in remove:
        dict3[i]=val
        
print("Dictonary 3: ")
for i in dict3:
    print(i, dict3[i])
    
           
line= "Anika_Shukla_Hello"

num= re.sub("_", " ", line)
print(num)

with open("PatClean.txt", "w+") as a:
    for i in dict3:
        a.write(str(i)+": "+str(dict3[i])+"\n")
    
