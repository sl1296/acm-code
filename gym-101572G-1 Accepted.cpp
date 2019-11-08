
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int n,t;
    bool operator < (const node &p) const{
        if(n!=p.n)return n<p.n;
        return t>p.t;
    }
};
node fd[100010];
int id[100010],time[100010],sz[100010],nn;
int pos[100010];
node val[100010];
inline int lowbit(int x){
    return x&-x;
}
inline void update(int x,int v){
    for(int i=x;i<=nn;i+=lowbit(i)){
        sz[i]+=v;
    }
}
inline int query(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ret+=sz[i];
    }
    return ret;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt=1;
    fd[cnt++]=(node){0,0};
    for(int i=0;i<m;++i){
        scanf("%d%d",&id[i],&time[i]);
        if(id[i]==1){
            fd[cnt]=(node){fd[cnt-1].n+1,fd[cnt-1].t+time[i]};
            ++cnt;
        }
    }
    nn=cnt;
    update(1,n-1);
    for(int i=2;i<=n;++i){
        pos[i]=1;
        val[i]=(node){0,0};
    }
    int now=1;
//        for(int i=1;i<=nn;++i){
//            printf("%d ",query(i));
//        }
//        printf("\n");
//        for(int i=1;i<=nn;++i){
//            printf("%d ",sz[i]);
//        }
//        printf("\n");
    for(int i=0;i<m;++i){
        if(id[i]==1){
            ++now;
        }else{
            update(pos[id[i]],-1);
            ++val[id[i]].n;
            val[id[i]].t+=time[i];
            pos[id[i]]=lower_bound(fd+1,fd+cnt,val[id[i]])-fd;
            update(pos[id[i]],1);
        }
//        for(int i=1;i<=nn;++i){
//            printf("%d ",query(i));
//        }
//        printf("\n");
//        for(int i=1;i<=nn;++i){
//            printf("%d ",sz[i]);
//        }
//        printf("\n");
        printf("%d\n",n-query(now));
    }
    return 0;
}
/*
3 4
2 7
3 5
1 6
1 9
*/

