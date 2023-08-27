k, s, n = input().split()
king = list(map(int, [ord(k[0])-64, k[1]]))
stone = list(map(int, [ord(s[0])-64, s[1]]))

move = {'R':[1,0],'L':[-1,0],'B':[0,-1],'T':[0,1],
        'RT':[1,1],'LT':[-1,1],'RB':[1,-1],'LB':[-1,-1]}

for _ in range(int(n)):
    m=input()
    mx = king[0] + move[m][0]
    my = king[1] + move[m][1]
    if (0<mx<=8) and (0<my<=8):
        if (mx==stone[0]) and (my==stone[1]): #이동 위치=돌 위치
            sx = stone[0] + move[m][0]
            sy = stone[1] + move[m][1]
            if (0<sx<=8) and (0<sy<=8):
                king = [mx,my]
                stone = [sx,sy]
        else:
            king = [mx,my]
print(chr(king[0]+64)+str(king[1]))
print(chr(stone[0]+64)+str(stone[1]))
