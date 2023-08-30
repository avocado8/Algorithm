#1244
n = int(input()) #스위치개수
switch = [-1]+list(map(int, input().split()))
stu = int(input()) #학생수

def switch_change(x):
    if switch[x]==0:
        switch[x]=1
    else:
        switch[x]=0

for _ in range(stu):
    a, b = map(int,input().split())
    if a==1: #남자
        for i in range(b, n+1, b):
            switch_change(i)
    else: #여자
        switch_change(b)
        for i in range(n//2):
            if b-i<1 or b+i>n:
                break
            if switch[b-i]==switch[b+i]:
                switch_change(b-i)
                switch_change(b+i)
            else:
                break

for i in range(1,n+1):
    print(switch[i], end=" ")
    if i%20==0:
        print()
