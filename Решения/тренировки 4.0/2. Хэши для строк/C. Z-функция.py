s = input()
n = len(s)
h = [0] * (n + 1)
x = [0] * (n + 1)
x_ = 257
p = 1_000_000_007
x[0] = 1
for i in range(0, n):
    h[i + 1] = (h[i] * x_ + ord(s[i])) % p
    x[i + 1] = x[i] * x_ % p


def equal(a, b, l):
    a += 1
    b += 1
    # h[a+l-1]-h[a]*x[l] == h[b+l-1]-h[b]*x[l]
    return (
            (h[a + l - 1] + h[b - 1] * x[l]) % p ==
            (h[b + l - 1] + h[a - 1] * x[l]) % p
    )


print(0, end = ' ')
for i in range(1, n):
    l = 0
    r = n - i + 1
    while r - l > 1:
        m = (r + l) // 2
        if equal(0, i, m):
            l = m
        else:
            r = m
    print(l, end = ' ')
