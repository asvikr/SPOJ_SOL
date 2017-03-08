#include<bits/stdc++.h>
using namespace std;
#define MAXI 50001
#define MAXN 250005
#define MAXSQRT 500
inline int read()
{
	int ret = 0;
	int c = getchar_unlocked();

	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
typedef long long int LL;
int A[MAXN],N,M,bit[MAXSQRT+1][MAXI+1],sqrtN;
void bitins(int x,int y,int val)
{
    while(x<=sqrtN){
        for(int i=y;i<=MAXI;i+=i&-i){
            bit[x][i]+=val;
        }
        x+=x&-x;
    }
}
void init()
{
    for(sqrtN=1;sqrtN*sqrtN<N;sqrtN++);
        for(int i=0;i<N;i++){
            bitins(i/sqrtN+1,A[i],1);
        }
}
int bitsum(int x,int y)
{
    int ret=0;
    for(;x>0;x-=x&-x){
        for(int yy=y;yy>0;yy-=yy&-yy){
            ret+=bit[x][yy];
        }
    }
    return ret;
}
int query(int i,int x)
{
    int ret=bitsum(i/sqrtN,x);
    for(int j=sqrtN*(i/sqrtN);j<=i;j++){
        if(A[j]<=x)
            ret++;
    }
    return ret;
}
int main()
{
    //scanf("%d",&N);
    N=read();
    for(int i=0;i<N;i++)
        A[i]=read();//scanf("%d",&A[i]);
   // scanf("%d",&M);
   M=read();
    int X,Y;
    init();
    LL inv=0;
    for(int i=0;i<N;i++)
        inv+=i-query(i,A[i])+1;
    while(M--){
        //scanf("%d %d",&X,&Y);
        X=read();
        Y=read();
        X--;
        inv-=(X-query(X-1,A[X])-1)+query(N-1,A[X]-1)-query(X,A[X]-1);
        bitins(X/sqrtN+1,A[X],-1);
        A[X]=Y;
        bitins(X/sqrtN+1,A[X],1);
        inv+=(X-query(X-1,A[X])-1)+query(N-1,A[X]-1)-query(X,A[X]-1);
        printf("%lld\n",inv);
    }
    return 0;
}
