#1065
n=int(input())
cnt=0
for i in range(1,n+1):
    num = list(map(int,str(i)))
    if i<100:
        cnt+=1
    elif num[0]-num[1] == num[1]-num[2]:
        cnt+=1
print(cnt)
