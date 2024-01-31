a,b=map(int,input().split())
perimetr = (a + b) * 2
yuza = a * b
if perimetr>yuza:
  print(perimetr)
else:
  print(yuza)