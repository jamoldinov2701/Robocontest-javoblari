n = int(input())
for x in str(n):
    if int(x) % 2 == 0 or len(str(n)) % 2 == 0:
        print("NO")
        break
else:
        print("YES")