#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
typedef long long int LL;
#define pb push_back
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
const int N = 300005;
int n,m;
LL bit[N];
int qval[N],ql[N],qr[N];

void upd(int x,int val) {
	while(x<=m){
		bit[x]+=val;
		x+=x&-x;
	}
}

LL query(int x) {
	LL ret = 0;
	while(x>0) {
		ret += bit[x];
		x-=x&-x;
	}
	return ret;
}

void update(int l,int r,int val) {
	//printf("hel %d\n",m);
	if(l<=r) {
		upd(l,val);
		upd(r+1,-val);
	} else {
		upd(1,val);
		upd(r+1,-val);
		upd(l,val);
	}
	//for(int i=1;i<=m;i++) printf("xx %lld ",bit[i]);
}

vector<int> range_id[N];
vector<int> owner[N];
int hi[N],lo[N];
LL req[N];
int main() 
{

	n=read();m=read();
	for(int i=1;i<=m;i++) {
		int x=read();
		owner[x].pb(i);
	}
	for(int i=1;i<=n;i++) {
		req[i] = read();
		//printf("%lld ",req[i]);
	}

	int q = read();
	
	for(int i=1;i<=q;i++){
		ql[i] = read();
		qr[i] = read();
		qval[i] = read();
	}
	for(int i=1;i<=n;i++) {
		lo[i]=1;
		hi[i]=q+1;
	}
	bool change = true;
	while(change) {
		change = false;

		for(int i=1;i<=m;i++) bit[i] = 0;
		for(int i=1;i<=n;i++) if(hi[i]!=lo[i]) range_id[(lo[i]+hi[i])>>1].pb(i);

		for(int k=1;k<=q;k++) {
			//printf("%d %d %d\n",ql[k],qr[k],qval[k]);
			update(ql[k],qr[k],qval[k]);
			
			
			while((int)range_id[k].size()) {
				change = true;
				int id = range_id[k].back();
				range_id[k].pop_back();
				LL sum = 0;
				
				for(int sectors:owner[id]) {
					
					sum+=query(sectors);
					if(sum>=req[id]) break;
				}
				
				if(sum>=req[id]) {
					hi[id] = k;
				} else {
					lo[id] = k+1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(lo[i]<=q) {
			printf("%d\n",lo[i]);
		} else {
			printf("NIE\n");
		}
	}
	return 0;
}