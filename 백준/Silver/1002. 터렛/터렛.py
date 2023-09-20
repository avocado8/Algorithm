T=int(input())
for i in range(T):
    x1,y1,r1,x2,y2,r2=map(int,input().split())
    d=((x2-x1)**2+(y2-y1)**2)**0.5
    if(x1==x2 and y1==y2):
        if(r1==r2):
            print(-1)
        else:
            print(0)
    else:
        if(abs(r2-r1)<d and d<(r2+r1)):
            print(2)
        elif(d==abs(r2-r1) or d==(r2+r1)):
            print(1)
        else:
            print(0)
