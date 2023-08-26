#1004어린왕자

T=int(input())
for i in range(T):
    x1, y1, x2, y2 = map(int,input().split())
    n=int(input())
    cnt=0
    for _ in range(n):
        cx, cy, r = map(int,input().split())
        dist1 = (x1-cx)**2 + (y1-cy)**2
        dist2 = (x2-cx)**2 + (y2-cy)**2
        rad = r**2

        if rad > dist1 and rad > dist2:
            pass
        elif rad > dist1:
            cnt+=1
        elif rad > dist2:
            cnt+=1
    print(cnt)
