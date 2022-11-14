import csv
import os
import re


f= open("hello.txt")

print("Filename: ", f.name)
print("Mode: ", f.mode)
print("F closed: ", f.closed)
  
print(f.read(6))
print(f.read(5))
print(f.read())
print(f.tell())
f.seek(0)
print(f.read())

with open("test.txt", "w+") as m:
    m.write("Hello\n")
    m.write("My name is\n")
    m.write("Anika\n")

lst=[]
with open("Pat.txt", "r") as a:
    for line in a:
        lst.append(line)

dict={}

for i in range(len(lst)):
    temp=[]
    temp=lst[i].split(" ")
    dict[temp[0]]= temp[1:5]

for i in dict:
    print(i, dict[i])


"""nd=os.mkdir("NewDir")
l= os.listdir()

if "NewDir" in l:
    print("Created")
else:
    print("Not present")"""

p= "C://Users//Anika Shukla//OneDrive//Desktop//Python//NewDir"

l= os.listdir(p)

for i in l:
    print(i)

for i in dict:
    temp=[]
    temp=dict[i]
    for a in temp:
        if(re.search("^#", a)!=None):
            print(temp)
            dict.pop(i)

print(dict)
        
line= "Anika_Shukla_Hello"

num=re.sub("*_", " ", line)
print(num)
