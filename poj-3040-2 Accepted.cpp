
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=2147483600;
struct node{
    int v,b;
    bool operator < (const node &p) const{
        return v>p.v;
    }
};
node a[25];
int need[25];
int main(){
   // system("chcp 936");
    int n,c;
    while(~scanf("%d%d",&n,&c)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].v,&a[i].b);
        }
        sort(a,a+n);
        int p=0;
        int ans=0;
        while(a[p].v>=c){
            ans+=a[p].b;
            p++;
        }
        while(1){
            int tmp=c;
            memset(need,0,sizeof(need));
            for(int i=p;i<n;i++){
                if(a[i].b==0)continue;
                need[i]=min(tmp/a[i].v,a[i].b);
                tmp-=need[i]*a[i].v;
                if(tmp==0)break;
            }
            if(tmp>0){
                for(int i=n-1;i>=p;i--){
                    if(a[i].b-need[i]==0)continue;
                    int more=min(a[i].b-need[i],(tmp+a[i].v-1)/a[i].v);
                    need[i]+=more;
                    tmp-=more*a[i].v;
                    if(tmp<=0)break;
                }
            }
            if(tmp>0)break;
            int maxn=INF;
            for(int i=p;i<n;i++){
                if(need[i]==0)continue;
                maxn=min(maxn,a[i].b/need[i]);
            }
            ans+=maxn;
            for(int i=p;i<n;i++){
                a[i].b-=maxn*need[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

