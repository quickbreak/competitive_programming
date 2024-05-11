s = input()
q = int(input())
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
    # h[a+l-1]-h[a]*x[l] == h[b+l-1]-h[b]*x[l]
    return (
            (h[a + l - 1] + h[b-1] * x[l]) % p ==
            (h[b + l - 1] + h[a-1] * x[l]) % p
    )


for _ in range(q):
    l, a, b = map(int, input().split())
    if equal(a+1, b+1, l):
        print("yes")
    else:
        print("no")
