c0=[1,0,1]
c1=[0,1,1]

def fibo(n):#6
    l=len(c0)#3
    if l<=n:
        for i in range(l,n+1):
            c0.append(c0[i-1]+c0[i-2])
            c1.append(c1[i-1]+c1[i-2])
    print('%d %d'%(c0[n],c1[n]))
for _ in range(int(input())):
    fibo(int(input()))
