
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ll long long
char name[500010][12];
int num[500010];
int tmp[500010],cnt[500010];
int tree[2000010];
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
int query(int x,int l,int r,int rt){
    tree[rt]--;
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(tree[rt<<1]>=x)return query(x,lson);else return query(x-tree[rt<<1],rson);
}
int main(){
    for(int i=1;i<500001;i++)tmp[i]=i,cnt[i]=1;
    for(ll i=2;i<500001;i++){
        if(tmp[i]>1){
            cnt[i]=2;
            for(ll j=i*2;j<500001;j+=i){
                int cc=1;
                while(tmp[j]%i==0)tmp[j]/=i,cc++;
                cnt[j]*=cc;
            }
        }
    }
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=1;i<=n;i++)scanf("%s%d",name[i],&num[i]);
        build(1,n,1);
        int pos=k,ans=k,mx=1,left=n-1;
        for(int i=1;i<=n;i++){
            int up=query(pos,1,n,1);
            if(cnt[i]>mx){
                mx=cnt[i];
                ans=up;
            }
            if(i==n)break;
            if(num[k]>0){
                pos=(k-1+num[k])%left;
            }else{
                pos=((k+1+num[k])%left+left)%left;
            }
            if(pos==0)pos=left;
            left--;
        }
        printf("%s %d\n",name[ans],mx);
    }
    return 0;
}

