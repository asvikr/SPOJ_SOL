
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int mini[10005];
const int sz = 1000;
int main()
{
    int n,t,q;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        printf("Scenario #%d:\n",k);
    scanf("%d",&n);
     scanf("%d",&q);
    for(int i=0;i<1005;i++)
        mini[i]=INT_MAX;
    int prev=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
         if(i<prev+sz)
         cnt=cnt;
         else
         {
             cnt++;
             prev+=sz;
         }

        if(a[i]<mini[cnt])
        {
            mini[cnt]=a[i];
        }

    }
    /*printf("\n");
    for(int i=0;i<cnt;i++)
        printf("%d ",mini[i]);*/
    int l,r,st,en;
    while(q--)
    {
        scanf("%d %d",&l,&r);
        st=--l/sz;
        en=--r/sz;
        int m=INT_MAX;
        if(st==en)
        {

            for(int i=l;i<=r;i++)
            {
                if(a[i]<m)
                    m=a[i];
            }
            printf("%d\n",m);
        }
        else
        {
            for(int i=l;i<(st+1)*sz;i++)
                {
                    if(m>a[i])
                        m=a[i];
                }
            for(int i=st+1;i<en;i++)
            {
                if(m>mini[i])
                    m=mini[i];
            }
            for(int i=en*sz;i<=min(r,sz*(en+1)-1);i++)
                if(m>a[i])
                m=a[i];
            printf("%d\n",m);
        }
    }
    }
    return 0;
}
