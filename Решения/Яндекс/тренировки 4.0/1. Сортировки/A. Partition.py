import random


def slow(x):
    res = 0
    for num in a:
        if num < x:
            res += 1
    return res


def partition(x, l, r):
    if r == l:
        if a[l] < x:
            return l + 1
        else:
            return l
    while l < r:
        while l < n and a[l] < x:
            l += 1
        while r >= 0 and a[r] >= x:
            r -= 1
        if l < r:
            a[l], a[r] = a[r], a[l]

    if l < n and a[l] < x:
        return l + 1
    else:
        return l


n = int(input())
a = [int(num) for num in input().split()]
x = int(input())
uk = partition(x, 0, n - 1)
print(uk, n - uk, sep="\n")
#print(slow(x), n - slow(x), sep="\n")

# for i in range(1000):
#     n = random.randint(0, 10)
#     a = [random.randint(-10, 10) for _ in range(n)]
#     x = random.randint(-13, 13)
#     uk = partition(x, 0, n - 1)
#     b, y = uk, n - uk
#     c = slow(x)
#     d = n - c
#     if (b, y) != (c, d):
#         print(n)
#         for i in range(n):
#             print(a[i],end=' ')
#         print('\n', x, sep='')
#         print((b, y), (c, d))
#         break
