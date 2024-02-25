import random


def mine(s):  # моё решение, рассматривая 2 варианта: подпалиндромы чётной длины и нечётной
    n = len(s)
    hl = [0] * (n + 1)
    hr = [0] * (n + 1)
    x = [0] * (n + 1)
    x_ = 257
    p = 1_000_000_007
    x[0] = 1
    for i in range(0, n):
        hl[i + 1] = (hl[i] * x_ + ord(s[i])) % p
        hr[i + 1] = (hr[i] * x_ + ord(s[n - i - 1])) % p
        x[i + 1] = x[i] * x_ % p

    def equal(a, b, l):
        a += 1
        b += 1
        # hl[a+l-1]-hl[a-1]*x[l] == hr[b+l-1]-hr[b-1]*x[l]
        return (
                (hl[a + l - 1] + hr[b - 1] * x[l]) % p ==
                (hr[b + l - 1] + hl[a - 1] * x[l]) % p
        )

    ans = n
    for i in range(n):
        # без этого элемента (он посередине)
        l = 0
        r = min(i, n - i - 1) + 1
        while r - l > 1:
            m = (r + l) // 2
            # if equal(i + 1, n - i - 1, m)
            if equal(i + 1, n - i, m):
                l = m
            else:
                r = m

        ans += l

        # до и после этого элемента
        l = 0
        r = min(i + 1, n - (i + 1)) + 1
        while r - l > 1:
            m = (r + l) // 2
            if equal(i + 1, n - (i + 1), m):
                l = m
            else:
                r = m

        ans += l

    print(ans)

    # я бинарю максимальный палиндром. Все, меньшие его, тоже палиндромы
    #  457 123 uk 321 9
    # 4571233219
    #  6-палиндром, соответственно, ans+=6//2


def optinal_not_optimal(s):  # подсказка Славы: вставить разделить, и рассматривать
    # все подпалиндромы становятся нечётной длины,
    # но работает дольше
    n = len(s)
    ans = n
    cnt = 0
    for i in range(1, len(s)):
        s = s[:i + cnt] + '2' + s[i + cnt:]
        cnt += 1
    # print(s)
    n = len(s)
    hl = [0] * (n + 1)
    hr = [0] * (n + 1)
    x = [0] * (n + 1)
    x_ = 257
    p = 1_000_000_007
    x[0] = 1
    for i in range(0, n):
        hl[i + 1] = (hl[i] * x_ + ord(s[i])) % p
        hr[i + 1] = (hr[i] * x_ + ord(s[n - i - 1])) % p
        x[i + 1] = x[i] * x_ % p

    def equal(a, b, l):
        a += 1
        b += 1
        # hl[a+l-1]-hl[a-1]*x[l] == hr[b+l-1]-hr[b-1]*x[l]
        return (
                (hl[a + l - 1] + hr[b - 1] * x[l]) % p ==
                (hr[b + l - 1] + hl[a - 1] * x[l]) % p
        )

    for i in range(n):
        l = 0
        r = min(i, n - i - 1) + 1
        while r - l > 1:
            m = (r + l) // 2
            # if equal(i + 1, n - i - 1, m)
            if equal(i + 1, n - i, m):
                l = m
            else:
                r = m

        if l > 1 or (l == 1 and s[i] == '2'):
            ans += l // 2 + (l % 2 != 0 and s[i] == '2')

    print(ans)

    # a2a2a2a


s = input()
mine(s)
'''
for i in range(1000):
    s = ''
    for _ in range(10):
        s += chr(random.randint(97, 110))
    if right(s) != wrong(s):
        print(s)
        print(right(s))
        print(wrong(s))
        break
'''
