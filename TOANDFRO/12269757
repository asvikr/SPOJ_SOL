#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,i,j,l,r,k;
    char a[220],b[102][22];
    for(;;)
    {
      scanf("%d",&n);
      if(n==0)
        return 0;
        scanf("%s",a);
        l=strlen(a);
        r=l/n;j=-1;
        for(i=0;a[i]!='\0';i++)
        {
            k=i%n;
            if(k==0)
            {
                j++;
            }
                    if(j%2!=0)
                     b[j][n-k-1]=a[i];
                     else
                        b[j][k]=a[i];

        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<r;j++)
            {
                printf("%c",b[j][i]);
            }
        }
        printf("\n");
  }
  return 0;
}
