a,b=tuple(map(int,input().split()))
c=input()
for i in range(a):
    if i!=b-1:
        print(c[i],end="")
    else:
        print(c[i].lower(),end="")
