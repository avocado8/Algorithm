word = input()
result = []

for i in range(1, len(word)-1):
    for j in range(i+1, len(word)):
        first = word[:i]
        second = word[i:j]
        third = word[j:]

        revfirst = first[::-1]
        revsec = second[::-1]
        revthird = third[::-1]

        result.append(revfirst + revsec + revthird)

result.sort()

print(result[0])
