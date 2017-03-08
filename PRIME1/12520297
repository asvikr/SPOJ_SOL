#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int arr[1000005];
main()
{
	int T,i,j;
	cin>>T;
	while(T--)
	{
		for(i=0;i<=1000000;i++)
		arr[i]=0;
		int M,N;
		cin>>M>>N;
		M=max(2,M);
		int X=sqrt(N);
		for(i=2;i<=X;i++)
		{
			int s=M/i;
			int t=N/i;
			for(j=max(s,2);j<=t+1;j++)
			{
				if(j*i>=M)
				arr[j*i - M]=1;
			}
		}
		for(i=0;i<=N-M;i++)
		{
			if(arr[i]==0)
			printf("%d\n",M+i);
		}
		printf("\n");
		
		
	}
	
} 