n = int(input())
a = sorted([int(x) for x in input().split()])
 
d = [0] * (n + 1)
d[2] = a[1] - a[0]
if n > 2:
    d[3] = a[2] - a[0]
for i in range(4, n + 1):
    d[i] = min(d[i - 1], d[i - 2]) + a[i - 1] - a[i - 1 - 1]
 
print(d[n])