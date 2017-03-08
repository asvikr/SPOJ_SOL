#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<deque>
#include<utility>
#include<algorithm>
#include<bitset>
#include<climits>
#include <sstream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
/*#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;*/
typedef long long int LL;
typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long int     ull;
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
LL com(LL n,LL r)
{
    if(n<r)
        return 0;
    if(n==r)
        return 1;
    LL m=max(n-r,r);
    LL ans=1;
    for(LL i=n;i>m;i--)
    {
        //printf("%lld %lld\n",i,n-i+1);
     ans=(ans*i)/(n-i+1);
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n,k;
        scanf("%lld%lld",&n,&k);
        LL ans=com(n-1,k-1);
        printf("%lld\n",ans);
    }
    return 0;
}
