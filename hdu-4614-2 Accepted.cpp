
#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int sum[200010];
int add[200010];
void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt){
    add[rt]=-1;
    if(l==r){
        sum[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt,int len){
    int ls=rt<<1;
    int rs=rt<<1|1;
    if(add[rt]==0){
        sum[ls]=len-len/2;
        sum[rs]=len/2;
        add[ls]=add[rs]=0;
    }else{
        sum[ls]=sum[rs]=0;
        add[ls]=add[rs]=1;
    }
    add[rt]=-1;
}
int query1(int L,int R,int l,int r,int rt){
 //   printf("q1:L=%d R=%d l=%d r=%d rt=%d\n",L,R,l,r,rt);
  //  if(add[rt]==1)printf("q1:add[%d]=%d return 0\n",rt,add[rt]);
    if(add[rt]==1)return 0;
   // if(L<=l&&r<=R)printf("q1:return sum[%d]=%d\n",rt,sum[rt]);
    if(L<=l&&r<=R)return sum[rt];
    int re=0;
    int m=(l+r)>>1;
   // if(add[rt]>-1)printf("q1:pushdown\n");
    if(add[rt]>-1)pushdown(rt,r-l+1);
   // printf("q1:left\n");
    if(L<=m)re+=query1(L,R,lson);
  //  printf("q1:re=%d\nq1:right\n",re);
    if(R>m)re+=query1(L,R,rson);
  //  printf("q1:re=%d\n",re);
    return re;
}
int query2(int v,int l,int r,int rt){
    if(l==r)return l;
    int m=(l+r)>>1;
    if(add[rt]>-1)pushdown(rt,r-l+1);
    if(v>sum[rt<<1]){
        v-=sum[rt<<1];
        return query2(v,rson);
    }else{
        return query2(v,lson);
    }
}
void update(int L,int R,int v,int l,int r,int rt){
  //  printf("L=%d R=%d v=%d l=%d r=%d rt=%d\n",L,R,v,l,r,rt);
    if(L<=l&&r<=R){
        add[rt]=v;
        if(v)sum[rt]=0;else sum[rt]=r-l+1;
     //   printf("add[%d]=%d sum[%d]=%d\nreturn\n",rt,add[rt],rt,sum[rt]);
        return;
    }
    if(add[rt]>-1)pushdown(rt,r-l+1);
    int m=(l+r)>>1;
   // printf("left\n");
    if(L<=m)update(L,R,v,lson);
   // printf("right\n");
    if(R>m)update(L,R,v,rson);
  //  printf("pushup\n");
    pushup(rt);
  //  printf("sum[%d]=%d\n",rt,sum[rt]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while(m--){
            int k,x,y;
            scanf("%d%d%d",&k,&x,&y);
            if(k==1){
                x++;
                int cnt=0;
                if(x-1>0)cnt=query1(1,x-1,1,n,1);
             //   printf("cnt=%d\n",cnt);
                if(sum[1]==cnt)printf("Can not put any one.\n");
                else{
                    y=min(sum[1]-cnt,y);
                //    printf("sum[1]=%d y=%d\n",sum[1],y);
                    int from=query2(cnt+1,1,n,1);
                    int to=query2(cnt+y,1,n,1);
                    update(from,to,1,1,n,1);
                //    for(int i=0;i<30;i++)printf("%3d ",sum[i]);printf("\n");
                //    for(int i=0;i<30;i++)printf("%3d ",add[i]);printf("\n");
                    printf("%d %d\n",from-1,to-1);
                }
            }else{
                x++;y++;
                int em=query1(x,y,1,n,1);
                update(x,y,0,1,n,1);
          //          for(int i=0;i<30;i++)printf("%3d ",sum[i]);printf("\n");
           //         for(int i=0;i<30;i++)printf("%3d ",add[i]);printf("\n");
                printf("%d\n",y-x+1-em);
            }
        }
        printf("\n");
    }
    return 0;
}

