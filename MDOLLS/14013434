#include <list>
#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iterator>
#include <cassert>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define int64 LL

typedef vector < int > VI;
typedef pair< int , int > pii;
typedef pair < LL , LL > PLL;
#define fr first
#define se second
#define pi M_PI
#define rad(x) (x)*acos(-1)/180.0
#define EPS 1e-6
#define INF 10000*10000*10000LL
stringstream ss;
#define two(x) ( 1LL<<x )
#define sq(x) ( (x)*(x) )
LL mod = 1000000007LL;

/**************************Code****************************/

vector < int > a[10010];
int all[20010], sz;

int main()
{
	int t, n;
	cin >> t;
	while( t -- )
	{
		for( int i = 0 ; i < 10001 ; i ++ )
			a[i].clear();
		scanf( "%d" , &n );
		for( int i = 0 ; i < n ; i ++ )
		{
			int h, w;
			scanf( "%d%d" , &h , &w );
			a[h].push_back( w );
		}
		for( int i = sz = 0 ; i < 10001 ; i ++ )
			if( a[i].size() )
			{
				sort( a[i].begin() , a[i].end() , greater < int > () );
				int j = 0, k = 0;
				while( j < a[i].size() )
				{
					while( k < sz && all[k] >= a[i][j] )
						k ++;
					if( k == sz )
						all[ sz++ ] = a[i][j ++];
					else
						all[k] = a[i][j ++];
					k ++;
				}
			}
		printf( "%d\n" , sz );
	}
	return 0;
}
