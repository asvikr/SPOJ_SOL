#include<bits/stdc++.h>
using namespace std;
#define M  98765431
typedef long long int LL;
const int N=50005;
LL C[N];
int n,t;
pair<LL,LL> solve(int t)
{
    LL ret[2][2]={{0,n-1},{1,n-2}};
    LL mat[2][2]={{1,0},{0,1}};
    LL temp[2][2];
    while(t>0){
        memset(temp,0,sizeof(temp));
        if(t&1){
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                   for(int k=0;k<2;k++)
                   temp[i][j]=(temp[i][j]+ret[i][k]*mat[k][j])%M;
           for(int i=0;i<2;i++) for(int j=0;j<2;j++)
            mat[i][j]=temp[i][j];
        }
        memset(temp,0,sizeof(temp));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
              for(int k=0;k<2;k++)
                temp[i][j]=(temp[i][j]+ret[i][k]*ret[k][j])%M;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++)
            ret[i][j]=temp[i][j];
            t/=2;
    }
    return make_pair(mat[0][0],mat[1][0]);
}
int main()
{
    scanf("%d %d",&n,&t);
    LL sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&C[i]);
        sum=(sum+C[i])%M;
    }
    pair<LL,LL> res=solve(t);
    LL ans;
    for(int i=0;i<n;i++){
        ans=((res.first*C[i])%M+(res.second*(sum-C[i]+M))%M)%M;
        printf("%lld\n",ans);
    }
    return 0;
}
