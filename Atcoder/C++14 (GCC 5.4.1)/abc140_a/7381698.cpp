a=input()
b=int(a[:2])
c=int(a[2:])
y=0
m=0
if c>0 and c<13:
    m=1
if b>0 and b<13:
    y=1
if m==1==y:
    print("AMBIGUOUS")
elif m==y==0:
    print("NA")
elif m==1:
    print("YYMM")
else:
    print("MMYY")