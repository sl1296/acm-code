
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
char s1[100],s2[100];
int tree[540000];
bool op[540000],ans[132000];
int ll[132000],rr[132000];
void build(int l,int r,int rt){
    op[rt]=false;
    if(l==r){
        tree[rt]=0;
        return;
    }
    tree[rt]=-1;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
}
void pushdown(int rt){
    int left=rt<<1,right=rt<<1|1;
    if(tree[rt]!=-1){
        op[left]=op[right]=false;
        tree[left]=tree[right]=tree[rt];
        tree[rt]=-1;
    }
    if(op[rt]){
        op[rt]=false;
        if(tree[left]!=-1){
            op[left]=false;
            tree[left]=!tree[left];
        }else{
            op[left]=true;
        }
        if(tree[right]!=-1){
            op[right]=false;
            tree[right]=!tree[right];
        }else{
            op[right]=true;
        }
    }
}
void update(int x,int y,int v,int l,int r,int rt){
    if(x<=l&&y>=r){
        op[rt]=false;
        tree[rt]=v;
        return;
    }
    int mid=(l+r)>>1;
    if(op[rt]||tree[rt]!=-1)pushdown(rt);
    if(x<=mid)update(x,y,v,lson);
    if(y>mid)update(x,y,v,rson);
}
void update2(int x,int y,int l,int r,int rt){
    if(x<=l&&y>=r){
        if(tree[rt]!=-1){
            tree[rt]=!tree[rt];
        }else{
            op[rt]=!op[rt];
        }
        return;
    }
    int mid=(l+r)>>1;
    if(op[rt]||tree[rt]!=-1)pushdown(rt);
    if(x<=mid)update2(x,y,lson);
    if(y>mid)update2(x,y,rson);
}
void query(int l,int r,int rt){
    if(tree[rt]!=-1){
        if(tree[rt])for(int i=l;i<=r;i++)ans[i]=true;
        return;
    }
    int mid=(l+r)>>1;
    if(op[rt])pushdown(rt);
    query(lson);
    query(rson);
}
int main(){
	freopen("in.txt","r",stdin);
    int n=131080;
    build(1,n,1);
    while(~scanf("%s%s",s1,s2)){
        int a=0,b=0;
        bool l,r;
        if(s2[0]=='(')l=false;else l=true;
        int p=1;
        while(s2[p]!=','){
            a=a*10+s2[p]-48;
            p++;
        }
        p++;
        while(s2[p]>=48&&s2[p]<=57){
            b=b*10+s2[p]-48;
            p++;
        }
        if(s2[p]==')')r=false;else r=true;
        a=a*2+1;if(!l)a++;
        b=b*2+1;if(!r)b--;
        if(s1[0]=='U'){
            update(a,b,1,1,n,1);
        }else if(s1[0]=='I'){
            update(1,a-1,0,1,n,1);
            update(b+1,n,0,1,n,1);
        }else if(s1[0]=='D'){
            update(a,b,0,1,n,1);
        }else if(s1[0]=='C'){
            update(1,a-1,0,1,n,1);
            update(b+1,n,0,1,n,1);
            update2(a,b,1,n,1);
        }else{
            update2(a,b,1,n,1);
        }
    }
        query(1,n,1);
        int cnt=0;
        for(int i=0;i<131071;i++){
            if(ans[i]){
                ll[cnt]=i;
                while(i+1<131071&&ans[i+1])i++;
                rr[cnt++]=i;
            }
        }
  //      for(int i=0;i<15;i++)printf("%d ",ans[i]);
        for(int i=0;i<cnt;i++){
            if(i)printf(" ");
            int ss=(ll[i]-1)/2;
            int ee=rr[i]/2;
            if(ll[i]&1)printf("[");else printf("(");
            printf("%d,%d",ss,ee);
            if(rr[i]&1)printf("]");else printf(")");
        }
        if(cnt==0)printf("empty set");
        printf("\n");
    return 0;
}

