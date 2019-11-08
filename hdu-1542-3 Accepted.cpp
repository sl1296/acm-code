
#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
double ys[1000];
int ysn;
struct edge{
    double l,r,h;
    int v;
    bool operator < (const edge &p) const{
        return h<p.h;
    }
};
edge e[1000];
int ec;
int val[5000];
double len[5000];
void pushup(int l,int r,int rt){
    if(val[rt]){
        len[rt]=ys[r+1]-ys[l];
    }else if(l==r){
        len[rt]=0;
    }else{
        len[rt]=len[rt<<1]+len[rt<<1|1];
    }
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        val[rt]+=v;
        pushup(l,r,rt);
        return;
    }
    int mid=(l+r)>>1;
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(l,r,rt);
}
int main(){
    int n,cas=1;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        ec=0;
        ysn=1;
        for(int i=0;i<n;i++){
            double aa,bb,cc,dd;
            scanf("%lf%lf%lf%lf",&aa,&bb,&cc,&dd);
            e[ec++]=(edge){aa,cc,bb,1};
            e[ec++]=(edge){aa,cc,dd,-1};
            ys[ysn++]=aa;
            ys[ysn++]=bb;
            ys[ysn++]=cc;
            ys[ysn++]=dd;
        }
        sort(e,e+ec);
        sort(ys+1,ys+ysn);
        int cnt=1;
        for(int i=1;i<ysn;i++){
            ys[cnt++]=ys[i];
            while(i+1<ysn&&ys[i+1]==ys[i])i++;
        }
        memset(val,0,sizeof(val));
        memset(len,0,sizeof(len));
        double ans=0;
        double prelen=0;
        double preh=0;
        for(int i=0;i<ec;i++){
         //   printf("i=%d\n",i);
            int left=lower_bound(ys+1,ys+cnt,e[i].l)-ys;
            int right=lower_bound(ys+1,ys+cnt,e[i].r)-ys-1;
          //  printf("l=%f r=%f left=%d right=%d\n",e[i].l,e[i].r,left,right);
            update(left,right,e[i].v,1,cnt,1);
          //  printf("%f*(%f-%f)\n%f %f\n",prelen,e[i].h,preh,len[1],e[i].h);
            ans+=prelen*(e[i].h-preh);
         //   printf("ans=%f\n",ans);
            prelen=len[1];
            preh=e[i].h;
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",cas++,ans);
    }
    return 0;
}

