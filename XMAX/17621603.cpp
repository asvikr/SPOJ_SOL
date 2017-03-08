#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#define ull unsigned long long
#define testcases() int var;  cin>>var; while(var--)

int length(ull n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n>>=1;
    }
    return cnt;
}

int main()
{   
    
        int n;
        cin>>n;

        // input array --> a[]
        ull a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        // store how many bit is the ith number (bit-length) --> lengths[]
        int lengths[n]; 
        for(int i=0; i<n; i++)
            lengths[i] = length(a[i]);

        // put all numbers with same bit-length in one bucket --> buckets[]
        vector<ull> buckets[65];
        for(int i=0; i<n; i++)
            buckets[lengths[i]].push_back(a[i]);

        // this array will have a number from each bucket --> modified_array[]
        ull modified_array[100], m_index = 0;
        ull ans = 0;
        for(int i=64; i>0; i--) //since long long is 8 byte = 64 bit long
        {
            if(buckets[i].size()) //if there exist at least one element in bucket[i]
            {
                // put first value from bucket in modified_array[]
                modified_array[m_index++]=buckets[i][0];
                // and put remaining elements from same bucket again in corresponding 
                // buckets after ex-oring 
                for(int j=1; j<buckets[i].size(); j++)
                {
                    ull temp = buckets[i][0] ^ buckets[i][j];
                    int len = length(temp);
                    buckets[len].push_back(temp);
                }
            }
        
        }
        for(int i=0;i<m_index;i++) if((ans^modified_array[i])>ans) ans = ans^modified_array[i];
        cout<<ans<<endl;
    return 0;
}