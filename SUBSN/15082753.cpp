#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
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
	int ret = 0;
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
string S;
vector<int> occ[26];
int main()
{
    int t;
    scanf("%d",&t);
    getline(cin,S);
    for(int tt=1;tt<=t;tt++)
    {
        printf("Case %d:\n",tt);
        getline(cin,S);
        int n=S.size();
        for(int i=0;i<26;i++) occ[i].clear();
        for(int i=0;i<n;i++)
            occ[S[i]-'a'].pb(i);
        int q;
        scanf("%d",&q);
        string str;
        getline(cin,str);
        while(q--)
        {
          getline(cin,str);
          bool temp=true;
          int m=str.size();
          int prev=-1;
          for(int i=0;i<m;i++){
            int pos=lower_bound(occ[str[i]-'a'].begin(),occ[str[i]-'a'].end(),prev+1)-occ[str[i]-'a'].begin();
            if(pos!=occ[str[i]-'a'].size()){
                prev=occ[str[i]-'a'][pos];
            }
            else{
                temp=false;
                break;
            }
          }
          if(temp) puts("YES");
          else puts("NO");
        }
    }
    return 0;
}
