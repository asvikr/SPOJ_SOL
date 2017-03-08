#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int a[1000005],x;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        a[0]=0;
        multiset<int> s;
        s.insert(a[0]);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            a[i]=a[i-1]+x;
            s.insert(a[i]);
            int p=s.count(a[i]-47);
            cnt+=p;
        }
        printf("%d\n",cnt);
    }
}
