#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define f first
#define sc second
#define M 1000000007
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
int a[1005],pos[1005],b[1005];
int Map[100005],Map1[100005];
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
int main()
{
    int t;
    t=read();
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(pos,0,sizeof(pos));
        memset(Map,0,sizeof(Map));
        memset(Map1,0,sizeof(Map1));
        int n;
        n=read();
        vector<int> V[2005];
        for(int i=0;i<n;i++){
            a[i]=read();
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            pos[i]=read();
            maxi=max(pos[i],maxi);
            Map[a[i]]=pos[i];
            V[pos[i]].push_back(a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<=maxi;i++)
        sort(V[i].begin(),V[i].end());
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<V[i].size();j++){
                b[cnt]=V[i][j];
                Map1[V[i][j]]=cnt;
                cnt++;
            }
        }
        for(int i=n-1;i>=0;i--){
            int k=Map1[a[i]];
            cnt=0;
            for(int j=k-1;j>=0;j--){
                if(b[k]<b[j])
                    cnt++;
            }
            if(cnt==Map[a[i]])
                continue;
            else
            {
                if(cnt>Map[a[i]]){
                    cnt-=Map[a[i]];
                while(cnt){
                    if(b[k-1]>b[k] && (k-1>=0))
                    cnt--;
                    swap(b[k],b[k-1]);
                    k-=1;
                }
                }
                else
                {
                    cnt=Map[a[i]]-cnt;
                    while(cnt){
                    if(b[k+1]>b[k] && k+1<n)
                    cnt--;
                    swap(b[k],b[k+1]);
                    k+=1;
                }
                }
            }
            for(int tt=0;tt<n;tt++)
                Map1[b[tt]]=tt;
        }
        for(int i=0;i<n;i++)
            printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}

