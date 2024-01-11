n=int(input())
stu = []
for i in range(n):
  stu.append(input())
num_len = len(stu[0])

def has_dup(arr):
  return len(arr) != len(set(arr))

for i in range(num_len):
  tmp = []
  for j in range(n):
    tmp.append((stu[j])[(num_len-1)-i:])
  if (has_dup(tmp)):
    continue
  else:
    print(i+1)
    break 