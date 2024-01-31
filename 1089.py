a = [1_000_000_000, 1_000_000, 1_000, 100]
b = ["milliard ","million ", "ming ", "yuz "]
c = ["", "o'n ", "yigirma ", "o'ttiz " , "qirq ", "ellik ", "oltmish ", "yetmish ", "sakson ", "to'qson "]
d = ["", "bir ", "ikki ", "uch ", "to'rt ", "besh ", "olti ", "yetti ", "sakkiz ", "to'qqiz "]

def say(n):  
    for i in range(4):
      if n >= a[i]:
        return say(n // a[i]) + b[i] + say(n % a[i])
    return c[n // 10] + d[n % 10]

print(say(int(input())))