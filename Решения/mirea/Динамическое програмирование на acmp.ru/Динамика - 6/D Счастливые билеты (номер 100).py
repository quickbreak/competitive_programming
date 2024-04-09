n = int(input())
# cnt_sum[i][j] - count of numbers with length == i and sum == j
cnt_sum = [[0] * 901 for i in range(51)]
# small initialize
for digit in range(10):
    cnt_sum[1][digit] = 1
# small dp
for length in range(2, 51):
    for summa in range(901):
        for digit in range(10):
            if summa + digit > 900:
                break
            cnt_sum[length][summa + digit] += cnt_sum[length - 1][summa]

# lucky_dp[i][j] - count of lucky tickets with length == i and sum == j
lucky_dp = [[0] * 901 for _ in range(101)]
# initialize
# dp
for length in range(1, 51):
    for summa in range(451):
        lucky_dp[2 * length][2 * summa] = cnt_sum[length][summa] ** 2

ans = 0
for summa in range(901):
    ans += lucky_dp[n][summa]

print(ans)
