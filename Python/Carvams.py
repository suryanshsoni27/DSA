t = int(input())

lidi = {}
if(t >= 1 and t <= 100):
    for i in range(t):
        numcars = int(input())
        if numcars >= 1 and numcars <= 10000:
            li = list(map(int, input().split()))
            lidi[numcars] = li
        else:
            pass
else:
    pass


def max():
    pass


for key in lidi:
    val = max(lidi[key])

print(val)
