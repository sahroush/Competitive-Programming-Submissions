N = int(input())
 
def solve(N):
    if (N % 2 == 1):
        return 0
    
    d = N // 10
    ans = d
    while d:
        d //= 5
        ans += d
    return ans
 
print(solve(N))