#1302
n=int(input())
booklist=dict()

for _ in range(n):
    book = input()
    if book in booklist:
        booklist[book] += 1
    else:
        booklist[book] = 1
max=0
sorted_list=dict(sorted(booklist.items()))

for i in sorted_list:
    if sorted_list[i] > max:
        max = sorted_list[i]
        result = i
print(result)

