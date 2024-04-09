n = int(input())
# dp[i][j] == count of ladders with sum of lens == i and last len == j
dp = [[0] * (n + 1) for _ in range(n + 1)]
# initializing
for i in range(1, n+1):
    dp[i][i] = 1
# dp
for summa in range(1, n + 1):
    for last in range(0, n + 1):
        for i in range(last + 1, n + 1):
            if summa + i > n:
                break

            dp[summa + i][i] += dp[summa][last]

ans = 0
for last in range(n + 1):
    ans += dp[n][last]

print(ans)
