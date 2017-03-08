#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
LL gcd(LL a, LL b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
inline int read()
{
	int ret = 0,temp=1;
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
char str[25];
int main()
{
    while(true)
    {
        scanf("%s",str);
        int l=strlen(str);
        if(l==1 && str[0]=='0') break;
        LL n=0;
        LL k=1;
        for(int i=2;i<l;i++){
            if(str[i]=='.') break;
            n=n*10+(str[i]-'0');
            k=k*10;
        }
        LL g=gcd(n,k-1);
        LL a=n/g,b=(k-1)/g;
        LL temp=1,num=0;
        for(int i=2;i<l;i++){
            if(str[i]=='.') break;
            num=num*10+(str[i]-'0');
            temp=temp*10;
            if(n==num) break;
            LL p=n-num;
            LL q=k-temp;
            LL g=gcd(p,q);
            p/=g,q/=g;
            if(q<b){
                a=p;
                b=q;
            }
        }
        printf("%lld/%lld\n",a,b);
    }
    return 0;
}

