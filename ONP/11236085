#include<stdio.h>
int main()
{
char stack[405],str[405];
int i,j=0,n;
scanf("%d",&n);
while(n--)
{
scanf("%s",str);
for(i=0;str[i]!='\0';i++)
{
if(str[i]=='(')
continue;
else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='^' || str[i]=='/')
{
    stack[j]=str[i];
    j++;
}
else if(str[i]==')')
{
    j--;
    printf("%c",stack[j]);
 
}
else
    printf("%c",str[i]);
}
printf("\n");
}
return 0;
}