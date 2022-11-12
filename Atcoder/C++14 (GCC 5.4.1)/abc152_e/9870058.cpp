(a , b) = list (map (int, input().strip().split()))
c = str(a)*b
d = str(b)*a
if(c < d):
  print (c)
else:
  print(d)
