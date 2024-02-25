import random


def slow():
    return sorted(a+b)


def merge(l, r, l2, r2, uk):
    while True:
        if l < n and l2 < m:
            uk += 1
            if a[l] <= b[l2]:
                res[uk] = a[l]
                l+=1
            else:
                res[uk] = b[l2]
                l2+=1
        else:
            if l2 < m:
                for i in range(l2, m):
                    uk += 1
                    l2+=1
                    res[uk] = b[i]
            elif l<n:
                for i in range(l, n):
                    uk += 1
                    l+=1
                    res[uk] = a[i]
            else:
                break


n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
b = [int(i) for i in input().split()]
res = [0]*(n+m)
merge(0, n, 0, m, -1)
for num in res:
    print(num, end= ' ')

# for _ in range(1000):
#     n = random.randint(0, 10)
#     a = [random.randint(-10, 10) for _ in range(n)]
#     a.sort()
#     m = random.randint(0, 10)
#     b = [random.randint(-10, 10) for _ in range(m)]
#     b.sort()
#     res = [0]*(n+m)
#     merge(0,n,0,m,-1)
#     wres = slow()
#     for i in range(n+m):
#         if res[i]!=wres[i]:
#             print(n)
#             for j in range(n):
#                 print(a[j], end = ' ')
#             print('\n', m, sep="")
#             for j in range(m):
#                 print(b[j], end = ' ')
#             print()
#             print(res)
#             print(wres)
#             exit()

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