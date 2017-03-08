#include<bits/stdc++.h>
using namespace std;
//#define getchar_unlocked getchar
inline int read()
{
	int ret = 0;
	char c = getchar_unlocked();
    int temp=1;
    if(c=='-') temp=-1;
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
		 if(c=='-') temp=-1;
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
	//printf("%d\n",temp);
        return ret*temp;
}
struct node
{
    int val,pri,siz;
    node *l,*r;
};
typedef node* pnode;
int sz(pnode tree)
{
    return tree?tree->siz:0;
}
void upd_sz(pnode tree)
{
    if(tree)
        tree->siz=sz(tree->l)+sz(tree->r)+1;
}
void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) l=r=NULL;
    else if(t->val<=key) split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t;
    upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    if(!l || !r) t=l?l:r;
    else if(l->pri>r->pri) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
}
void insert(pnode &t,pnode it)
{
    if(!t) t=it;
    else if(t->pri>it->pri) split(t,it->l,it->r,it->val),t=it;
    else insert(t->val<=it->val?t->r:t->l,it);
    upd_sz(t);
}
void erase(pnode &t,int key)
{
    if(!t) return;
    else if(t->val==key){
        pnode temp=t;
        merge(t,t->l,t->r);
        free(temp);
    }
    else erase(t->val<key?t->r:t->l,key);
    upd_sz(t);
}
int find_kth(pnode t,int k)
{
    if(sz(t->l)+1==k)
        return t->val;
    if(sz(t->l)+1<k)
        return find_kth(t->r,k-sz(t->l)-1);
    else
        return find_kth(t->l,k);
}
int solve(pnode t,int val)
{
    if(t==NULL) return 0;
    if(t->val<val){
        if(t->r!=NULL)
        return sz(t->l)+1+solve(t->r,val);
        else return sz(t->l)+1;
    }
    else{
        if(t->l==NULL) return 0;
        else return solve(t->l,val);
    }
}
pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val=val;ret->siz=1;ret->pri=rand();ret->l=ret->r=NULL;
    return ret;
}
int main()
{
    pnode root=NULL;
    int q;
    //scanf("%d",&q);
    q=read();
    char str[2];
    int val;
    map<int,int> M;
    while(q--){
        scanf("%s",str);
        val=read();
       // printf("%d\n",val);
        if(str[0]=='I'){
            if(M.find(val)==M.end()){
            node* temp=init(val);
            insert(root,temp);
            M[val]=1;
            }
        }
        else if(str[0]=='D'){
            if(M.find(val)!=M.end()){
            erase(root,val);
            M.erase(M.find(val));
            }
        }
        else if(str[0]=='K'){
            if(val>sz(root)){
                printf("invalid\n");
                continue;
            }
            int ans=find_kth(root,val);
            printf("%d\n",ans);
        }
        else
        {
            int ans=solve(root,val);
            printf("%d\n",ans);
        }
    }
    return 0;
}


