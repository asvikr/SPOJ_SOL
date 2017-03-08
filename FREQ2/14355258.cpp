
#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define getchar_unlocked getchar
#define N 110000
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
#define index second.second.second
#define lef second.second.first
#define rig second.first
#define blok first
int n,q;
priority_queue<pair<int,pair<int,pair<int,int> > > > PQ;//first will have l/sqn , second.first will have right , second.second.first will have left and second.second.second will have index
int freq[N]={0};
int counter[N]={0};
int arr[N];
int ans[N]={0};
int curl=1,curr=0;
int tempans=0;
void process(pair<int,pair<int,pair<int,int> > > a){
    int l=-a.lef;
    int r=-a.rig;
    int indice=a.index;
   // cout<<l<<" "<<r<<" "<<indice<<endl;
    //1 1 3 3 3 3 5 12 12 12  , 2 ,3
    while(r>curr){//add
        curr++;
        int val=arr[curr];
        int c=freq[val];
        counter[c]--;
        freq[val]++;
        counter[freq[val]]++;
        tempans=max(tempans,freq[val]);
      //  cout<<"r add ";
      //  cout<<val<<" "<<freq[val]<<" "<<counter[freq[val]]<<" "<<tempans<<endl;
    }
    while(l>curl){//remove
        int val=arr[curl];
        counter[freq[val]]--;
        freq[val]--;
        //printf("%d\n",freq[val]);
        counter[freq[val]]++;
        curl++;
        while(counter[tempans]==0){
            tempans--;
        }
       // cout<<"l remove ";
       // cout<<val<<" "<<freq[val]<<" "<<counter[freq[val]]<<" "<<tempans<<endl;
    }
    while(l<curl){//add
        curl--;
        int val = arr[curl];
        int c = freq[val];
        counter[c]--;
        freq[val]++;
        counter[freq[val]]++;
        tempans=max(tempans,freq[val]);
       // cout<<"l add ";
       // cout<<val<<" "<<freq[val]<<" "<<counter[freq[val]]<<" "<<tempans<<endl;
    }
    while(r<curr){//remove
        int val=arr[curr];
        counter[freq[val]]--;
        freq[val]--;
        counter[freq[val]]++;
        curr--;
        while(counter[tempans]==0){
            tempans--;
        }
       // cout<<"r remove ";
       // cout<<val<<" "<<freq[val]<<" "<<counter[freq[val]]<<" "<<tempans<<endl;
    }
    ans[indice]=tempans;
    //cout<<l<<" "<<r<<" "<<counter[tempans]<<endl;
}
int main(){
    //freopen("input1.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    n=scan();
    int sqn=sqrt(n);
    counter[0]=n;
    q=scan();
    for(int i=1;i<=n;i++){
        arr[i]=scan();
    }
    for(int i=1;i<=q;i++){
        int l=scan()+1,r=scan()+1;
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
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
}
