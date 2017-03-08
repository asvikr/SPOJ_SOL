#include<bits/stdc++.h>
using namespace std;
int a[102];
int clc(int x)
{
    if(x<=4)
        return 1;
    if(x==5)
        return 2;
    if(x==6)
        return 3;
    if(x==7)
        return 5;
    if(x>7)
        return 11;
}
int main()
{
    int t;
    scanf("%d",&t);
    string str,temp;
    getline(cin,str);
    map<string,int> M1,M2;
    for(int i=1;i<=t;i++)
    {
        getline(cin,str);
        istringstream ss(str);
        while(ss >> temp)
        {
            M1[temp]+=1;
            M2[temp]=i;
        }
    }
    map<string,int> :: iterator it;
    for(it=M1.begin();it!=M1.end();it++)
    {
        if(it->second==1)
        {
            a[M2[it->first]]+=clc(it->first.size());
        }
    }
    int maxi=-1;
    for(int i=1;i<=t;i++)
        if(maxi<a[i])
        maxi=a[i];
    printf("%d\n",maxi);
    return 0;
}
