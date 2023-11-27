n = int(input())
arr = list(map(int, input().split()))
pair = int(input())

for x in arr:
    if x % 2 == pair:
        print(x, end=' ')