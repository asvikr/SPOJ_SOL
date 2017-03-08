#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
const LL base=10007;
const int N=200005;
LL p[N],h[N],w[N];
LL getH(int l,int r)
{
    if(l>r) return 0;
    return h[r]-h[l-1]*p[r-l+1];
}
LL getW(int l,int r)
{
    if(l>r) return 0;
    return w[l]-w[r+1]*p[r-l+1];
}
int main()
{
    p[0]=1;
    for(int i=1;i<N/2;i++) p[i]=p[i-1]*base;
    char str[N];
    while(scanf("%s",str)!=EOF){
        int n=strlen(str);
        h[0]=0;
        w[n+1]=0;
        for(int i=1;i<=n;i++){
            h[i]=h[i-1]*base+(LL)(str[i-1]);
        }
        for(int i=n;i>=1;i--){
            w[i]=w[i+1]*base+(LL)(str[i-1]);
        }
        string s="";
        for(int i=1;i<=n;i++){
            if(getH(i,n)==getW(i,n)){
                if(s.size()==0){
                    printf("%s\n",str);
                }
                else
                {
                    reverse(s.begin(),s.end());
                        int sz=s.size();
                        int j=0;
                    for(int i=n;i<n+sz;i++){
                        str[i]=s[j++];
                    }
                    str[n+sz]='\0';
                    printf("%s\n",str);
                }
                break;
            }
            s+=str[i-1];
        }
    }
    return 0;
}
