def divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n%i == 0:
            divisors.append(i)
            if i != n//i:
                divisors.append(n//i)
    return sorted(divisors) 
n = int(input())
ans = len(divisors(n-1))-1;
for k in divisors(n)[1:]:
    boz = n
    while (n % k == 0):
        n = n//k
    if (n % k == 1):
	    ans += 1
    n = boz
print(ans)
