#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL dp[55],sum[55];
string solve(LL k,string s)
{
    if(k==1) return s+'5';
    if(k==2) return s+'6';
    int p=lower_bound(sum,sum+52,k)-sum;
    LL diff=k-sum[p-1];
    LL to=sum[p]-sum[p-1];
    //printf("%lld %lld %lld\n",diff,to,sum[p-1]);
    if(diff>to/2){
       return solve(sum[p-2]+diff-to/2,s+'6');
    }
    else
    {
        return solve(sum[p-2]+k-sum[p-1],s+'5');
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    LL k;
    dp[1]=2;
    dp[2]=4;
    sum[1]=2;
    sum[2]=6;
    for(int i=3;i<=51;i++){
        dp[i]=dp[i-1]*2;
        sum[i]=sum[i-1]+dp[i];
    }
    while(n--){
    scanf("%lld",&k);
    string str=solve(k,"");
    cout<<str<<endl;
    }
    return 0;
}
