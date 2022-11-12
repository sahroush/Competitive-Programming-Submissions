n, x, m = map(int,input().split())
dic = {x:0}
tmp = x
i = 1
l = 0
start = 0
while 1:
    tmp = pow(tmp,2,m)
    if tmp in dic:
        start = dic[tmp]
        l = i - dic[tmp]
        check = tmp
        break
    else:
        dic[tmp] = i
    i += 1
# print(l,start, check)
ans = 0
tmp = 0
if n <= start:
    if tmp == 0:
        ans = x
        tmp = x
    else:
        for i in range(n-1):
            tmp = pow(tmp,2,m)
            ans += tmp
else:
    for i in range(start):
        if tmp == 0:
            tmp = x
            ans = x
        else:
            tmp = pow(tmp,2,m)
            ans += tmp
    sep = 0
    tmp = check
    for i in range(l):
        sep += tmp
        tmp = pow(tmp,2,m)
    ans += sep * ((n - start) // l)
    tmp = check
    for i in range((n - start) % l):
        ans += tmp
        tmp = pow(tmp,2,m)
print(ans)