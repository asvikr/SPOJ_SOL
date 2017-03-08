#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string txt,pat;
        cin>>txt>>pat;
        int l=txt.size();
        int j=0,x;
        for(int i=0;i<l;i++)
        {
            x=txt.find(pat,i);
            if(x>=0 && x<l)
                a[j++]=x+1;
            else
            {
                break;
            }
            i=x;
        }
        if(j==0){
            printf("Not Found\n");
            continue;
        }
        printf("%d\n",j);
        for(int i=0;i<j;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
