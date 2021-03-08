cn = 26 # ord('z')-ord('a')+1
a = ord('a') #97
z = ord('z') #122
A = ord('A') #65
Z = ord('Z') #90

def caesar(s, n):
    result=""
    for i in range(0,len(s)):
        if s[i]==" ":
            result+=" "
            continue
        nl = ord(s[i])+n
        if (a <= ord(s[i]) and z >= ord(s[i]) and nl > z):
            result += chr((a+(nl-123)%cn));
        elif (A <= ord(s[i]) and Z >= ord(s[i]) and nl > Z):
            result += chr((A+(nl-91)%cn));
        else:
            result += chr(nl)
    return result
    # 주어진 문장을 암호화하여 반환하세요.



# 실행을 위한 테스트코드입니다.
print('s는 "a B z", n은 4인 경우: ' + caesar("a B z", 4))

