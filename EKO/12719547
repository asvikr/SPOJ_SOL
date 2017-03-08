#include"stdio.h"
#include"algorithm"
int arr[1000005] = {0};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&arr[i]);
	// insert a tree of height 0 to the list of trees to avoid edge case.
	std::sort(arr, arr+n+1); // can be done in linear time by radix sort
	long long sum = m; // amount of wood I need, after chopping upto height arr[i]
	for (int i=n; ; i--) {
		sum -= (arr[i]-arr[i-1])*1ll*(n+1-i); // amount of wood I need after chopping upto height arr[i-1]
		if (sum>0)
		    continue;
		printf("%d\n", arr[i-1] + (-sum)/(n+1-i));
		// I have (-sum) extra wood after cutting upto height arr[i-1] that I should try to distribute to as many trees as possible.
		return 0;
	}
}