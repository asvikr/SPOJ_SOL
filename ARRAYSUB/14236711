#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int k;
    scanf("%d",&k);
    int ans[n];
    deque<int> Q;
    int i;
    for(i=0;i<k;i++)
    {
        while((!Q.empty()) && (a[i]>=a[Q.back()]))
            Q.pop_back();
        Q.push_back(i);
    }
    for(;i<n;i++)
    {
        ans[i-k]=a[Q.front()];
        while((!Q.empty()) && (Q.front()+k<=i))
            Q.pop_front();
         while((!Q.empty()) && (a[i]>=a[Q.back()]))
            Q.pop_back();
        Q.push_back(i);
    }
    ans[i-k]=a[Q.front()];
    for(int j=0;j<n-k+1;j++)
        printf("%d ",ans[j]);
    printf("\n");
    return 0;
}
