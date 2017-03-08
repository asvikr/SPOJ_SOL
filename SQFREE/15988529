#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long LL;
const int MAX_N=10000001;
int n,m,cnt;
int P[MAX_N],c[MAX_N],u[MAX_N],su[MAX_N];
LL ans;

void init(){
	u[1]=1;
	su[1]=1; 
	for (int i=2;i<MAX_N;i++){
		if (!c[i]){
			c[i]=i;
			u[i]=-1;
			P[++cnt]=i;
		}
		int x=(MAX_N-1)/i;
		for (int j=1;j<=cnt && P[j]<=x;j++){
			c[i*P[j]]=P[j];
			if (c[i]==P[j]) u[i*P[j]]=0;
						else u[i*P[j]]=-u[i];
			if (c[i]==P[j]) break;
		}
		su[i]=su[i-1]+u[i];
	}
}

int main(){
	int T;
	LL N,ans;
	scanf("%d",&T);
	init();
	while (T--){
		cin>>N;
		ans=0;
		int n=(int)sqrt(N);
		for (int i=1;i<=n;){
			LL nn=(N/((LL)i*i));
			int nt=((int)sqrt(N/nn)+1);
			ans+=(su[nt-1]-su[i-1])*nn;
			i=nt;
		}
		cout<<ans<<endl;
	}
} 