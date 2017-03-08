#include<bits/stdc++.h>
using namespace std;
int  solve( int time[], int n) {
     if (n <=  2 )
         return time[n - 1 ];
     if (n ==  3 )
         return time[ 0 ] + time[ 1 ] + time[ 2 ];
     int normal =  2 * time[ 0 ] + time[n - 2 ] + time[n - 1 ];
     int alternative = time [ 0 ] +  2 * time[1] + time[n - 1 ];
     return min (normal, alternative) + solve(time, n - 2 );
}
int main()
{
     int c,n,a[1005];
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",solve(a,n));
    }
    return 0;
}
