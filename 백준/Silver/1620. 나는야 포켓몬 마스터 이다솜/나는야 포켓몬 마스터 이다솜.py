#1620
import sys
input = sys.stdin.readline

n,m=map(int,input().split())
plist={}

for i in range(1,n+1):
    p=input().rstrip()
    plist[i]=p
    plist[p]=i

for i in range(m):
    a=input().rstrip()
    if a.isdigit():
        print(plist[int(a)])
    else:
        print(plist[a])
