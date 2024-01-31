def popcount(x):
    # Ikki sanoq sistemasidagi 1 lar sonini hisoblash
    count = 0
    while x:
        count += x & 1
        x >>= 1
    return count

def qanoatlantirish(n):
    for a in range(max(1, n - 100), n + 1):
        if n == a + popcount(a):
            return a
    return -1

# Kiruvchi ma'lumotni olish
n = int(input())

# Natijani hisoblash va chiqarish
natija = qanoatlantirish(n)
print(natija)