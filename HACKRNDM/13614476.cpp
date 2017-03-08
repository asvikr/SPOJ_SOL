#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    map<int,int> M;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        M[a[i]]=1;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(M[a[i]-k]==1)
            ans+=1;
    }
    printf("%d\n",ans);
    return 0;
}
