import math
t=int(raw_input())
for _ in xrange(t):
    n=int(raw_input())
    temp=(n*(n+1))/2
    sq=int(math.sqrt(n))
    res=0
    prev=temp
    for i in range(1,sq+1):
        en=n//i
        st=n//(i+1)
        cur=(st*(st+1))/2
        res=res+i*(prev-cur)
        if i!=en:
            res=res+en*i
        prev=cur

    res=res-temp
    print(res)



