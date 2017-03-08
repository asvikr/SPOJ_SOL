#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define N 100002
#define SN 400000
#define SQN 327
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    bool b=0;
    while(c<'0'||c>'9'){
        if(c=='-'){
            b=1;
        }
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    if(b){
        return -x;
    }
    return x;
}
#define index second.second.second
#define lef second.second.first
#define rig second.first
#define blok first
int n,m=100002,k;
int leftmost[N]={0},rightmost[N]={0},nextright[N]={0},nextleft[N]={0},templeft[N],tempright[N];
int sqn;
priority_queue<pair<int,pair<int,pair<int,int> > > > PQ;//first will have l/sqn , second.first will have right , second.second.first will have left and second.second.second will have index
int freq[N]={0};
int arr[N];
int segtree[SN];
int ans[N];
int curl=1,curr=0;
int posintree[N];
void build(int l,int r,int node){
    if(l==r){
        posintree[l]=node;
        return;
    }
    int lc=node<<1;
    int rc=lc|1;
    int mid = (l+r)>>1;
    build(l,mid,lc);
    build(mid+1,r,rc);
}
void update(int inde,int val){
    int x=posintree[inde];
    segtree[x]=val;
    while(x){
        x>>=1;
        int lc=x<<1;
        int rc=lc|1;
        segtree[x]=max(segtree[lc],segtree[rc]);
    }
}
void process(pair<int,pair<int,pair<int,int> > > a){
    int l=-a.lef;
    int r=-a.rig;
    int indice=a.index;
    //cout<<l<<" "<<r<<endl;
    //3,5 to 5,6 , 4 5 6 6 5 7 4
    while(curr>r){
        int val=arr[curr];
        rightmost[val]=nextleft[curr];
        if(nextleft[curr]==0){
            rightmost[val]=curr;
        }
        update(val,rightmost[val]-leftmost[val]);
        curr--;
    }
    while(r>curr){
        curr++;
        int val=arr[curr];
        rightmost[val]=curr;
        if(leftmost[val]==0){
            leftmost[val]=curr;
        }
        int nmax = rightmost[val]-leftmost[val];
        update(val,nmax);
        //cout<<"curr++ "<<val<<" "<<nmax<<endl;
    }
    while(l>curl){
        int val=arr[curl];
        leftmost[val]=nextright[curl];
        if(nextright[curl]==0){
            rightmost[val]=0;
        }
        update(val,rightmost[val]-leftmost[val]);
        curl++;
    }
    while(l<curl){
        curl--;
        int val=arr[curl];
        leftmost[val]=curl;
        if(rightmost[val]==0){
            rightmost[val]=curl;
        }
        update(val,rightmost[val]-leftmost[val]);
       // cout<<"curl-- "<<val<<" "<<nmax<<endl;
    } 
    ans[indice]=segtree[1];
    if(ans[indice]<0){
        ans[indice]=0;
    }
}
int main(){
    arr[1]=50001;
    n=scan(),k=scan();
    sqn=sqrt(n+1);
    build(1,100002,1);
    for(int i=1;i<=n;i++){
        arr[i+1]=arr[i]+scan();
    }
    n++;
    for(int i=1;i<=n;i++){
        int cur = arr[i];
        nextleft[i]=templeft[cur];
        templeft[cur]=i;
    }
    for(int i=n;i>=1;i--){
        int cur=arr[i];
        nextright[i]=tempright[cur];
        tempright[cur]=i;
    }
    int ma=0;
    for(int i=1;i<=k;i++){
        int l=scan(),r=scan()+1;
        int pos=l/sqn;
        pair<int,pair<int,pair<int,int> > > temp;
        temp.blok = -pos;
        temp.rig = -r;
        temp.lef = -l;
        temp.index = i;
        PQ.push(temp);
    }
    while(!PQ.empty()){
        pair<int,pair<int,pair<int,int> > >  x = PQ.top();
        PQ.pop();
        process(x);
    }
    for(int i=1;i<=k;i++){
        printf("%d\n",ans[i]);
    }
}  