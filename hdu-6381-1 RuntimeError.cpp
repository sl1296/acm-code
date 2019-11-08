
#include<cstdio>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
char s[510][510];
ll xds[510][2010];
int len[510];
void build(int id,int l,int r,int rt){
    if(l==r){
        xds[id][rt]=1LL<<(s[id][l]<58?s[id][l]-48:(s[id][l]<97?s[id][l]-29:s[id][l]-87));
        return;
    }
    int m=(l+r)>>1;
    build(id,lson);
    build(id,rson);
    xds[id][rt]=xds[id][rt<<1]|xds[id][rt<<1|1];
}
ll query(int id,int l,int r,int rt,int s,int t){
    if(s<=l&&r<=t)return xds[id][rt];
    ll ret=0;
    int m=(l+r)>>1;
    if(s<=m)ret|=query(id,lson,s,t);
    if(t>m)ret|=query(id,rson,s,t);
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int l;
        scanf("%d",&l);
        int n=2*l-1;
        for(int i=0;i<n;++i){
            scanf("%s",&s[i][1]);
            len[i]=i<l?(l+i):(l+n-1-i);
            build(i,1,len[i],1);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int x,y,d,cnt=0;
            scanf("%d%d%d",&x,&y,&d);
            ll ans=0;
            --y;
            //i=y j=(x+1)/2 s=i-l+1 e=i+l-1  y-l+1 -> y+l-1
            int j=(x+1)>>1;
            for(int i=y-d+1,le=d-1;i<=y;++i,++le){
//                printf("%d %d %d %d %d %d\n",i,1,len[i],1,j,j+le);
                ans|=query(i,1,len[i],1,j,j+le);
            }
            for(int i=y+d-1,le=d-1;i>y;--i,++le){
//                printf("%d %d %d %d %d %d\n",i,1,len[i],1,j,j+le);
                ans|=query(i,1,len[i],1,j,j+le);
            }
            while(ans){
                if(ans&1)++cnt;
                ans>>=1;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}

