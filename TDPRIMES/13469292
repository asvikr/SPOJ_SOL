#include<bits/stdc++.h>
using namespace std;
const int MAX=100000000;
const int LMT=10000;
const int LEN=5000000;
int flag[MAX>>6];
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
/*inline void write (int n)
{
	register int i=20, n2=n;
	char output_buffer[20];
	do
	{
		output_buffer[--i]=(n2%10)+'0';
		n2/=10;
	}while(n2);
	do
	{
		putchar_unlocked(output_buffer[i]);
	}while(++i<20);
}*/
void sieve()
{
    int k,i,j;
    for(i=3;i<LMT;i+=2)
    {
        if(!ifc(i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
            isc(j);
    }
    printf("2\n");
    for(i=3,j=2;i<MAX;i+=2)
    {
        if(!ifc(i))
        {
            if(j%100==1)
            {
                printf("%d\n",i);
            }
            j++;
        }
    }
}
int main()
{
    sieve();
    return 0;
}
