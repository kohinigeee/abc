l = input().split()
a = int(l[0])
b = int(l[1])
c = int(l[2])
d = int(l[3])
e = int(l[4])
f = int(l[5])

MOD = 998244353

v = a*b*c-d*e*f

v = v%MOD
if ( v < 0 ):
     v += MOD
print(v)