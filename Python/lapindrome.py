t = int(input())
s_li = []

if(t >= 1 and t <= 100):
    while(t > 0):
        t -= 1
        s = input()
        if (len(s) >= 2 and len(s) <= 1000):
            s_li.append(s)


def lapidrome(s):
    if len(s) % 2 == 0:
        first = s[0:int(len(s)/2)]
        second = s[int(len(s)/2):]
        if sorted(first) == sorted(second):
            return("YES")
        else:
            return("NO")
    else:

        first = s[0:int(len(s)/2)]
        second = s[int(len(s)/2)+1:]
        if sorted(first) == sorted(second):
            return("YES")
        else:
            return("NO")


results = map(lapidrome, s_li)

for i in list(results):
    print(i)
