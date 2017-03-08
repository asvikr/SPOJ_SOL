#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<cctype>
using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define INF 2000000000
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000

typedef long long LL;

string pat,txt;
int lps[1000000];
int n,m,b;

int computeLPSArray()
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < m)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
    return 0;
}

int KMPSearch()
{
    int j  = 0;  // index for pat[]

    int i = 0;  // index for txt[]
    while(i < n)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == m)
      {
          b=1;
        printf("%d\n", i-j);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    return 0;
}

int main()
{
    while(cin>>m)
    {
        b=0;
        cin>>pat;
        cin>>txt;
        n=txt.size();
        computeLPSArray();
        KMPSearch();
        if(b==0) printf("\n");
    }
    return 0;
}
