#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void subset(int start,int Num,int* arr,vector<int>& vect)
{
    int sum;
    for(int i=0;i<(1<<Num);i++)
    {
        sum=0;
        for(int j=0;j<Num;j++)
            if(i & (1<<j))
                sum+=arr[j+start];
        vect.push_back(sum);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int N,A,B,K;
    unsigned long long ans=0;
    vector<int> left,right;
    vector<int>::iterator low,high;
    int arr[50];

    cin>>N>>A>>B;
    for(int i=0;i<N;i++)
        cin>>arr[i];

    subset(0,N/2,arr,left);
    subset(N/2,N&1?N/2+1:N/2,arr,right);
    sort(right.begin(),right.end());

    for(int i=0;i<left.size();i++)
    {
        low=lower_bound(right.begin(),right.end(),A-left[i]);
        high=upper_bound(right.begin(),right.end(),B-left[i]);
        ans+=(high-right.begin())-(low-right.begin());
    }
    cout<<ans<<endl;

    return 0;
}
