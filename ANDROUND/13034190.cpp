#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
 
using namespace std;
 
const bool debug=true;
 
#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define PB 			push_back
#define SZ(x)		((int)((x).size()))
#define TR(i,x) 	for(i=0;i<(x).size();++i)
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;
#define HELLO		if(debug) puts("hello");
#define LL 			long long
#define INF			0x3f3f3f3f
#define M			20009
 
int tree[4*M];
int a[M];
int n,k;
 
int init(int node,int s,int e)
{
	if(e<s)
		return -1;
	if(e==s)
		return tree[node]=a[s];
	int m=(e+s)/2;
	return tree[node]=(init(node*2,s,m) & init(node*2+1,m+1,e));
}
 
int query(int node,int s,int e,int qs,int qe)
{
	if( s > qe || e < qs )
		return -1;
	if( qs <= s && e <=qe )
		return tree[node];
 
	int m = (s+e)/2;
	return query(node*2,s,m,qs,qe) & query(node*2+1,m+1,e,qs,qe);
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		if(k>=n/2)
		{
			int ans=a[0];
			for(int i=1;i<n;++i)
			{
				ans &= a[i];
			}
			for(int i=0;i<n;++i)
				printf("%d ",ans);
			puts("");
			continue;
		}
		init(1,0,n-1);
		for(int i=0;i<n;++i)
		{
			int s=(i-k+n)%n;
			int e=(i+k)%n;
			int ans;
			if(s<e)
				ans=query(1,0,n-1,s,e);
			else
				ans=query(1,0,n-1,0,e) & query(1,0,n-1,s,n-1);
			printf("%d ",ans);
		}
		puts("");
	}
	return 0;
}
 