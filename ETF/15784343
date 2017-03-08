#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long int t,phi[1001000];
	 long int i,j;
	cin>>t;
	for(i=1;i<=1000000;i++)
	    {
	        phi[i]=i;
	    }
	    for(i=2;i<=1000000;i++)
	    {
	        if(phi[i]==i)
	        {
	            for(j=i;j<=1000000;j+=i)
	            {
	                phi[j]-=phi[j]/i;
	            }
	        }
	    }
	while(t--)
	{
	    long int n;
	    cin>>n;
	    cout<<phi[n]<<endl;
	}
	return 0;
}
