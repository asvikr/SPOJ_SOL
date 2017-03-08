#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int num[1005];
int solve(string str,int n)
{
    //printf("%d %d\n",cnt,n);
    if(str[cnt]=='l')
        return 0;
    cnt+=1;
    int p=solve(str,n+1)+1;
    cnt+=1;
    int q=solve(str,n+1)+1;
   // printf("p q %d %d\n",p,q);
    num[n]=max(num[n+1],num[n+2])+1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        string str;
        cin>>str;
        solve(str,0);
        printf("%d\n",num[0]);
      /*  for(int i=0;i<5;i++)
            printf("%d ",num[i]);
        printf("\n");*/
        memset(num,0,sizeof(num));
        cnt=0;
    }
    return 0;
}
