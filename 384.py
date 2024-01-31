a = int(input())
one = a // 100
two = (a % 100) // 20
three = ((a % 100) % 20) // 10
four = (((a % 100) % 20) % 10) // 5
five = ((((a % 100) % 20) % 10) % 5) // 1
print(one + two + three + four + five)