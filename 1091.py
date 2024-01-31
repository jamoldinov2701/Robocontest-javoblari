a,b,c = map(int, input().split())
if a==b==c:
    print(1)
elif a==b>c:
    print(2)
elif a==b<c:
    print(2)
elif a==c>b:
    print(2)
elif a==c<b:
    print(2)
elif c==b<a:
    print(2)
elif c==b>a:
    print(2)
else:
    print(3)