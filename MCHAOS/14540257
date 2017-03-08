#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <set>
#include <queue>
using namespace std;
#define i64 long long
#define maxn 100002
struct str
{
int p;
string s;
};
int n,np1;
str a[maxn],rev[maxn];
int tree[maxn];
int pos[maxn];
i64 ans=0;
char buff[13];
bool ca(const str &x,const str &y)
{
int d=strcmp(x.s.c_str(),y.s.c_str());
if(d<=0)
{
return true;
}
return false;
}
void update(int idx)
{
while(idx<=np1)
{
++tree[idx];
idx+=(idx & -idx);
}
}
int read(int idx)
{
int sum=0;
while(idx>0)
{
sum+=tree[idx];
idx-=(idx & -idx);
}
return sum;
}
int main()
{
//freopen("C:/Users/DR. MOON GUPTA/Desktop/Deepak/Programs/Spoj/Text/MCHAOS.txt","r",stdin);
int i,j,len;
scanf("%d",&n);
np1=n+1;
for(i=1;i<=n;++i)
{
scanf("%s",buff);
a[i].p=i;
a[i].s=string(buff);
rev[i].p=i;
//rev[i].s=string(buff);
//reverse(rev[i].s.begin(),rev[i].s.end());
len=strlen(buff);
reverse(buff,buff+len);
rev[i].s=string(buff);
}
sort(a+1,a+n+1,ca);
sort(rev+1,rev+n+1,ca);
/* for(i=1;i<=n;++i)
{
printf("%d\t%s\t\t%d\t%s\t\t%d\n",a[i].p,a[i].s.c_str(),rev[i].p,rev[i].s.c_str(),pos[i]);
}
*/
for(i=1;i<=n;++i)
{
pos[rev[i].p]=i;
}
update(pos[a[1].p]);
for(i=2;i<=n;++i)
{
ans+=read(np1)-read(pos[a[i].p]);
update(pos[a[i].p]);
}
printf("%lld\n",ans);
return 0;
}