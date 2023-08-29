#1463
#dynamic programming
n=int(input())
res = [0]*(n+1)

for i in range(2,n+1):
    res[i] = res[i-1]+1
    if i%3==0:
        res[i] = min(res[i],res[i//3]+1)
    if i%2==0:
        res[i] = min(res[i],res[i//2]+1)
print(res[n])
