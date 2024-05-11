def gen(pos):
    if pos == n - 1:
        print(''.join(a))
        return

    for x in range(1, n + 1):
        if not used[x]:
            a[pos + 1] = str(x)
            used[x] = 1
            gen(pos + 1)
            used[x] = 0


n = int(input())
used = [0] * (n + 1)
a = ['0'] * (n)
gen(-1)


# def gen(p, cur):
#     if cur == n:
#         ans.append(''.join(p))
#     else:
#         for i in range(cur, n):
#             p[i], p[cur] = p[cur], p[i]
#             gen(p, cur + 1)
#             p[i], p[cur] = p[cur], p[i]
#
#
# ans = []
# n = int(input())
# p = list(map(str, range(1, n + 1)))
# gen(p, 0)
# for s in sorted(ans):
#     print(s)
