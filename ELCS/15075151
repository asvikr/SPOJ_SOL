#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
const LL base=10007;
const int N=500005;
LL p[N];
int L[N];
vector<LL> h[N];
LL getH(int l,int r,int i)
{
    if(l>r) return 0;
    return h[i][r]-h[i][l-1]*p[r-l+1];
}
int solve(int i,int j)
{
    int l=0,r=min(L[i],L[j])-1;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(getH(1,mid+1,i)==getH(1,mid+1,j))
            l=mid;
        else r=mid-1;
    }
   // printf("%d\n",l);
  // cout<<getH(1,l+1,i)<<" "<<getH(1,l+1,j)<<endl;
    if(getH(1,l+1,i)==getH(1,l+1,j))
        return l+1;
    else return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    p[0]=1;
    for(int i=1;i<N;i++) p[i]=p[i-1]*base;
    char str[N];
    for(int i=0;i<t;i++){
        scanf("%s",str);
        int len=strlen(str);
        L[i]=len;
        h[i].resize(len+1);
        h[i][0]=0;
        for(int j=1;j<=len;j++){
            h[i][j]=h[i][j-1]*base+(LL)(str[j-1]);
           // cout<<h[i][j]<<" ";
        }
        //cout<<endl;
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        int ans=solve(l,r);
        printf("%d\n",ans);
    }
    return 0;
}
