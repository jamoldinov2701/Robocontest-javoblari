numbers = [int(x) for x in input().split()]
min_sum = sum(numbers) - max(numbers)
max_sum = sum(numbers) - min(numbers)
print(min_sum,  max_sum)