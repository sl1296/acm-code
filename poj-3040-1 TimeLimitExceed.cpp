
#include<cstdio>
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
node get[25];
int getn;
int main(){
   // system("chcp 936");
    int n,c;
    while(~scanf("%d%d",&n,&c)){
        int all=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].v,&a[i].b);
            all+=a[i].b;
        }
        sort(a,a+n);
        int p=0;
        int ans=0;
        while(a[p].v>=c){
            ans+=a[p].b;
            all-=a[p].b;
            p++;
        }
        while(all){
            int tmp=c;
            getn=0;
            for(int i=p;i<n;i++){
                if(a[i].b==0)continue;
                get[getn].b=min(tmp/a[i].v,a[i].b);
              //  printf("tmp=%d i=%d v=%d b=%d gb=%d\n",tmp,i,a[i].v,a[i].b,get[getn].b);
                if(get[getn].b==0)break;
                tmp-=a[i].v*get[getn].b;
                get[getn++].v=i;
            }
            if(tmp>0){
                for(int i=n-1;i>=p;i--){
                    if(a[i].b==0)continue;
                    get[getn].b=min(tmp/a[i].v+1,a[i].b);
                    tmp-=a[i].v*get[getn].b;
                    get[getn++].v=i;
                    if(tmp<=0)break;
                }
            }
            if(tmp>0)break;
            sort(get,get+getn);
            int pp=0;
            for(int i=0;i<getn;i++){
                if(i+1<getn&&get[i+1].v==get[i].v){
                    i++;
                    get[i].b+=get[i-1].b;
                }
                get[pp++]=get[i];
             //   printf("%d %d\n",get[i].v,get[i].b);
            }
            int maxn=INF;
            for(int i=0;i<pp;i++){
                maxn=min(maxn,a[get[i].v].b/get[i].b);
            }
            ans+=maxn;
          //  printf("max=%d\n",maxn);
            for(int i=0;i<pp;i++){
                a[get[i].v].b-=get[i].b*maxn;
                all-=get[i].b*maxn;
            }
           // printf("ans=%d all=%d\n",ans,all);
        }
        printf("%d\n",ans);
    }
    return 0;
}

