n = int(input())
file = list(input())

for i in range(n-1):
    file2 = input()
    for j in range(len(file2)):
        if file[j] == file2[j]:
            continue
        else:
            file[j] = "?"
print(''.join(file))
