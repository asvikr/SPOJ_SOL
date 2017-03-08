#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
const LL base=10007;
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
char str[N];
LL p[N];
int main()
{
    p[0]=1;
    for(int i=1;i<N;i++){
        p[i]=p[i-1]*base;
    }
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        printf("Case %d:\n",tt);
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        LL h=0,w=0;
        for(int i=0;i<n;i++)
            h=h*base+(LL)str[i];
        for(int i=n-1;i>=0;i--)
            w=w*base+(LL)str[i];
        int q;
        scanf("%d",&q);
        while(q--){
            int id;
            char s[2];
            scanf("%d %s",&id,s);
            LL temp=(LL)str[id-1];
            temp=temp*p[n-id];
            h-=temp;
            temp=(LL)s[0];
            temp=temp*p[n-id];
            h+=temp;
            id--;
            temp=(LL)str[id];
            temp=temp*p[id];
            w-=temp;
            temp=(LL)s[0];
            temp=temp*p[id];
            w+=temp;
            str[id]=s[0];
           // cout<<h<< " "<<w<<endl;
            (h==w)?puts("YES"):puts("NO");
        }
    }
    return 0;
}
/*
1
9
123456789
10
3 5
1 5
8 9
9 7
1 4
2 3
*/

