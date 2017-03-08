#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long LL;
const int MAX_N=10000005;
int mob[MAX_N];
int sum[MAX_N];
bool mark[MAX_N];
void init(){
	for(int i=1;i<MAX_N;i++) mark[i]=false,mob[i]=1;
    for(int i=2;i<MAX_N;i++){
        if(!mark[i]){
            mob[i]=-1;
            for(int j=2;i*j<MAX_N;j++){
                mark[i*j]=1;
                if(j%i==0) mob[i*j]=0;
                else mob[i*j]*=-1;
            }
        }
    }
    for(int i=1;i<MAX_N;i++){
        sum[i]=sum[i-1]+mob[i];
    }
}

int main(){
	int T;
	LL N,ans;
	scanf("%d",&T);
	init();
	while (T--){
		scanf("%lld",&N);
		ans=0;
		LL n=sqrt(N);
		LL j,k;
		for (LL i=1;i<=n;){
           // ans+=(LL)mob[i]*N/(i*i);
            // lets do some optimisztion
            j=N/(i*i);
            k=sqrt(N/j);
            ans+=(sum[k]-sum[i-1])*j;
            i=k+1;
		}
        printf("%lld\n",ans);
	}
	return 0;
}

