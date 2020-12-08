arr = []

while(True):
    i = int(input())
    if i == 42:
        for k in arr:
            print(k)
        break
    else:
        arr.append(i)
