def sum(N):
    if N<10:
        return N*(N+1)/2
    i=0
    n=N
    while(n/10!=0):
        i+=1
        n/=10
    p=p10[i]
    return ((n*45*i*p/10)+n*(n-1)*p/2+n*(N%p+1)+sum(N%p))
    
p10=[0]*20
p10[0]=1
for i in range(1,20):
    p10[i]=p10[i-1]*10
t=int(raw_input())
while t>0:
    a,b=map(int,raw_input().split())
    print sum(b)-sum(a-1)
    t-=1
    
