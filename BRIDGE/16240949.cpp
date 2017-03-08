#include <algorithm>
#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;
int st[1003], fin[1003];
pair<int, int> edge[1003];
int dp[1003][2003];
int lis[1003];
int N;
int ans;

void LIS(){
    sort(edge, edge+N);
    ans = 0;
    for(int i=0;i<N;++i){
        lis[i] = 1;
        for(int j=i-1;j>=0;--j){
            if(edge[j].second <= edge[i].second){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ans = max(ans, lis[i]);
    }
    printf("%d\n", ans);
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%d", &st[i]);
        }
        for(int i=0;i<N;++i){
            scanf("%d", &fin[i]);
        }
        for(int i=0;i<N;++i){
            edge[i] = make_pair(st[i], fin[i]);
        }
        LIS();
    }
    return 0;
}