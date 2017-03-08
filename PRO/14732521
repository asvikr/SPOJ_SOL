#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
int main()
{
	int n,k,x;
	scanf("%d",&n);
	multiset<int> S;
	LL ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&x);
			S.insert(x);
		}
		ans+=(LL)(*S.rbegin()-*S.begin());
		S.erase(S.begin());
		multiset<int> :: iterator it=S.end();
		it--;
		S.erase(it);
	}
	printf("%lld\n",ans);
	return 0;
}