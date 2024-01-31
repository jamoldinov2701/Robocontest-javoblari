a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
y1 = a * 3600 + b * 60 + c
y2 = d * 3600 + e * 60 + f
print(y2 - y1)