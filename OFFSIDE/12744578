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
int main()
{
    int A,D;
    while(1)
    {
    scanf("%d%d",&A,&D);
    if(A==0 && D==0)
        break;
    int x,min1=99999;
    FOR(i,0,A-1)
    {
        scanf("%d",&x);
        if(x<min1)
            min1=x;
    }
    //printf("%d\n",min1);
    int m1,m2=99999;
    scanf("%d",&x);
    m1=x;
    int temp;
    FOR(i,1,D-1)
    {
        temp=m1;
        scanf("%d",&x);
       m1=min(m1,x);
       if(m1==x)
       {
           m2=temp;
       }
       else if(m2>x)
       {
        m2=x;
       }
     }
      //printf("%d %d\n",m1,m2);
      if(min1==m1 && min1==m2)
        printf("N\n");
      else if(min1>=m2 && min1>m1)
        printf("N\n");
      else
        printf("Y\n");
}
    return 0;
}
