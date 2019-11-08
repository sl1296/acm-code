
#include<cstdio>
#include<algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
struct node{
    int val,bj;
    int llena,rlena,lena;
    int llenb,rlenb,lenb;
    int lv,rv,cnt;
    bool isonea,isoneb;
};
node tree[400010];
void pushup(int rt){
    int left=rt<<1,right=rt<<1|1;
    tree[rt].lv=tree[left].lv;
    tree[rt].rv=tree[right].rv;
    tree[rt].cnt=tree[left].cnt+tree[right].cnt;
    tree[rt].llena=tree[left].llena;
    if(tree[left].isonea)tree[rt].llena+=tree[right].llena;
    tree[rt].rlena=tree[right].rlena;
    if(tree[right].isonea)tree[rt].rlena+=tree[left].rlena;
    tree[rt].lena=max(max(tree[left].lena,tree[right].lena),tree[left].rlena+tree[right].llena);
    if(tree[left].isonea&&tree[right].isonea)tree[rt].isonea=true;else tree[rt].isonea=false;
    tree[rt].llenb=tree[left].llenb;
    if(tree[left].isoneb)tree[rt].llenb+=tree[right].llenb;
    tree[rt].rlenb=tree[right].rlenb;
    if(tree[right].isoneb)tree[rt].rlenb+=tree[left].rlenb;
    tree[rt].lenb=max(max(tree[left].lenb,tree[right].lenb),tree[left].rlenb+tree[right].llenb);
    if(tree[left].isoneb&&tree[right].isoneb)tree[rt].isoneb=true;else tree[rt].isoneb=false;
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&tree[rt].val);
        tree[rt].cnt=tree[rt].lv=tree[rt].rv=tree[rt].val;
        tree[rt].bj=0;
        if(tree[rt].val){
            tree[rt].llena=tree[rt].rlena=tree[rt].lena=0;
            tree[rt].llenb=tree[rt].rlenb=tree[rt].lenb=1;
            tree[rt].isonea=false;tree[rt].isoneb=true;
        }else{
            tree[rt].llena=tree[rt].rlena=tree[rt].lena=1;
            tree[rt].llenb=tree[rt].rlenb=tree[rt].lenb=0;
            tree[rt].isonea=true;tree[rt].isoneb=false;
        }
        return;
    }
    tree[rt].bj=0;
    tree[rt].val=-1;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void qf(int rt,int len){
    if(tree[rt].val!=-1)tree[rt].val^=1;else tree[rt].bj^=1;
    tree[rt].lv^=1;tree[rt].rv^=1;
    tree[rt].cnt=len-tree[rt].cnt;
    swap(tree[rt].isonea,tree[rt].isoneb);
    swap(tree[rt].llena,tree[rt].llenb);
    swap(tree[rt].rlena,tree[rt].rlenb);
    swap(tree[rt].lena,tree[rt].lenb);
}
void pushdown(int l,int r,int mid,int rt){
    tree[rt].bj=0;
    qf(rt<<1,mid-l+1);
    qf(rt<<1|1,r-mid);
}
void pushdown2(int l,int r,int mid,int rt){
    int left=rt<<1,right=rt<<1|1;
    tree[left]=tree[right]=tree[rt];
    if(tree[rt].val){
        tree[left].llenb=tree[left].rlenb=tree[left].lenb=tree[left].cnt=mid-l+1;
        tree[right].llenb=tree[right].rlenb=tree[right].lenb=tree[right].cnt=mid-l+1;
    }else{
        tree[left].llena=tree[left].rlena=tree[left].lena=r-mid;
        tree[right].llena=tree[right].rlena=tree[right].lena=r-mid;
        tree[left].cnt=0;
        tree[right].cnt=0;
    }
    tree[rt].val=-1;
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        tree[rt].lv=tree[rt].rv=tree[rt].val=v;
        tree[rt].bj=0;
        if(v){
            tree[rt].cnt=r-l+1;
            tree[rt].llena=tree[rt].rlena=tree[rt].lena=0;
            tree[rt].llenb=tree[rt].rlenb=tree[rt].lenb=r-l+1;
            tree[rt].isonea=false;tree[rt].isoneb=true;
        }else{
            tree[rt].cnt=0;
            tree[rt].llena=tree[rt].rlena=tree[rt].lena=r-l+1;
            tree[rt].llenb=tree[rt].rlenb=tree[rt].lenb=0;
            tree[rt].isonea=true;tree[rt].isoneb=false;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(tree[rt].bj)pushdown(l,r,mid,rt);
    if(tree[rt].val!=-1)pushdown2(l,r,mid,rt);
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(rt);
}
void update2(int from,int to,int l,int r,int rt){
    if(from<=l&&to>=r){
        tree[rt].bj^=1;
        qf(rt,r-l+1);
        return;
    }
    int mid=(l+r)>>1;
    if(tree[rt].val!=-1)pushdown2(l,r,mid,rt);
    if(from<=mid)update2(from,to,lson);
    if(to>mid)update2(from,to,rson);
    pushup(rt);
}
int query(int from,int to,int l,int r,int rt){
   // printf("%d %d %d %d %d\n",from,to,l,r,rt);
    if(from<=l&&to>=r){
       // printf("ret2=%d\n",tree[rt].cnt);
        return tree[rt].cnt;
    }
    int mid=(l+r)>>1;
    if(tree[rt].bj)pushdown(l,r,mid,rt);
    if(tree[rt].val!=-1)pushdown2(l,r,mid,rt);
    int ret=0;
    if(from<=mid)ret+=query(from,to,lson);
    if(to>mid)ret+=query(from,to,rson);
    pushup(rt);
  //  printf("ret=%d\n",ret);
    return ret;
}
int query2(int from,int to,int l,int r,int rt){
 //   printf("%d %d %d %d %d\n",from,to,l,r,rt);
 //   printf("%d-%d llenb=%d rlenb=%d\n",l,r,tree[rt].llenb,tree[rt].rlenb);
    if(from<=l&&to>=r){
    //    printf("%d %d ret2=%d\n",l,r,tree[rt].lenb);
        return tree[rt].lenb;
    }
    int mid=(l+r)>>1;
    if(tree[rt].val!=-1){
        if(tree[rt].val){
       //     printf("%d %d ret3=%d\n",l,r,min(r,to)-max(from,l));
            return min(r,to)-max(from,l);
        }else{
       //     printf("%d %d ret4=0\n",l,r);
            return 0;
        }
    }
    if(tree[rt].bj)pushdown(l,r,mid,rt);
    int ret=0;
    if(from<=mid)ret=max(ret,query2(from,to,lson));
    if(to>mid)ret=max(ret,query2(from,to,rson));
    pushup(rt);
  //  printf("%d-%d llenb=%d rlenb=%d\n",l,r,tree[rt].llenb,tree[rt].rlenb);
    if(from<=mid&&to>mid){
        int left=min(mid-from+1,tree[rt<<1].rlenb);
        int right=min(to-mid,tree[rt<<1|1].llenb);
    //    printf("mid-from+1=%d left=%d to-mid=%d right=%d\n",mid-from+1,left,to-mid,right);
        ret=max(ret,left+right);
    }
   // printf("%d %d ret=%d\n",l,r,ret);
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,n,1);
        int op,a,b;
        while(q--){
            scanf("%d%d%d",&op,&a,&b);
            a++;b++;
            if(op==0){
                update(a,b,0,1,n,1);
            }else if(op==1){
                update(a,b,1,1,n,1);
            }else if(op==2){
                update2(a,b,1,n,1);
            }else if(op==3){
                printf("%d\n",query(a,b,1,n,1));
            }else{
                printf("%d\n",query2(a,b,1,n,1));
            }
        }
    }
    return 0;
}
/*
1
10 10
0 0 0 1 1 0 1 0 1 1
1 0 2
3 0 5
2 2 2
4 0 4
0 3 6
2 3 7
4 2 8
1 0 5
0 5 6
3 3 9
*/

