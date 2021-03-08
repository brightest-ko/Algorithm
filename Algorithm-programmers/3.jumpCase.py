def fac(a):
    if a <= 1:
        return 1
    return a*fac(a-1)

def com(a,b):
    return fac(a)/(fac(b)*fac(a-b))

def jumpCase(num):
    result = 0
    print(num//2+1)
    for i in range(0,num//2+1): 
        #와 대박!! num이 계속 바뀌는데 for문엔 영향을 주지 않음.
        result += com(num,i)
        num = num-1
        print(i,result)
    return result

'''
def jumpCase(num):
    if num == 1:
        return 1
    if num == 2:
        return 2
    return jumpCase(num - 1) + jumpCase(num - 2)
'''
#아래는 테스트로 출력해 보기 위한 코드입니다.
print(jumpCase(13))
