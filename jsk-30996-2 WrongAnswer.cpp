
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define maxn 100010
int v[maxn],pos;
int rep[maxn],rem[maxn];
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
    for(int i=1;i<=100000;i++){
        if(rep[i-1]==n){
            rep[i]=rep[i-1];
            rem[i]=rem[i-1];
        }else{
            y+=m;
            if(T.minv[1]>y){
                rep[i]=rep[i-1];
                rem[i]=y;
            }else{
                int minx=T.query(1,1,n,y);
                rep[i]=rep[i-1]+1;
                rem[i]=y=y-minx;
                T.update(1,1,n,pos);
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        printf("%d %d\n",rep[t],rem[t]);
    }
    return 0;
}

