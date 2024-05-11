k, n = map(int, input().split())
d = [0]*(n+1)
d[0] = 1
for i in range(1, n + 1):
    j = 1
    while i - j >=0 and j <= k:
        d[i] += d[i-j]
        j += 1

print(d[n])