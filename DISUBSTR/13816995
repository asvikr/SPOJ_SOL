#include<bits/stdc++.h>
using namespace std;
#define MAXN 65536
#define MAXLG 17
struct entry
{
    int nr[2];
    int p;
}L[MAXN];
char A[MAXN];
int P[MAXLG][MAXN];
int n,stp,cnt;
int cmp(struct entry a,struct entry b)
{
    return a.nr[0]==b.nr[0]?((a.nr[1]<b.nr[1])?1:0):(a.nr[0]<b.nr[0]?1:0);
}
int lcp(int x,int y)
{
    //printf("%d %d\n",x,y);
    int ret=0;
    if (x ==y) return n- x;
    for(int k=stp-1;k>=0;k--)
    {
     // printf("%d %d\n",P[k][x],P[k][y]);
        if(P[k][x]==P[k][y]){
                //printf("hello\n");
            ret+=1<<k;
            x+=1<<k;
            y+=1<<k;
            if(x>=n || y>=n)
                return ret;
        }
    }
    return ret;
}
int LCParray()
{
   //printf("%d\n",n);
    int sum=0;
    for(int i=1;i<n;i++){
           // printf("%d %d\n",L[i].p,L[i-1].p);
        sum+=lcp(L[i].p,L[i-1].p);
    }
        //printf("%d\n",sum);
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%s",A);
     n=strlen(A);
    for(int i=0;i<n;i++)
        P[0][i]=A[i]-'a';
    stp=1;
    for(cnt=1;cnt<n;cnt*=2)
    {
        for(int i=0;i<n;i++)
        {
            L[i].nr[0]=P[stp-1][i];
            L[i].nr[1]=i+cnt<n?P[stp-1][i+cnt]:-1;
            L[i].p=i;
        }
        sort(L,L+n,cmp);
        for(int i=0;i<n;i++)
        {
            P[stp][L[i].p]=i>0 && (L[i].nr[0]==L[i-1].nr[0]) && (L[i].nr[1]==L[i-1].nr[1]) ? P[stp][L[i-1].p]:i;
        }
        stp++;
    }
    int lcpsum=LCParray();
    printf("%d\n",(n*(n+1))/2-lcpsum);
    }
    return 0;
}
