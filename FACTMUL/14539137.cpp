n=int(input())
fact=1
ans=1
if n>=587117:
    print(0)
else:
    M=109546051211
    for i in range(1,n+1):
        fact=fact*i
        if fact>=M:
            fact%=M
        ans=ans*fact
        if ans>=M:
            ans%=M    
    print(ans)

