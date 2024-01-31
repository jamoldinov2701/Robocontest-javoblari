a, b = map(int, input().split(":"))
q = int(input())
o = "0"
if b + q > 59:
    a = a + 1
    b = (b + q) % 60
else:
    b = b + q
if a > 23:
    a = a % 24
if 9 >= a:
    a = o + str(a)
if 9 >= b:
    b = o + str(b)
print(f"{a}:{b}")
