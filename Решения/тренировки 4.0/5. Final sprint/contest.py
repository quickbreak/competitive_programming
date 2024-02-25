a = [i * i for i in range(1, 1_000_0000)]
b = [i ** 3 for i in range(1, 1_000_00)]
res = [0] * 1_0000_001
l = 0
r = 0
uk = 1
while uk <= 1e7:
    if l < 1000_0000:
        if r < 1_000_00:
            if a[l] < b[r]:
                if a[l] > res[uk-1]:
                    res[uk] = a[l]
                    uk += 1
                l += 1
            else:
                if b[r] > res[uk-1]:
                    res[uk] = b[r]
                    uk += 1
                r += 1
        else:
            while l < 1_0000_000:
                if a[l] > res[uk-1]:
                    res[uk] = a[l]
                    uk += 1
                l += 1
    else:
        while r < 1_00_000:
            if b[r] > res[uk-1]:
                res[uk] = b[r]
                uk += 1
            r += 1

print(res[int(input())])
