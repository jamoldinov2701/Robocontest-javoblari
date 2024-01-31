a=int(input())
c=0
b=0
d=-1
e=0
for i in str(a):
    b+=1
    #print(b)
for j in range(1,b+1):
    #print(b)
    e=int(str(a)[d+1])
    d+=1
    if e==0:
        c+=6
    if e==1:
        c+=2
    if e==2:
        c+=5
    if e==3:
        c+=5
    if e==4:
        c+=4
    if e==5:
        c+=5
    if e==6:
        c+=6
    if e==7:
        c+=3
    if e==8:
        c+=7
    if e==9:
        c+=6
print(c)