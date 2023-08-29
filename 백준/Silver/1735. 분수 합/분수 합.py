import math
u1, d1 = map(int, input().split())
u2, d2 = map(int, input().split())

dres = d1 * d2
ures = u1*d2 + u2*d1

gcd = math.gcd(dres,ures)
dres = dres//gcd
ures = ures//gcd

print(ures, dres)
