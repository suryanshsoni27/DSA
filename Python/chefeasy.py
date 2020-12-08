def caculateday(arr, arrdn):
    val = arrdn
    summ = sum(arr)

    count = 1
    while(summ >= arrdn[1]):
        summ = summ - arrdn[1]
        count += 1

    return count


i = int(input())
if(i >= 1 and i <= 1e5):
    arr_daysNnum = []
    arr_queries = []
    ans = []
    for ite in range(i):
        days, queries = input().split()
        if(int(queries) >= 1 and int(queries) <= 1e8):
            arr_daysNnum.append(int(days))
            arr_daysNnum.append(int(queries))

            arr_queries = list(map(int, input().strip().split()))[
                :arr_daysNnum[0]]
            day = caculateday(arr_queries, arr_daysNnum)
            ans.append(day)
            arr_daysNnum.clear()
            arr_queries.clear()

        for i in ans:
            print(i)
        else:
            break
else:
    pass
