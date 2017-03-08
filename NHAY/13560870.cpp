#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        string pat,txt;
        cin>>pat;
        cin>>txt;
        int l=pat.size();
        int m=txt.size();
        if(l>m)
        {
            printf("\n");
        }
        else
        {
        for(int i=0;i<m;i++)
        {
        int k=txt.find(pat,i);
        if(k>=0 && k<m)
        printf("%d\n",k);
        else
            break;
        i=k;
        }
        }
        printf("\n");
    }
    return 0;
}
