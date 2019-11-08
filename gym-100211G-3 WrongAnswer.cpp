
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    ll x,y;
};
node tr[1000010];
ll ys[2000010];
ll ysc;
ll cmp1(node a,node b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
ll cmp2(node a,node b){
    if(a.x!=b.x)return a.x>b.x;
    return a.y<b.y;
}
ll cmp3(node a,node b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y>b.y;
}
ll cmp4(node a,node b){
    if(a.x!=b.x)return a.x>b.x;
    return a.y>b.y;
}
ll sum[2000010];
ll len;
ll lowbit(ll x){
    return x&(-x);
}
void add(ll x){
    for(ll i=x;i<=len;i+=lowbit(i)){
        sum[i]++;
    }
}
ll query(ll x){
    ll ret=0;
    for(ll i=x;i>0;i-=lowbit(i)){
        ret+=sum[i];
    }
    return ret;
}
int main(){
    ll m,n;
    while(~scanf("%I64d%I64d",&m,&n)){
        ysc=0;
        for(ll i=0;i<n;i++){
            scanf("%I64d%I64d",&tr[i].x,&tr[i].y);
            ys[ysc++]=tr[i].x;
            ys[ysc++]=tr[i].y;
        }
        sort(ys,ys+ysc);
        len=unique(ys,ys+ysc)-ys;
        for(ll i=0;i<n;i++){
            tr[i].x=lower_bound(ys,ys+len,tr[i].x)-ys+1;
            tr[i].y=lower_bound(ys,ys+len,tr[i].y)-ys+1;
        }
        tr[n]=(node){-1,-1};
       // printf("len=%lld\n",len);
        ll ans=2e18;
       // printf("1\n");
        sort(tr,tr+n,cmp1);
        memset(sum,0,sizeof(sum));
        for(ll i=0;i<=n;i++){
           /* printf("i=%lld x=%lld y=%lld\n",i,tr[i].x,tr[i].y);
                    for(int j=1;j<=len;j++){
                        printf("%lld ",query(j));
                    }
                    printf("\n");*/
            if(i&&tr[i].x!=tr[i-1].x){
                ll re=query(len);
                if(re*2>=n){
                    ll s=1,e=len;
                    while(s<e){
                        ll mid=s+(e-s)/2;
                        if(query(mid)*2<n){
                            s=mid+1;
                        }else{
                            e=mid;
                        }
                    }
                 //  printf("s=%lld\n",s);
                    if(query(s)*2==n){
                        ans=min(ans,(ys[tr[i-1].x-1]+1)*(ys[s-1]+1));
                    //    printf("%lld %lld %lld\n",ys[tr[i-1].x-1],ys[s-1],ans);
                    }
                }
            }
            if(i<n)add(tr[i].y);
        }
     //   printf("2\n");
        sort(tr,tr+n,cmp2);
        memset(sum,0,sizeof(sum));
        for(ll i=0;i<=n;i++){
          /*  printf("i=%lld x=%lld y=%lld\n",i,tr[i].x,tr[i].y);
                    for(int j=1;j<=len;j++){
                        printf("%lld ",query(j));
                    }
                    printf("\n");*/
            if(i&&tr[i].x!=tr[i-1].x){
                ll re=query(len);
                if(re*2>=n){
                    ll s=1,e=len;
                    while(s<e){
                        ll mid=s+(e-s)/2;
                        if(query(mid)*2<n){
                            s=mid+1;
                        }else{
                            e=mid;
                        }
                    }
               //    printf("s=%lld\n",s);
                    if(query(s)*2==n){
                        ans=min(ans,(m-ys[tr[i-1].x-1])*(ys[s-1]+1));
                 //       printf("%lld %lld %lld\n",ys[tr[i-1].x-1],ys[s-1],ans);
                    }
                }
            }
            if(i<n)add(tr[i].y);
        }
       // printf("3\n");
        sort(tr,tr+n,cmp3);
        memset(sum,0,sizeof(sum));
        for(ll i=0;i<=n;i++){
         /*   printf("i=%lld x=%lld y=%lld\n",i,tr[i].x,tr[i].y);
                    for(int j=1;j<=len;j++){
                        printf("%lld ",query(j));
                    }
                    printf("\n");*/
            if(i&&tr[i].x!=tr[i-1].x){
                ll re=query(len);
                if(re*2>=n){
                    ll s=1,e=len;
                    while(s<e){
                        ll mid=e-(e-s)/2;
                        if((re-query(mid-1))*2<n){
                            e=mid-1;
                        }else{
                            s=mid;
                        }
                    }
                //   printf("s=%lld\n",s);
                    if(query(s)*2==n){
                        ans=min(ans,(ys[tr[i-1].x-1]+1)*(m-ys[s-1]));
                 //       printf("%lld %lld %lld\n",ys[tr[i-1].x-1],ys[s-1],ans);
                    }
                }
            }
            if(i<n)add(tr[i].y);
        }
        sort(tr,tr+n,cmp4);
        memset(sum,0,sizeof(sum));
        for(ll i=0;i<=n;i++){
            if(i&&tr[i].x!=tr[i-1].x){
                ll re=query(len);
                if(re*2>=n){
                    ll s=1,e=len;
                    while(s<e){
                        ll mid=e-(e-s)/2;
                        if((re-query(mid-1))*2<n){
                            e=mid-1;
                        }else{
                            s=mid;
                        }
                    }
                    if(query(s)*2==n){
                        ans=min(ans,(m-ys[tr[i-1].x-1])*(m-ys[s-1]));
                    }
                }
            }
            if(i<n)add(tr[i].y);
        }
        if(ans==2e18)ans=-1;
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
6 8
4 5
1 4
0 3
5 3
1 2
3 2
3 1
4 0

3 3
2 0
1 1
0 2
2 2
0 0
1 1
*/


