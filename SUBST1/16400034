#include <bits/stdc++.h>
using namespace std;
const int N=50009;
struct state
{
	int len,link;
	int next[26];
}st[2*N];
char str[N];
int last,sz;
int n;
vector<int> d(2*N,0);
void init()
{
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<26;j++) st[i].next[j]=0;
		d[i]=0;
	}
	sz=last=0;
	st[sz].len=0;
	st[sz].link=-1;
	++sz;
}
void sz_extend(int i)
{
	int c=str[i]-'a';
	int cur=sz++;
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
			memcpy(st[clone].next,st[q].next,sizeof st[q].next);
			for(;p!=-1 && st[p].next[c]==q;p=st[p].link) st[p].next[c]=clone;

			st[q].link=st[cur].link=clone;	
		}
	}
	last=cur;
}
int distsub(int ver)
{
	int tp=1;
	if(d[ver]) return d[ver];
	for(int i=0;i<26;i++)
		if(st[ver].next[i]) tp+=distsub(st[ver].next[i]);

	d[ver]=tp;
	return d[ver];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%s",str);
		n=strlen(str);
		for(int i=0;i<n;i++) sz_extend(i);
		int ans=distsub(0);
		printf("%d\n",ans-1);
	}
	return 0;
} 