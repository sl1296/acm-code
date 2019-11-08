
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int n=10000001;
int tree[40000010];
bool bj[40000010];
void upset(int l,int r,int rt,int from,int to){
//    printf("upset:%d %d %d %d %d\n",l,r,rt,from,to);
    if(bj[rt])return;
    if(from<=l && r<=to){
        tree[rt]=0;
        bj[rt]=true;
        return;
    }
    int mid=(l+r)>>1;
    if(from<=mid)upset(lson,from,to);
    if(to>mid)upset(rson,from,to);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void add(int l,int r,int rt,int x){
//    printf("add:%d %d %d %d\n",l,r,rt,x);
    if(l==r){
        tree[rt]=1;
        bj[rt]=false;
        return;
    }
    int mid=(l+r)>>1;
    if(bj[rt]){
        bj[rt<<1]=bj[rt<<1|1]=true;
        tree[rt<<1]=tree[rt<<1|1]=0;
        bj[rt]=false;
    }
    if(x<=mid)add(lson,x);
    else add(rson,x);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
int query(int l,int r,int rt,int from,int to){
//    printf("query:%d %d %d %d %d\n",l,r,rt,from,to);
//    if(bj[rt])printf("true\n");
    if(bj[rt] || tree[rt]==0)return 0;
    if(from<=l && r<=to){
        return tree[rt];
    }
    int mid=(l+r)>>1,ret=0;
    if(from<=mid)ret+=query(lson,from,to);
    if(to>mid)ret+=query(rson,from,to);
    return ret;
}
int main(){
    int m,k,x;
    char s[10];
    scanf("%d%d",&m,&k);
    while(m--){
        scanf("%s%d",s,&x);
//        printf("%s %d\n",s,x);
        ++x;
        if(s[0]=='a'){
            if(!query(1,n,1,max(1,x-k),min(n,x+k))){
                add(1,n,1,x);
            }
        }else if(s[0]=='d'){
            upset(1,n,1,max(1,x-k),min(n,x+k));
        }else{
            if(query(1,n,1,max(1,x-k),min(n,x+k))){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}

