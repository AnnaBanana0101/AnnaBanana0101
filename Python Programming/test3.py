import sqlite3

conn=sqlite3.connect("hello.txt")

curr=conn.cursor()

curr.execute("create table Table(Name text, Age integer)")
curr.execute("Insert into Table values(?,?)", ("Anika",20))
curr.executes("Insert into Table values(:Name, :Age)", ("ABCD", 20))

query=curr.execute("select * from Table")
for row in query:
    print(row)