a = int(input())
h = a // 3600
m = (a % 3600) // 60
s = (a % 3600) % 60
x = "0"
print(f"{h%24}:{(x+str(m),m)[m>=10]}:{(x+str(s),s)[s>=10]}")