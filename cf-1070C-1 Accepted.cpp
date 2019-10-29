
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200010
#define N 1000000
struct node{
    int l,r,c,p;
}a[maxn],b[maxn];
bool cmp1(const node &a,const node &b){
    return a.l<b.l;
}
bool cmp2(const node &a,const node &b){
    return a.r<b.r;
}
struct SegTree{
    ll sumv[N*4+10],numv[N*4+10];
    void update(int o,int L,int R,int p,int v){
        if(L==R){
            numv[o]+=v;
            sumv[o]=numv[o]*L;
        }else{
            int M=(L+R)/2;
            if(p<=M) update(o*2,L,M,p,v);
            else update(o*2+1,M+1,R,p,v);
            numv[o]=numv[o*2]+numv[o*2+1];
            sumv[o]=sumv[o*2]+sumv[o*2+1];
        }
    }
    ll query(int o,int L,int R,int k){
        if(numv[o]<=k) return sumv[o];
        if(L==R) return (ll)k*L;
        int M=(L+R)/2;
        if(k<=numv[o*2]) return query(o*2,L,M,k);
        else return sumv[o*2]+query(o*2+1,M+1,R,k-numv[o*2]);
    }
}T;
int main(){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].c,&a[i].p);
        b[i]=a[i];
    }
    sort(a,a+m,cmp1);sort(b,b+m,cmp2);
    int p1=0,p2=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        while(p1<m&&a[p1].l<=i){
            T.update(1,1,N,a[p1].p,a[p1].c);
            p1++;
        }
        while(p2<m&&b[p2].r<i){
            T.update(1,1,N,b[p2].p,-b[p2].c);
            p2++;
        }
        ans+=T.query(1,1,N,k);
    }
    printf("%I64d\n",ans);
    return 0;
}
/*
4 100 3
3 3 2 5
1 1 3 2
2 4 4 4
*/

