#1388
n,m=map(int,input().split())
cnt=0
tile=[]

for _ in range(n):
    tile.append(list(input()))

#'-'모양
for i in range(n):
    a=''
    for j in range(m):
        if tile[i][j]=='-':
            if tile[i][j]!=a:
                cnt+=1
        a=tile[i][j]

#'|'모양
for j in range(m):
    a=''
    for i in range(n):
        if tile[i][j]=='|':
            if tile[i][j]!=a:
                cnt+=1
        a=tile[i][j]

print(cnt)
