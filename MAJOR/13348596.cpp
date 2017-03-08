#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x,temp=0;
        map<int,int> M;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            M[x]++;
            if(M[x]>n/2)
                temp=x;
        }
        if(temp!=0)
            printf("YES %d\n",temp);
        else
            printf("NO\n");
    }
    return 0;
}
