#1205
n, score, p = map(int, input().split())
if n==0:
    print(1)
else:
    ranking=list(map(int, input().split()))
    if n==p and ranking[-1]>=score :
        print(-1)
    else:
        rank = n+1
        for s in ranking:
            if s <= score:
                rank = ranking.index(s)+1
                break
        print(rank)
