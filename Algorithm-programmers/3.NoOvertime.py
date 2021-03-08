def noOvertime(n, works):
    result = 0
    # 야근 지수를 최소화 하였을 때의 야근 지수는 몇일까요?
    l = len(works) -1
    for i in range(0,n):
        works.sort()
        works[l] = works[l]-1
    
    for i in range(0,len(works)):
        result += works[i]*works[i]
    return result
