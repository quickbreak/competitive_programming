import random

def wrong():
    print('Initial array:')
    s = a[0]
    if n==1:
        print(s)
        m = len(s)
        b1 = [[] for _ in range(10)]
        b2 = [[] for _ in range(10)]
        print('**********')
        b1[int(s[-1])].append(s)
    else:
        print(s, end = ', ')
        m = len(s)
        b1 = [[] for _ in range(10)]
        b2 = [[] for _ in range(10)]
        b1[int(s[-1])].append(s)
        for i in range(1, n - 1):
            s = a[i]
            print(s, end = ', ')
            b1[int(s[-1])].append(s)
        s = a[-1]
        print(s, end='\n**********\n')
        b1[int(s[-1])].append(s)
    i = 1
    print(f'Phase {1}')
    for k in range(10):
        if i % 2 == 0:
            print(f'Bucket {k}: ', end='')
            if len(b2[k])==0:
                print('empty')
            else:
                for j in range(len(b2[k])-1):
                    s = b2[k][j]
                    print(s, end = ', ')
                print(f'{b2[k][-1]}')
        else:
            print(f'Bucket {k}: ', end='')
            if len(b1[k]) == 0:
                print('empty')
            else:
                for j in range(len(b1[k]) - 1):
                    s = b1[k][j]
                    print(s, end=', ')
                print(f'{b1[k][-1]}')
    print('**********')

    for i in range(2, m + 1):
        for k in range(10):
            if i % 2 == 0:
                for j in range(len(b1[k])):
                    s = b1[k][j]
                    b2[int(s[-i])].append(s)
                b1[k] = []
            else:
                for j in range(len(b2[k])):
                    s = b2[k][j]
                    b1[int(s[-i])].append(s)
                b2[k] = []
        print(f'Phase {i}')
        for k in range(10):
            if i % 2 == 0:
                print(f'Bucket {k}: ', end='')
                if len(b2[k]) == 0:
                    print('empty')
                else:
                    for j in range(len(b2[k]) - 1):
                        s = b2[k][j]
                        print(s, end=', ')
                    print(f'{b2[k][-1]}')
            else:
                print(f'Bucket {k}: ', end='')
                if len(b1[k]) == 0:
                    print('empty')
                else:
                    for j in range(len(b1[k]) - 1):
                        s = b1[k][j]
                        print(s, end=', ')
                    print(f'{b1[k][-1]}')
        print('**********')

    ans = ''
    print('Sorted array:')
    for k in range(10):
        if m % 2 == 0:
            for j in range(len(b2[k])):
                s = b2[k][j]
                ans+=s+', '
        else:
            for j in range(len(b1[k])):
                s = b1[k][j]
                ans += s + ', '

    return ans[:-2]

'''
2
2 
1
'''


n = int(input())
a = [input() for _ in range(n)]
print(wrong())

# for i in range(1000):
#     n = random.randint(1, 10)
#     a = [str(random.randint(0, 9)) for _ in range(n)]
#     res = wrong()
#     a = [int(x) for x in a]
#     a.sort()
#     res1 = ''
#     for x in a:
#         res1+=f'{x}, '
#     if res1[:-2]!=res:
#         print(n)
#         for x in a:
#             print(x)
#         break