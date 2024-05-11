n = int(input())
# n = 1000
# a = [1000] * 1000
a = [int(x) for x in input().split()]
pref = [0]*(n+1)
for i in range(n):
    pref[i+1] = pref[i]+a[i]

ans = 0
for i in range(1, n - 1):
    ans += pref[i] * a[i] * (pref[n] - pref[i+1])

print(ans)