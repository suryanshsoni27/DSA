import math
t = int(input())


def calculate(arr):
    if len(set(arr)) == 1:
        sumi = 0
        for i in range(int(math.ceil(len(arr))/2)+1):
            sumi += arr[0]
        return sumi
    else:
        val = max(arr)

        if sum(sorted(arr)[:-1]) == val:
            return max(arr)
        else:
            return min(arr) + max(arr)


def check(vals):
    for i in vals:
        if i < 1 or i > 5:
            return False
    return True


ansarr = []
if(t >= 1 and t <= 1000):

    while(t > 0):
        n = int(input())
        if(n >= 1 and n <= 4):
            vals = []
            vals = list(map(int, input().strip().split()))[:n]
            if check(vals):
                ans = calculate(vals)
                ansarr.append(ans)
        t -= 1

for i in ansarr:
    print(i)
