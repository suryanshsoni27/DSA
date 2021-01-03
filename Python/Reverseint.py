i = int(input())


def reverse(n):
    rev = 0
    while(n > 0):
        a = n % 10
        rev = rev * 10 + a
        n = n//10
    return rev


arr = []
for val in range(i):
    k = int(input())
    ret = reverse(val)
    arr.append(ret)

for val in arr:
    print(val)
