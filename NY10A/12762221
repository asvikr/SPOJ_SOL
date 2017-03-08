#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int t;
    map<int,int> S;

    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n=40;
        int p;
        scanf("%d",&p);
        char str[45];
        scanf("%s",str);
        int k=0;
    S[111]=0;
    S[112]=0;
    S[121]=0;
    S[122]=0;
    S[211]=0;
    S[212]=0;
    S[221]=0;
    S[222]=0;
        for(int j=0;j<=2;j++)
        {
        if(str[j]=='T')
            k=k*10+1;
        else
            k=k*10+2;
        }
        S[k]++;
        for(int j=3;str[j]!='\0';j++)
        {
            if(k/100==1)
                k=k-100;
            else
                k=k-200;
           if(str[j]=='T')
           {
               k=k*10+1;
               S[k]++;
           }
           else
           {
               k=k*10+2;
               S[k]++;
           }
        }
        printf("%d ",p);
        printf("%d %d %d %d %d %d %d %d\n",S[111],S[112],S[121],S[122],S[211],S[212],S[221],S[222]);
    }
    return 0;
}
