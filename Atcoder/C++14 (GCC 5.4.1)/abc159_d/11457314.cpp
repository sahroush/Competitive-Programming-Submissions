a = input();
cnt = 0;
if(a == a[::-1]):
	cnt+=1
n = len(a)
if(a[:(n-1)//2] == a[:(n-1)//2:-1]):
    cnt+=1
if(a[(n+3)//2-1::][::-1] == a[(n+3)//2-1:]):
    cnt+=1
if(cnt == 3):
    print("Yes")
else:
   	print("No")
