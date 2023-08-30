#1358
w, h, x, y, p = map(int,input().split())
radius = h/2
xlo=[]
ylo=[]
for _ in range(p):
    x1,y1=map(int,input().split())
    xlo.append(x1)
    ylo.append(y1)

cnt=0
for i in range(p):
    if xlo[i] >=x and xlo[i]<=x+w: #직사각형
        if ylo[i]>=y and ylo[i]<=y+h:
            cnt+=1
    elif xlo[i]<x: #왼쪽반원
        #(x,y+radius), (xlo[i],ylo[i])
        dist = ((xlo[i]-x)**2 + (ylo[i]-(y+radius))**2)**0.5
        if dist <= radius:
            cnt+=1
    elif xlo[i]>x+w: #오른쪽반원
        #(x+w,y+radius), (xlo[i],ylo[i])
        dist = ((xlo[i]-(x+w))**2 + (ylo[i]-(y+radius))**2)**0.5
        if dist <= radius:
            cnt+=1

print(cnt)
