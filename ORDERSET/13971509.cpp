#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
    ordered_set S;
    int q;
    scanf("%d",&q);
    char str[2];
    int x;
    while(q--)
    {
        scanf("%s",str);
        scanf("%d",&x);
        if(str[0]=='I')
            S.insert(x);
        else if(str[0]=='D')
            S.erase(S.find(x));
        else if(str[0]=='C')
            printf("%d\n",S.order_of_key(x));
        else{
            int p=*S.find_by_order(x-1);
            if(p==0)
                printf("invalid\n");
            else
            printf("%d\n",p);
        }
    }
    return 0;
}
