import math
def countOne(n):
    count = 0
    for i in range(0,int(math.log(n ,2 ))+1):
        count += n % 2
        n = n // 2
    return count
    
def nextBigNumber(n):
    answer = 0
    i = 0
    while True:
        i= i+1
        if countOne(n+i) == countOne(n):
            break
    answer = n+i
    return answer

#아래 코드는 테스트를 위한 출력 코드입니다.
print(nextBigNumber(78))

#다른분의 참고코드
'''
def nextBigNumber(n):
    num1 = bin(n).count('1')
    while True:
        n = n + 1
        if num1 == bin(n).count('1'):
            break
    return n

#아래 코드는 테스트를 위한 출력 코드입니다.
print(nextBigNumber(78))
'''
