#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        printf("\n");
        int n;
        char s[10000];
        scanf("%d\n",&n);
        map<string,int> M;
        for(int i=0;i<n;i++)
        {
            gets(s);
            M[(string)s]++;
        }
        map<string,int> :: iterator it;
        for(it=M.begin();it!=M.end();it++)
            printf("%s %d\n",it->first.c_str(),it->second);
    }
}
