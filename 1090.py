a = int(input())
b = list(map(int, input().split()))
s = 0

for x in b:
    s += x  

if a >= 5:
    print("%.5f" %((s - (min(b) + max(b))) / (a-2)))
else:
    print(round(s/a))