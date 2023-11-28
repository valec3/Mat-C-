import math

def find_index(n):
    if n == 1 :
        return 1
    if n == 2:
        return 3
    if n == 3:
        return 4
    fib = round((math.pow((1 + math.sqrt(5)) / 2, round(math.log(n * math.sqrt(5) + 0.5) / math.log((1 + math.sqrt(5)) / 2))) - math.pow(1 - (1 + math.sqrt(5)) / 2, round(math.log(n * math.sqrt(5) + 0.5) / math.log((1 + math.sqrt(5)) / 2)))) / math.sqrt(5))
    if fib == n:
        return index
    else:
        return -1  # n is not a Fibonacci number

n = int(input())
index = find_index(n)
print(index)
