
#include <bits/stdc++.h>
using namespace std;
char s[10005];
int main()
{
 int t,i=1,j;
 string s,s1;
 bool check=true;
 scanf("%d",&t);
 getline(cin,s);
 while(t--)
 {
  set< string > q;
  getline(cin,s);
  istringstream iss(s);
  do
  {
   string sub;
   iss>>sub;
   q.insert(sub);
  }while(iss);
  cout<<q.size()-1<<"\n";
  q.clear();
 }
 return 0;
}