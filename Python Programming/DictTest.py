print("Enter the number of students:\n")

n=int(input())

print("Enter the reg nos:\n")
dict={}
lst=[]
for i in range(n):
    lst.append(int(input()))
    i+=i

print("Enter the details:\n")
lst2=[]
for j in range(n):
    lst2.append(input().split(","))
    j+=1


for i in range (n):
    dict[lst[i]]=lst2[i]

print(dict)
