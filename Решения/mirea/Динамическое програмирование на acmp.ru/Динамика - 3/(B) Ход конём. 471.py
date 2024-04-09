n = int(input())
d = [0] * (n + 1)
last = [0] * 10
nextt = [0] * 10
# база динамики
d[1] = 10 - 2  # не может начинаться с 0 и 8
for i in range(1, 10):
    if i != 8:
        nextt[i] = 1

# динамика
for i in range(2, n + 1):
    for j in range(10):
        last[j] = nextt[j]

    d[i] = 3 * (last[4] + last[6])
    for j in range(10):
        if j != 4 and j != 6 and j != 5:
            d[i] += 2 * last[j]

    nextt[0] = last[4] + last[6]
    nextt[1] = last[6] + last[8]
    nextt[2] = last[7] + last[9]
    nextt[3] = last[4] + last[8]
    nextt[4] = last[3] + last[9] + last[0]
    nextt[6] = last[0] + last[7] + last[1]
    nextt[7] = last[2] + last[6]
    nextt[8] = last[1] + last[3]
    nextt[9] = last[2] + last[4]

print(d[n])
