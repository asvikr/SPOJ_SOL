#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long int LL;
char str[1005];
int suff;
struct node
{
    int num;
    int len;
    int sufflink;
    int next[26];
};
node tree[1234];
void initTree()
{
    suff=2;
    tree[1].len=-1;
    tree[1].sufflink=1;
    tree[2].len=0;
    tree[2].sufflink=1;
}
void addLetter(int pos)
{
    int curlen=0,cur=suff;
    int let=str[pos]-'a';
    while(true){
        curlen=tree[cur].len;
        if(pos-1-curlen>=0 && str[pos-1-curlen]==str[pos])
        break;
        cur=tree[cur].sufflink;
    }
    if(tree[cur].next[let]){
        suff=tree[cur].next[let];
        int temp=suff;
        while(temp!=1){
            tree[temp].num++;
            temp=tree[temp].sufflink;
        }
        return;
    }
    suff++;
    tree[suff].len=tree[cur].len+2;
    tree[suff].num++;
    tree[cur].next[let]=suff;
    if(tree[suff].len==1){
        tree[suff].sufflink=2;
        return;
    }
      //printf("helol\n");
    while(true){
        cur=tree[cur].sufflink;
        curlen=tree[cur].len;
        if(pos-1-curlen>=0 && str[pos-1-curlen]==str[pos]){
            tree[suff].sufflink=tree[cur].next[let];
           int temp=tree[cur].next[let];
            while(temp!=1){
            tree[temp].num++;
            temp=tree[temp].sufflink;
            }
            break;
        }
    }
    //printf("helol\n");
}
LL ans=0;
int main()
{
    scanf("%s",str);
    for(int i=1;i<1234;i++){
        tree[i].num=0;
    }
    initTree();
    int n=strlen(str);
    for(int i=0;i<n;i++){
        addLetter(i);
    }
   // printf("%d\n",suff);
    for(int i=3;i<=suff;i++){
        ans=(ans+tree[i].num);
    }
    printf("%lld\n",ans);
    return 0;
}
