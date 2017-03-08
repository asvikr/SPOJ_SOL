#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
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
const int N=50005;
struct node
{
	int x,y;
}points[N];

int topleft[N],bottomright[N],bottomleft[N],topright[N];

bool cmp(node u,node v)
{
	if(u.x==v.x) return u.y<v.y;
	return u.x<v.x;
}

bool cmpx(node u,node v)
{
	if(u.x==v.x) return u.y>v.y;
	return u.x<v.x;
}
int X[N],Y[N];
int bit[N];
int query(int x)
{
	int ret = 0;
	while(x>0){

		ret += bit[x];
		x -= x&-x;
	}
	return ret;
}
void upd(int x)
{
	while(x<N){
		bit[x] += 1;
		x += x&-x;
	}

}
int cx[N],cy[N];
LL nc3(LL x)
{
	return (x*(x-1)*(x-2))/6;
}
int main()
{
	int t;
	t=read();
	while(t--){
		memset(bit,0,sizeof bit);
		memset(cx,0,sizeof cx);
		memset(cy,0,sizeof cy);
		memset(topright,0,sizeof topright);
		memset(topleft,0,sizeof topleft);
		memset(bottomright,0,sizeof bottomright);
		memset(bottomleft,0,sizeof bottomleft);

		int n=read();
		for(int i=0;i<n;i++){
			X[i]=read();Y[i]=read();
			points[i].x=X[i];
			points[i].y=Y[i];
		}
		LL ans=0;
		sort(X,X+n);sort(Y,Y+n);
		for(int i=0;i<n;i++){
			points[i].x = lower_bound(X,X+n,points[i].x)-X+1;
			cx[points[i].x]++;
			points[i].y = lower_bound(Y,Y+n,points[i].y)-Y+1;
			cy[points[i].y]++;
		}
		for(int i=1;i<N;i++){
			ans -= nc3(cx[i]);
			ans -= nc3(cy[i]);
		}
		sort(points,points+n,cmp);

		for(int i=0;i<n;i++){
			bottomleft[i] = query(points[i].y);
			upd(points[i].y);
		}
		memset(bit,0,sizeof bit);
		for(int i=n-1;i>=0;i--){
			topright[i] = query(N-1)-query(points[i].y-1);
			upd(points[i].y);
		}
		sort(points,points+n,cmpx);
		memset(bit,0,sizeof bit);
		for(int i=0;i<n;i++){
			topleft[i] = query(N-1)-query(points[i].y-1);
			upd(points[i].y);
		}
		memset(bit,0,sizeof bit);
		for(int i=n-1;i>=0;i--){
			bottomright[i] = query(points[i].y);
			upd(points[i].y);
		}
		
		for(int i=0;i<n;i++) {
		//	printf("%d %d\n",points[i].x,points[i].y);
			//printf("%d %d %d %d\n",topleft[i],bottomright[i],topright[i],bottomleft[i]);
			ans += topleft[i]*1LL*bottomright[i] + topright[i]*1LL*bottomleft[i];
		}
		printf("%lld\n",ans*2);
	}


}
