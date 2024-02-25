import random


def slow(a):
    return sorted(a)


def merge(l, r, l2, r2, uk):
    res = [0] * (r2 - l)
    cl = l
    cr = r2
    while True:
        if l < r and l2 < r2:
            uk += 1
            if a[l] <= a[l2]:
                res[uk] = a[l]
                l += 1
            else:
                res[uk] = a[l2]
                l2 += 1
        else:
            if l2 < r2:
                for i in range(l2, r2):
                    uk += 1
                    l2 += 1
                    res[uk] = a[i]
            elif l < r:
                for i in range(l, r):
                    uk += 1
                    l += 1
                    res[uk] = a[i]
            else:
                break
    a[cl:cr] = res
    return res


def sof(l, r):
    if r - 1 - l == 0:
        return a[l]
    sof(l, l + (r - l) // 2 + (r - l) % 2)
    sof(l + (r - l) // 2 + (r - l) % 2, r)
    # print(a[l:l + (r-l) // 2 + (r-l) % 2], a[l + (r-l) // 2 + (r-l) % 2:r])
    return merge(l, l + (r - l) // 2 + (r - l) % 2, l + (r - l) // 2 + (r - l) % 2, r, - 1)


'''n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
b = [int(i) for i in input().split()]
res = [0]*(n+m)
merge(0, n, 0, m, -1)
for num in res:
    print(num, end= ' ')'''

n = int(input())
a = [int(i) for i in input().split()]
if n == 0 or n == 1:
    for x in a:
        print(x, end = ' ')
else:
    # if n == 1:
    #     print(a[0])
    #     exit()
    # c = slow(a)
    b = sof(0, n)
    for i in b:
        print(i, end=' ')


# for _ in range(10000):
#     n = random.randint(0, 20)
#     a = [random.randint(-10, 10) for _ in range(n)]
#     if (n==0):
#         print()
#         continue
#     copy = a.copy()
#     c = slow(a)
#     b = sof(0, n)
#     print(b)
#     if (b != c):
#         print(n)
#         for x in copy:
#             print(x)
#         print(c)
#         print(b)
#         exit()

# f = open('14.txt')
# n = int(f.readline())
# a = [int(i) for i in f.readline().split()]
# a.sort()
# m = int(f.readline())
# b = [int(i) for i in f.readline().split()]
# b.sort()
# res = [0]*(n+m)
# merge(0, n, 0, m, -1)
# for num in res:
#     print(num, end= ' ')
