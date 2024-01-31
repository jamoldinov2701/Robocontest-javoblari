t = int(input())
s = 0
l = []
for x in range(t):
  n = int(input())
  s = n**2
  l.append(s % 1000000007)
for i in l:
	print(i)