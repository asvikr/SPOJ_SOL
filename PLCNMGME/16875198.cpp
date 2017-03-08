#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define M 100000007
typedef long long LL;
const int N=1005;
int dp[1<<21];
int cnt[26];
int grid[21][21];
int n;
int solve(int i,int mask)
{
	if(i==21) return 1;
	int &res=dp[mask];
	if(res!=-1) return res;
	res=0;
	for(int x=0;x<21;x++){
		if(!(mask & (1<<x)) && (grid[i][x])){
			res+=grid[i][x]*solve(i+1,mask | (1<<x));
			res%=M;
		}
	}
return res;
}

int main()
{
	int c=0;
	for(int i=0;i<26;i++){
		if(i+'a'=='a' || i+'a'=='e' || i+'a'=='i' || i+'a'=='o' || i+'a'=='u') continue;
		cnt[i]=c++;
	}
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	char str[12];
	for(int i=0;i<n;i++){
		scanf("%s",str);
		int k=strlen(str);
		int u = cnt[(str[0]-'A')];
		int v = cnt[(str[k-1]-'A')];
		grid[u][v]++;
	}

	printf("%d\n",solve(0,0));
}