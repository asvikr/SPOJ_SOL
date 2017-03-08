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
inline LL read()
{
	LL ret = 0;
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
LL a[1000005];
int main()
{
    int n;
    //while(1)
    //{
    //scanf("%d",&n);
    n=read();
    FOR(i,0,n-1)
    {
        //scanf("%d",&a[i]);
        a[i]=read();
    }
    int k;
    scanf("%d",&k);
    if(k==1)
    {
        FOR(i,0,n-1)
        printf("%lld ",a[i]);
        printf("\n");
    }
    else
    {
        multiset<LL> S;
        int cnt=0,j=0;
        for(int i=0;i<k;i++)
            S.insert(a[i]);
        for(int i=k;i<n;i++)
        {
            multiset<LL>::iterator it;
            /*for(it=S.begin();it!=S.end();it++)
                printf("%lld ",*it);
            printf("\n");*/
                printf("%lld ",*S.rbegin());
                S.erase(S.find(a[j]));
                j++;
                S.insert(a[i]);
        }
         printf("%lld\n",*S.rbegin());
    }
    //}
    return 0;
}
