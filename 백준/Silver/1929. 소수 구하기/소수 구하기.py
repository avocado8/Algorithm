m,n=map(int,input().split())

def isprime(x):
    if x==1:
        return False
    else:
        for i in range(2, int(x**0.5)+1):
            if x%i==0:
                return False
        return True

for i in range(m, n+1):
    if isprime(i):
        print(i)
