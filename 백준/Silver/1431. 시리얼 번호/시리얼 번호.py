n=int(input())
serial=[]
for _ in range(n):
    serial.append(input())

def ser_sum(ser):
    result=0
    for i in ser:
        if i.isdigit():
            result+=int(i)
    return result

serial.sort(key=lambda x:(len(x), ser_sum(x),x))
for i in serial:
    print(i)

