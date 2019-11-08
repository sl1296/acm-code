
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
int sum[2000010];
int len;
int lowbit(int x){
    return x&(-x);
}
void update(int x){
    for(int i=x;i<=len;i+=lowbit(i)){
        sum[i]++;
    }
}
int query(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ret+=sum[i];
    }
    return ret;
}
struct node{
    LL x,y;
    bool operator < (const node &p){
        return x<p.x;
    }
};
node tree[1000010];
node add[1000010];
LL ys[2000010];
int ysn;
int main(){
    LL m;
    int n;
    while(~scanf("%I64d%d",&m,&n)){
        ysn=0;
        ys[0]=0;
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d",&tree[i].x,&tree[i].y);
            ys[++ysn]=tree[i].x;ys[++ysn]=tree[i].y;
        }
        if(n&1){
            printf("-1\n");
            continue;
        }
        sort(ys+1,ys+ysn+1);
        len=unique(ys+1,ys+ysn+1)-ys;
        sort(tree,tree+n);
        for(int i=0;i<n;i++){
            add[i].x=lower_bound(ys+1,ys+len,tree[i].x)-ys;
            add[i].y=lower_bound(ys+1,ys+len,tree[i].y)-ys;
        }
        LL ans=2000000000000000000LL;
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++){
            update(add[i].y);
            while(i+1<n&&add[i+1].x==add[i].x){
                i++;
                update(add[i].y);
            }
            LL re=query(len-1);
            if(re*2>=n){
                LL tmp=tree[i].x+1;
                int s=0,e=len-1;
                while(s<e){
                    int mid=s+(e-s)/2;
                    if(query(mid)*2<n){
                        s=mid+1;
                    }else{
                        e=mid;
                    }
                }
                if(query(s)*2==n){
                    ans=min(ans,tmp*(ys[s]+1));
                }
                s=0,e=len-1;
                while(s<e){
                    int mid=e-(e-s)/2;
                    if((re-query(mid-1))*2<n){
                        e=mid-1;
                    }else{
                        s=mid;
                    }
                }
                if((re-query(s-1))*2==n){
                    ans=min(ans,tmp*(m-ys[s]));
                }
            }
        }
        memset(sum,0,sizeof(sum));
        for(int i=n-1;i>=0;i--){
            update(add[i].y);
            while(i-1>=0&&add[i-1].x==add[i].x){
                i--;
                update(add[i].y);
            }
            LL re=query(len-1);
            if(re*2>=n){
                LL tmp=m-tree[i].x;
                int s=0,e=len-1;
                while(s<e){
                    int mid=s+(e-s)/2;
                    if(query(mid)*2<n){
                        s=mid+1;
                    }else{
                        e=mid;
                    }
                }
                if(query(s)*2==n){
                    ans=min(ans,tmp*(ys[s]+1));
                }
                s=0,e=len-1;
                while(s<e){
                    int mid=e-(e-s)/2;
                    if((re-query(mid-1))*2<n){
                        e=mid-1;
                    }else{
                        s=mid;
                    }
                }
                if((re-query(s-1))*2==n){
                    ans=min(ans,tmp*(m-ys[s]));
                }
            }
        }
        if(ans==2000000000000000000LL)ans=-1;
        printf("%I64d\n",ans);
    }
    return 0;
}


