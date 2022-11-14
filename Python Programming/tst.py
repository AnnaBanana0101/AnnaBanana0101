a=input()
Anika Hi bye no
>>> a.split(" ")
['Anika', 'Hi', 'bye', 'no']

lst = []
>>> lst = a.split(" ")
>>> lst[0]
'Anika'

count=0
>>> for i in range (len(lst)):
	if len(lst[i])>2:
		if(lst[i][0]==lst[i][-1]):
			count=count+1
