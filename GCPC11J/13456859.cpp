#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
 
vector<int> V[100100];
int vis[100100],dist[100100],k;
void dfs(int v,int n)
  {
 
            vis[v]=1;
            dist[v]=n;
            for(int u=0;u<V[v].size();u++)
             if(!vis[V[v][u]])
               dfs(V[v][u],n+1);
 
 }
 
int main()
  {
          int n,t1,t2 , t;
          for(scanf("%d",&t) ;t > 0 ; t-- )
            {
         scanf("%d",&n);
                 for(int i=0;i<n;i++)
                  V[i].clear(),vis[i]=0;
 
                 for(int i=0;i<n-1;i++)
                  {
                         scanf("%d%d",&t1,&t2);
                         V[t1].push_back(t2);
                         V[t2].push_back(t1);
                  }
          
         //if(n==2) { cout<<"1\n";continue;}
 
                 dist[0]=0;
                 dfs(0,0);
                 /* for(int i=0;i<n;i++)
                  cout<<dist[i]<<" ";
                  cout<<endl;*/
 
                 int node=0;
                 for(int i=0;i<n;i++)
                  if(dist[i]>dist[node])
                    node=i;
 
                 memset(vis,0,sizeof(vis));
                // cout<<"node"<<node<<endl;
 
                 dfs(node,0);
 
                 /*for(int i=0;i<n;i++)
                  cout<<dist[i]<<" ";
                  cout<<endl;*/
 
                 sort(dist,dist+n);
         int d = dist[n-1];
         if( d & 1 ) cout<< ( d>>1 ) + 1 <<endl;
         else cout<< ( d>>1 ) <<endl;
                 //cout<<dist[n-1]<<endl;
 
            }
 }