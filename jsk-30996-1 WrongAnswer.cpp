
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define inf 0x3f3f3f3f
int v[maxn],pos;
int mon[maxn],rep[maxn],rem[maxn];
struct SegTree{
    int minv[maxn];
    void build(int o,int L,int R){
        if(L==R) minv[o]=v[L];
        else{
            int M=(L+R)/2;
            build(o*2,L,M);
            build(o*2+1,M+1,R);
            minv[o]=min(minv[o*2],minv[o*2+1]);
        }
    }
    void update(int o,int L,int R,int p){
        if(L==R) minv[o]=inf;
        else{
            int M=(L+R)/2;
            if(p<=M) update(o*2,L,M,p);
            else update(o*2+1,M+1,R,p);
            minv[o]=min(minv[o*2],minv[o*2+1]);
        }
    }
    int query(int o,int L,int R,int val){
        if(L==R){
            pos=L;
            return minv[o];
        }else{
            int M=(L+R)/2;
            if(minv[o*2]<=val) return query(o*2,L,M,val);
            else return query(o*2+1,M+1,R,val);
        }
    }
}T;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    T.build(1,1,n);
    int y=0;
    for(int i=1;i<=n;i++){
        int minx=T.minv[1];
        int mm;
        if(y>=minx) mm=0;
        else{
            mm=(minx-y)/m;
            if((minx-y)%m) mm++;
        }
//        printf("%d : %d %d %d ",i,minx,mm,y+mm*m-minx);
        mon[i]=mon[i-1]+mm;
        minx=T.query(1,1,n,y+mm*m);
//        printf("  %d:%d\n",minx,pos);
        rem[i]=y=y+mm*m-minx;
        rep[i]=rep[i-1]+minx;
        T.update(1,1,n,pos);
    }
    int qq,t;
    scanf("%d",&qq);
    while(qq--){
        scanf("%d",&t);
        int p=upper_bound(mon+1,mon+1+n,t)-mon-1;
        if(t>mon[n]) printf("%d %d\n",p,rem[p]);
        else printf("%d %d\n",p,rem[p]+(t-mon[p])*m);
    }
    return 0;
}

