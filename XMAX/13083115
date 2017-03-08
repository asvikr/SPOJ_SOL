#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long int LL;
using namespace std;
vector<LL> V(100005);
int main()
{
    int n;
    scanf("%d",&n);
    LL x;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        V.push_back(x);
    }
    sort(V.rbegin(),V.rend());
    LL sign=1;
    while(sign<=V[0])
        sign<<=1;
    sign>>=1;
    for(int t=0;sign>=1;sign>>=1)
    {
        int i=t;
        while(i<n && (sign&V[i])==0)
        i++;
        if(i>=n)
            continue;
        swap(V[t],V[i]);
        for(int j=0;j<n;j++)
        {
            if(j!=t && (V[j]&sign)!=0)
                V[j]^=V[t];
        }
        t++;
    }
    LL res=0;
    for(int i=0;i<n;i++)
    {
        res^=V[i];
    }
    printf("%lld\n",res);
    return 0;
}
