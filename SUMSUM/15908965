#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
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
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
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
const int N=100005;
int tree[28][N];
int a[N];
int n,q;
void update(int idx,int val,int i)
{
    while(idx<=n){
        tree[i][idx]+=val;
        idx+=idx&-idx;
    }
}
int query(int idx,int i)
{
    int ret=0;
    while(idx>0){
        ret+=tree[i][idx];
        idx-=idx&-idx;
    }
    return ret;
}
LL b[28];
int main()
{
    for(int i=0;i<28;i++) b[i]=(1<<i);
    n=read();q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=0;i<28;i++){
        for(int j=1;j<=n;j++){
            if(a[j]&(1<<i))
                update(j,1,i);
        }
    }
    int id,l,r,val;
    char str[5];
    while(q--){
        id=read();
        if(id==1){
            val=read();
            l=read();
            if(a[l]!=val){
            for(int i=0;i<28;i++){
            int p=a[l]&(1<<i);
            int q=val&(1<<i);
            if(p!=q && q!=0)
            update(l,1,i);
            else if(p!=q && q==0)
                update(l,-1,i);
            }
            a[l]=val;
            }
        }
        else
        {
            scanf("%s",str);
            l=read();r=read();
            if(l>r) swap(l,r);
            LL ans=0;
            for(int i=0;i<28;i++){
                LL one=query(r,i)-query(l-1,i);
              //  printf("%lld\n",one);
                LL zero=(LL)(r-l+1)-one;
                if(str[0]=='X') ans=(ans+(one*zero)*b[i]);
                else if(str[0]=='O') ans=(ans+((one*(one-1))/2+one*zero)*b[i]);
                else ans=(ans+((one*(one-1))/2)*b[i]);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

