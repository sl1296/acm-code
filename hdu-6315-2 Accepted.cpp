
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,q;
int val[maxn];
int C[maxn];
int lowbit(int x){
    return x&-x;
}
void add(int x){
    while(x<=n){
        C[x]++;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=C[x];
        x-=lowbit(x);
    }
    return ans;
}
struct SegTree{
    int addv[maxn*4],minv[maxn*4];
    void build(int o,int L,int R){
        if(L==R) addv[o]=minv[o]=val[L];
        else{
            int M=(L+R)/2;
            build(o*2,L,M);build(o*2+1,M+1,R);
            addv[o]=0;
            minv[o]=min(minv[o*2],minv[o*2+1]);
        }
    }
    void update(int o,int L,int R,int qL,int qR){
        if(qL<=L&&R<=qR){
            addv[o]--;
            minv[o]--;
        }else{
            int M=(L+R)/2;
            if(qL<=M) update(o*2,L,M,qL,qR);
            if(qR>M) update(o*2+1,M+1,R,qL,qR);
            minv[o]=min(minv[o*2],minv[o*2+1])+addv[o];
        }
    }
    void query(int o,int L,int R,int s){
        if(s+minv[o]>0) return;
        if(L==R){
            add(L);
            addv[o]=minv[o]=val[L]-s;
        }else{
            int M=(L+R)/2;
            query(o*2,L,M,s+addv[o]);
            query(o*2+1,M+1,R,s+addv[o]);
            minv[o]=min(minv[o*2],minv[o*2+1])+addv[o];
        }
    }
}T;
int main(){
    while(scanf("%d%d",&n,&q)!=EOF){
        memset(C,0,sizeof(C));
        for(int i=1;i<=n;i++) scanf("%d",&val[i]);
        T.build(1,1,n);
        char op[10];
        int l,r;
        while(q--){
            scanf("%s%d%d",op,&l,&r);
            if(op[0]=='a'){
                T.update(1,1,n,l,r);
                T.query(1,1,n,0);
            }else printf("%d\n",sum(r)-sum(l-1));
        }
    }
    return 0;
}

