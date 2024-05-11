import random


def slow(a):
    return sorted(a)


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


def msort(l, r):
    if r == l:
        return
    if r <= l:
        print('ошибка в индексах')
        exit()
    if r - l == 1:
        return
    mi = min(a[l:r])
    ma = max(a[l:r])
    if mi == ma:
        return
    x = random.randint(mi, ma)
    uk = partition(x, l, r-1)
    # if uk == 0 or uk == r:
    #     return
    msort(l, uk)
    msort(uk, r)


n = int(input())
a = [int(num) for num in input().split()]
if n == 0 or n == 1:
    for x in a:
        print(x, end=' ')
else:
    #c = slow(a)
    msort(0, n)
    for num in a:
        print(num, end=' ')

# for i in range(1):
#     n = random.randint(0, 1000000)
#     a = [random.randint(-1000000000, 1000000000) for _ in range(n)]
#     #print(n)
#     # for x in a:
#     #     print(x, end=' ')
#     if n == 0 or n == 1:
#         continue
#     else:
#         c = slow(a)
#         msort(0, n)
#         if a != c:
#             print(1)
