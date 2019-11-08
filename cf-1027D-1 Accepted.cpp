
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200010],c[200010],id[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int cnt=1,ans=0;
    for(int i=1;i<=n;++i){
        if(!id[i]){
            int ss=i,now=i;
            bool cal=true;
            while(1){
                id[now]=cnt;
                now=a[now];
                if(id[now]<cnt && id[now]>0){
                    cal=false;
                    break;
                }else if(id[now]==cnt){
                    ss=now;
                    break;
                }
            }
            if(cal){
                int tmp=c[now];
                do{
                    now=a[now];
                    tmp=min(tmp,c[now]);
                }while(now!=ss);
                ans+=tmp;
            }
            ++cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}

