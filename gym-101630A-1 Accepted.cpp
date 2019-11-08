
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200010
int ty[maxn],x[maxn],y[maxn];
int V[maxn],len;
struct node {
    int x,y,id;
    node() {}
    node(int x,int y,int id):x(x),y(y),id(id) {}
    bool operator <(const node &rhs)const {
        return y>rhs.y||y==rhs.y&&x<rhs.x;
    }
};
set<node>::iterator it;
bool flag;
int ansid;
node ansnode;
struct SegTree {
    set<node> st[maxn*4];
    void build(int o,int L,int R){
        if(L==R) {
            st[o].clear();
        } else {
            int M=(L+R)/2;
            build(o*2,L,M);
            build(o*2+1,M+1,R);
            st[o].clear();
        }
    }
    void update(int o,int L,int R,node e,int ty) {
        if(L==R) {
            if(!ty) st[o].insert(e);
            else st[o].erase(e);
        } else {
            int M=(L+R)/2;
            if(e.x<=M) update(o*2,L,M,e,ty);
            else update(o*2+1,M+1,R,e,ty);
            if(!ty) st[o].insert(e);
            else st[o].erase(e);
        }
    }
    void query(int o,int L,int R,int p,int y) {
        if(flag||st[o].size()==0) return;
        if(R<p) {
            for(it=st[o].begin(); it!=st[o].end(); it++) {
                node e=*it;
                if(e.y<=V[p]) break;
                ll x1=((ll)V[e.x]+e.y)/2,y1=((ll)e.y-V[e.x])/2;
                ll x2=V[p],y2=y;
                if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<y1*y1) {
                    flag=true;
                    ansid=e.id;
                    ansnode=e;
                    break;
                }
            }
        } else {
            int M=(L+R)/2;
            query(o*2,L,M,p,y);
            if(M+1<p) query(o*2+1,M+1,R,p,y);
        }
    }
} T;
int main() {
//    freopen("data.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0; i<n; i++) {
            scanf("%d%d%d",&ty[i],&x[i],&y[i]);
            if(ty[i]==1) V[i]=x[i]-y[i];
            else V[i]=x[i];
        }
        sort(V,V+n);
        len=unique(V,V+n)-V;
        T.build(1,0,len-1);
        for(int i=0; i<n; i++) {
            if(ty[i]==1) {
                int p=lower_bound(V,V+len,x[i]-y[i])-V;
                T.update(1,0,len-1,node(p,x[i]+y[i],i+1),0);
            } else {
                flag=false;
                int p=lower_bound(V,V+len,x[i])-V;
//                printf("%d\n",p);
                if(p) T.query(1,0,len-1,p,y[i]);
                if(flag) {
                    printf("%d\n",ansid);
                    T.update(1,0,len-1,ansnode,1);
                } else printf("-1\n");
            }
        }
    }
    return 0;
}
/*
2
1 0 1
2 0 1
*/

