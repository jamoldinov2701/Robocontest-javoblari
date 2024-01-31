def sumdigit(n):
  s=0
  for i in str(n):
    s+=int(i)
  return s

def f(n):
  return n % (sumdigit(n) ** 2)==0

n=int(input())
i,l= 1,0
while l<n:
  l+=1 if f(i) else 0
  i+=1 if l !=n else 0
print(i)