
#include<cstdio>
struct node{
    int l,r,k,cur,id,type;
};
int n,m;
int a[50010];
int ans[10010];
node q[100010],q1[100010],q2[100010];
int cur[100010];
int qid,aid;
int tree[50010];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))tree[i]+=v;
}
int query(int x){
    int re=0;
    for(int i=x;i>0;i-=lowbit(i))re+=tree[i];
    return re;
}
void cdq(int ff,int tt,int l,int r){
    if(ff>tt)return;
    if(l==r){
        for(int i=ff;i<=tt;i++){
            if(q[i].type==3)ans[q[i].id]=l;
        }
        return;
    }
    int mid=(l+r)>>1;
    for(int i=ff;i<=tt;i++){
        if(q[i].type==1&&q[i].k<=mid)update(q[i].l,1);
        else if(q[i].type==2&&q[i].k<=mid)update(q[i].l,-1);
        else if(q[i].type==3)cur[i]=query(q[i].r)-query(q[i].l-1);
    }
    int t1=0,t2=0;
    for(int i=ff;i<=tt;i++){
        if(q[i].type==1&&q[i].k<=mid)update(q[i].l,-1);
        else if(q[i].type==2&&q[i].k<=mid)update(q[i].l,1);
        if(q[i].type==3){
            if(q[i].cur+cur[i]>=q[i].k){
                q1[t1++]=q[i];
            }else{
                q[i].cur+=cur[i];
                q2[t2++]=q[i];
            }
        }else{
            if(q[i].k<=mid){
                q1[t1++]=q[i];
            }else{
                q2[t2++]=q[i];
            }
        }
    }
    for(int i=0;i<t1;i++)q[ff+i]=q1[i];
    for(int i=0;i<t2;i++)q[ff+t1+i]=q2[i];
    cdq(ff,ff+t1-1,l,mid);
    cdq(ff+t1,tt,mid+1,r);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        qid=aid=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            q[qid++]=(node){i,i,a[i],0,0,1};
        }
        for(int i=0;i<m;i++){
            char s[5];
            scanf("%s",s);
            if(s[0]=='Q'){
                int l,r,k;
                scanf("%d%d%d",&l,&r,&k);
                q[qid++]=(node){l,r,k,0,aid++,3};
            }else{
                int l,k;
                scanf("%d%d",&l,&k);
                q[qid++]=(node){l,l,a[l],0,0,2};
                q[qid++]=(node){l,l,k,0,0,1};
                a[l]=k;
            }
        }
        cdq(0,qid-1,0,1000000000);
        for(int i=0;i<aid;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

