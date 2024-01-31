n = int(input())
numbers = list(map(int, input().split()))
unique_number = 0
for num in numbers:
    unique_number ^= num
print(unique_number)