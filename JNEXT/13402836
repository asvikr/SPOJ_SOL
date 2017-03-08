#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
            int temp=1;
            int mini,i;
        for(i=n-1;i>0;i--)
        {
            if(a[i-1]<a[i])
            {
                int chk=1;
                mini=i-1;
                for(int j=i;j<n;j++)
                {
                    if((a[i-1]<a[j]) && (chk==1))
                    {
                        mini=j;
                        chk=0;
                    }
                    else if((a[mini]>a[j]) && (a[j]>a[i-1]) && (chk==0))
                    {
                      mini=j;
                    }
                }
                 //printf("%d %d\n",a[mini],a[i-1]);
                swap(a[i-1],a[mini]);
                //printf("%d %d\n",a[mini],a[i-1]);
                temp=0;
                break;

            }
        }
        if(temp==1)
            printf("-1");
        else
        {
            sort(a+i,a+n);
        for(int i=0;i<n;i++)
            printf("%d",a[i]);
        }
            printf("\n");
    }
    return 0;
}
