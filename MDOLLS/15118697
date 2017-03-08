#include<bits/stdc++.h>
using namespace std;
pair<int,int> dolls[20005];
vector<pair<int,int> > V;
bool cmp(const pair<int,int> a,const pair<int,int> b)
{
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        V.clear();
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d %d",&dolls[i].first,&dolls[i].second);
        }
        sort(dolls,dolls+m,cmp);
        V.push_back(dolls[m-1]);
        for(int i=m-2;i>=0;i--){
            int hi=V.size()-1,lo=0;
            while(hi>=lo){
                int mid=(hi+lo)/2;
                if(dolls[i].first==V[mid].first || dolls[i].second>=V[mid].second)
                    lo=mid+1;
                else
                    hi=mid-1;
            }
            if(lo==V.size()){
                V.push_back(dolls[i]);
            }else{
              V[lo].first=dolls[i].first;
              V[lo].second=dolls[i].second;
            }
        }
        printf("%d\n",V.size());
    }
    return 0;
}
