a = list(map(int,input().split(".")))
s = 0
for x in a:
  if x<=255:
    s+=1
if s==len(a):
  print("YES")
else:
  print("NO")