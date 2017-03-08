#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
string str,str1;
vector<int> Z(N);
int n;
void z_algo()
{
    int L=0,R=0;
    Z[0]=0;
    for(int i=1;i<n;i++){
        if(i>R){
            L=R=i;
            while(R<n && (str1[R-L]==str1[R])) R++;
            Z[i]=R-L,R--;
        }
        else
        {
            int k=i-L;
            if(R-i+1>Z[k]) Z[i]=Z[k];
            else
            {
                L=i;
                while(R<n && (str1[R-L]==str1[R])) R++;
                Z[i]=R-L,R--;
            }
        }
        //printf("%d ",Z[i]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
      cin>>str;
      str1=str;
      int len=str.size();
      reverse(str1.begin(),str1.end());
      str1+='$'+str1;
      n=str1.size();
      z_algo();
      int q;
      scanf("%d",&q);
      while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",Z[n-x]);
      }
    }
    return 0;
}
