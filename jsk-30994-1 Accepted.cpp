
#include<cstdio>
#define ll long long
using namespace std;
struct node{
    ll x,y;
    int c;
} ;
ll cal[1048600],ans;
node x[25];
int main(){
    for(int i=1;i<1048600;++i)cal[i]=-1;
    int n,k,pre;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        x[i].c=0;
        scanf("%lld%lld%d",&x[i].x,&x[i].y,&k);
        for(int j=0;j<k;++j){
            scanf("%d",&pre);
            --pre;
            x[i].c|=(1<<pre);
        }
    }
    for(int _=1;_<(1<<n);++_){
        int num=0;
        for(int i=0;i<n;++i)if((1<<i)&_)++num;
        for(int i=0;i<n;++i){
//            printf("i=%d %d %d\n",i,x[i].c,cal[(1<<i)^_]);
            if(((1<<i)&_) && (x[i].c&_)==x[i].c && cal[(1<<i)^_]!=-1){
                ll now=cal[(1<<i)^_]+x[i].y+num*x[i].x;
                if(cal[_]<now)cal[_]=now;
//                printf("%d %d %lld\n",_,i,cal[_]);
            }
        }
        if(ans<cal[_])ans=cal[_];
//        printf("ans=%lld\n",ans);
    }
    printf("%lld\n",ans);
}

