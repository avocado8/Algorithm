n = int(input())
A = list(map(int,input().split()))

m = int(input())
B = list(map(int,input().split()))

A.sort()

for i in B:
    start = 0
    end = len(A) - 1
    flag = False
    while(start <= end):
        mid = (start + end) // 2
        
        if (A[mid]==i):
            print(1)
            flag=True
            break
        elif A[mid] > i :
            end = mid - 1
        else:
            start = mid + 1
            
    if not flag:
        print(0)
