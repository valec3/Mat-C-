# Xornacci
t = int(input())
for i in range(t):
    fn=0
    f0, f1, n = map(int, input().split())
    xr = f0 ^ f1
    if n%3 == 0:
        fn = f0
    elif n%3 == 1:
        fn = f1
    else:
        fn = xr
    print(fn)