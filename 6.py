n=int(input())
x=""
if n<10:
  x="000"
elif n<100:
  x="00"
elif n<1000:
  x="0"
if n%400==0 or n%4==0 and n%100!=0:
    x=f"12/09/{x+str(n)}"
else:
    x=f"13/09/{x+str(n)}"
print(x)