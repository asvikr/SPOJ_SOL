#include <bits/stdc++.h>
using namespace std;
const int N=200009;
struct state
{
	int fpos;
	int len,link;
	int next[26];
}st[2*N];
string str;
int last,sz;
int n;
void init()
{
	sz=last=0;
	st[sz].len=0;
	st[sz].link=-1;
	st[sz].fpos=0;
	++sz;
}
void sz_extend(int i)
{
	int c=str[i]-'a';
	int cur=sz++;
	st[cur].fpos=i+1;
	st[cur].len=st[last].len+1;
	int p;

	for(p=last;p!=-1 && !st[p].next[c];p=st[p].link)
		st[p].next[c]=cur;

	if(p==-1) st[cur].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len) st[cur].link=q;
		else {
			int clone=sz++;
			st[clone].len=st[p].len+1;
			st[clone].link=st[q].link;
			st[clone].fpos=st[q].fpos;
			memcpy(st[clone].next,st[q].next,sizeof st[q].next);
			for(;p!=-1 && st[p].next[c]==q;p=st[p].link) st[p].next[c]=clone;

			st[q].link=st[cur].link=clone;	
		}
	}
	last=cur;
}
int tp=0;
void solve(int pos)
{
	for(int i=0;i<26;i++)
		if(st[pos].next[i]) {
			tp++;
			if(tp==n+1) {
				printf("%d\n",st[pos].fpos-n);
				break;
			}
			solve(st[pos].next[i]);
			break;
		}
}
int main()
{
		init();
		cin>>str;
		n=str.size();
		str+=str;
		for(int i=0;i<2*n;i++) sz_extend(i);
		solve(0);
	return 0;
} 