#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long int LL;
using namespace std;
void mergesort(int i,int j);
void merge(int i,int j);
long long a[200009],b[200009];
long long c;
int main()
{
        int t,n,i;
        scanf("%d",&t);
        printf("\n");
        while(t--) {
                scanf("%d",&n);
                for(i=0;i<n;i++)
                scanf("%lld",&a[i]);
                c=0;
                mergesort(0,n-1);
                printf("%lld\n",c);
                printf("\n");
                }
        return 0;
}

void mergesort(int i,int j)
{
        if(i>=j)
                return;
        else {
                int mid=(i+j)/2;
                mergesort(i,mid);
                mergesort(mid+1,j);
                merge(i,j);
                }
        return;
}

void merge(int i,int j)
{
        int mid=(i+j)/2,k=i;
        int l,r;
        l=i;r=mid+1;
        while(l<=mid && r<=j) {
                if(a[l]<=a[r])
                        b[k++]=a[l++];
                else {
                        c=c+mid-l+1;
                        b[k++]=a[r++];
                        }
                }
        if(l>mid)
                while(r<=j)
                        b[k++]=a[r++];
        else if(r>j)
                while(l<=mid)
                        b[k++]=a[l++];
        for(l=i;l<=j;l++)
                a[l]=b[l];
}
