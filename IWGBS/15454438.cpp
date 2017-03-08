n=int(input())
a=1
b=2
if n==0:
    print a
elif n==1:
    print b
else:
    ans=0
    for i in range(0,n-2+1):
        ans=a+b
        a=b
        b=ans
    print ans
