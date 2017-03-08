#include<stdio.h>
int main()
{
  int t,fact[200],fac[200],i,n,temp,index,x,len;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d",&n);
      for(i=0;i<200;i++)
        fact[i]=0;
      fact[0]=1;
      temp=0;len=1;
      index=0;
      for(i=2;i<=n;i++)
      {
          temp=0;index=0;
          while(index<len)
          {
              x=fact[index]*i+temp;
              fact[index]=x%10;
              temp=x/10;
              index++;
          }
          while(temp>0)
          {
            fact[index++]=temp%10;
            temp=temp/10;
            len++;
          }

      }
      for(i=len-1;i>=0;i--)
        printf("%d",fact[i]);
      printf("\n");
  }
return 0;
}
