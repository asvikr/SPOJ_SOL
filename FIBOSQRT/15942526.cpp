#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
//#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x);
        x=(x*x);
        y/=2;
    }
    return ans;
}
inline LL read()
{
	LL ret = 0;
	int c = getchar_unlocked();
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
LL f0,f1,M,N;
LL fibo(LL n)
{
    LL mat[3][3]={{1,1,2},{1,0,0},{1,0,1}},ans[3][3],temp[3][3];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<3;i++) ans[i][i]=1;
    while(n>0){
        memset(temp,0,sizeof(temp));
        if(n&1){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        temp[i][j]=(temp[i][j]+ans[i][k]*mat[k][j])%M;
                    }
                }
            }
            for(int i=0;i<3;i++) for(int j=0;j<3;j++) {ans[i][j]=temp[i][j];temp[i][j]=0;}
        }
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) temp[i][j]=(temp[i][j]+mat[i][k]*mat[k][j])%M;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) {mat[i][j]=temp[i][j];temp[i][j]=0;}
        n>>=1;
    }
    LL p=sqrt(3+f1*f0);
    LL res=(ans[0][0]*f1+ans[0][1]*f0+ans[0][2]*p)%M;
    return res;
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        f0=read();f1=read();M=read();N=read();
        if(N==0){
            printf("%llu\n",f0%M);
            continue;
        }
        if(N==1){
            printf("%llu\n",f1%M);
            continue;
        }
        LL ans=fibo(N-1);
        printf("%llu\n",ans);
    }
    return 0;
}

