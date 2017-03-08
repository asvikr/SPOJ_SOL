#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,int> > V(n);
        for(int i=0;i<n;i++){
              int x;
              scanf("%d",&x);
              V[i].first=x;
        }
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            V[i].second=x;
        }
        sort(V.rbegin(),V.rend());
        list<int> mylist;
         mylist.push_back(V[0].first);
        for(int i=1;i<n;i++){
        int h=V[i].first;
        int p=V[i].second;
        list<int> :: iterator it;
        for(it=mylist.begin();it!=mylist.end();it++){
            if(p==0) break;
            else p-=1;
        }
        mylist.insert(it,h);
    }
     vector<int> ans;
    list<int> :: iterator it;
        for(it=mylist.begin();it!=mylist.end();it++){
           printf("%d ",*it);
        }
     printf("\n");
    }
}
