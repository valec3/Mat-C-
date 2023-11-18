n = int(input())
sumDigits = 0
def sum_digits(n):
    sum_d = 0
    while n > 0:
        sum_d += n % 10
        n //= 10
    return sum_d

if n <= 9:
    sumDigits = n*(n+1)//2
else:
    sumDigits = 45
    groups_extra = (n-9)//10
    rest_digits = (n-9)%10
    
    sumDigits += groups_extra*45
    for i in range(rest_digits):
        sumDigits += i
while sumDigits > 9:
    sumDigits = sum_digits(sumDigits)

print(sumDigits)