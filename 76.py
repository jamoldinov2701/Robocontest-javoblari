a = map(int,input().split())
b = int(input())
s = 0
for x in a:
  s+=x
if b==s or s>b:
  print(0)
else:
	print(b-s)