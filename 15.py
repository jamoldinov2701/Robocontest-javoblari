n,k = map(int, input().split())
m = 1000000007
if n == 0:
    print(0)
else:
    print((pow(k, n, m) - 1) * pow(k - 1, m - 2, m) % m)