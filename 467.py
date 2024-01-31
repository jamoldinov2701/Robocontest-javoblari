a , b = map(int, input().split())
if b%2==1:
  print(-1)
else:
  print(a+1+b//2)