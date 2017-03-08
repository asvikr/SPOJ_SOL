#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    char str[1000005];
    while(1)
    {
        scanf("%d %s",&k,str);
        if(k==-1 && str[0]=='*')
            return 0;
        int l=strlen(str);
        if(k<l)
        {
            printf("0\n");
            continue;
        }
        int lps[l];
        lps[0]=0;
        int i=1,k1=0;
        while(i<l)
        {
            if(str[i]==str[k1])
                lps[i++]=++k1;
            else
            {
                if(k1!=0)
                    k1=lps[k1-1];
                else
                    lps[i++]=0;
            }
        }
        int p=lps[l-1];
        //printf("%d\n",p);
        int ans=(k-p)/(l-p);
        printf("%d\n",ans);
    }
    return 0;
}
