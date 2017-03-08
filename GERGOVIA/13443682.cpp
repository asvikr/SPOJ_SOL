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
#define FOR(a,b) for(int i=a;i<=b;i++)

typedef long long int LL;
typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long int     ull;
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
int a[100005];
int main()
{
        int n;
        while(1)
        {
            scanf("%d",&n);
            if(n==0)
                break;
            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
                LL cost=0;
            for(int i=1;i<n;i++)
            {
                a[i]+=a[i-1];
                cost+=abs(a[i-1]);

            }
            printf("%lld\n",cost);
        }
    return 0;
}
