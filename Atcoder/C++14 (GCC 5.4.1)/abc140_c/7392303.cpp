a,b=tuple(map(int,input().split()))
cnt=0
for i in range(1,a+1):
    q=i
    cont=0
    while True:
        if q>=b:
            break
        cont+=1
        q*=2
    cnt+=1/a*(1/2)**cont
    
print(cnt)