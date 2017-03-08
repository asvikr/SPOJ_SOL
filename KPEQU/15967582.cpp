N=10005
prime=[2]
mark=[0]*N
for i in range(3,N,2):
    if mark[i]==0:
        for j in range(i*i,N,2*i):
            mark[j]=1

for i in range(3,N,2):
    if mark[i]==0:
        prime.append(i)

while 1:
    n=int(raw_input())
    if n==0:
        break
    ans=1
    for i in range(0,len(prime)):
        if n<prime[i]:
            break
        cnt=0
        p=n
        while p/prime[i]!=0:
            cnt+=p/prime[i]
            p/=prime[i]

        ans*=2*cnt+1

    print ans

    
