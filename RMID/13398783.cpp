#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n,count=0,pos=0,check=1,i=0;
 list<int>l;
 list<int>::iterator t,t1,t2,temp;
 t=l.begin();
 while(scanf("%d",&n)!=EOF)
 {
  if(n== -1)
  {
   printf("%d\n",(*t));
   temp=t;
   t++;
   t1=t;
   t--;
   if(t!=l.begin())
    t--;
   t2=t;
   l.erase(temp);
   if(count&1)
    t=t2;
   else
    t=t1;
   count--;
  }
  else if(n==0)
  {
   count=0;
   l.clear();
   t=l.begin();
   printf("\n");
  }
  else
  {
   l.push_back(n);
   count++;
   if(count&1)
    t++;
  }
 }
 return 0;
}