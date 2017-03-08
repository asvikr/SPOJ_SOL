#include<stdio.h>
#include<stdlib.h>
long long mul(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

long long mod(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c);
        b /= 2;
    }
    return x%c;
}
int fermat(long long p,int iterations){
    if(p == 1){
        return 0;
    }
    if((p%2==0) && (p!=2))
        return 0;
    int i;
    for(i=0;i<iterations;i++){
          long long a = rand()%(p-1)+1;
   // printf("a=%lld ",a);
     //   printf("mod=%d\n",mod(a,p-1,p));
        if(mod(a,p-1,p)!=1){
            return 0;
        }
    }
    return 1;
}

int main()
{
	long long test , n;
	scanf("%lld" , &test);
	int p=1,k=1;
	while(test--)
	{
	   // printf("%lld\n",mod(p++,k++,1000000007));
	    //ontinue;
		scanf("%lld" ,&n);
		int fl = fermat(n ,20);
		if(fl)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
