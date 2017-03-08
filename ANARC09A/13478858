#include<stdio.h>
int main()
{
 int T=1;
 while(1){
  char S[2001],ch;
  int top=0,count=0,i=0;
  scanf("%s",S);
  if(S[0]=='-')
   break;
  while(S[i]!='\0')
  {
   ch=S[i];
   if(ch==123)
    ++top;
   else if(ch==125 && top==0)
   {
    count+=1;
    ++top;
   }
   else
    top--;
   i++;
  }
  printf("%d. %d\n",T++,(top/2)+count);
 }
 return 0;
}