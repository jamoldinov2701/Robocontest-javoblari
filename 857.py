a=str(input())
s=0
d=0
for i in a:
    s +=1
    d+=int(i)
if s==9 and d%2!=0:
    print('yes')
else:
    print('no')