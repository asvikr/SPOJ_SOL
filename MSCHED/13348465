#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     scanf("%d",&n);
     vector<pair<int,int> >v;
     int arr[100003]={0};
     while(n--)
     {
          int a,b;
          scanf("%d%d",&a,&b);
          v.push_back(make_pair(a,b));

     }
     sort(v.begin(),v.end());
     long long int ans=0;
     for(int i=v.size()-1;i>=0;i--)
     {
           int d=v[i].second;
           while(d)
           {
                  if(!arr[d])
                  {
                          arr[d]=1;
                          ans+=v[i].first;
                          break;
                  }
                  else
                     d--;
           }
     }
     printf("%lld\n",ans);
     return 0;
}
