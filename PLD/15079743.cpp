#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
const LL base=1007;
const int N=30005;
LL p[N],h[N],w[N];
char str[N];
LL getH(int l,int r)
{
    if(l>r) return 0;
    return h[r]-h[l-1]*p[r-l+1];
}
LL getW(int l,int r)
{
    if(l>r) return 0;
    return w[l]-w[r+1]*p[r-l+1];
}
int main()
{
    int k;
    scanf("%d",&k);
    scanf("%s",str);
    p[0]=1;
    int n=strlen(str);
    for(int i=1;i<=n;i++) p[i]=p[i-1]*base;
    h[0]=0,w[n+1]=0;
    for(int i=1;i<=n;i++) h[i]=h[i-1]*base+(LL)(str[i-1]);
    for(int i=n;i>=1;i--) w[i]=w[i+1]*base+(LL)(str[i-1]);
    int ans=0;
    for(int i=0;i<n-k+1;i++){
        //cout<<getH(i+1,i+k)<<" "<<getW(i+1,i+k)<<endl;
        if(getH(i+1,i+k)==getW(i+1,i+k))
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
