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
int a[1005];
int main()
{
    int n;
    int x,k=1;
    while(1)
    {
        scanf("%d",&n);
        k=1;
        if(n==0)
            break;
        stack<int> S;
        FOR(i,1,n)
        {
        scanf("%d",&x);
        if(x==k)
        {
            k++;
            while(!S.empty())
            {
                if(S.top()==k)
                {
                    S.pop();
                    k++;
                }
                else
                    break;
            }
        }
        else
        {
            S.push(x);
        }
        }
        int temp=1;
        if(k==n+1)
        {
            printf("yes\n");
           // printf("hello\n");
        }
        else
        {
            while(!S.empty())
            {
                if(k==S.top())
                {
                   // printf("%d\n",S.top());
                    S.pop();
                    k++;
                }
                else
                {
                    temp=0;
                    break;
                }
            }
            if(temp==1)
                printf("yes\n");
            else
                printf("no\n");
        }

    }
    return 0;
}
