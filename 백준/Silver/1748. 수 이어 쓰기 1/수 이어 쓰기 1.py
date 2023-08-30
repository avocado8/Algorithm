n=input()
cnt=0
for i in range(1, len(n)):
    cnt += 10**(i-1) * i * 9
cnt += (int(n)-10**(len(n)-1)+1)*len(n)
print(cnt)

#자릿수 n -> 10**(n-1)* n * 9
