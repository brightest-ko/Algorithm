def lcm(num):
    num.sort()
    for i in range(0,num[0],-1):
        if num[0] % i == 0 and num[1] % i == 0:
            return i*(num[0]//i)*(num[1]//i)
        
def nlcm(num):
    a = lcm([num[0],num[1]])
    if len(num) > 2:
        for i in range(2,len(num)-1):
            lcm([a,num[i]])
    
# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(nlcm([2,6,8,14]));
