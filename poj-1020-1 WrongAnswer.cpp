
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s,n;
bool ans;
int vis[100];
int a[20];
void dfs(int cs){
    if(cs==n){
        ans=true;
        return;
    }
    int mx=1;
    for(int i=1;i<=s;i++){
        if(vis[i]<vis[mx])mx=i;
    }
    for(int i=10;i>0;i--){
        if(a[i]){
            if(s-vis[mx]>=i&&s-mx+1>=i){
                bool pd=true;
                for(int j=mx,k=0;k<i;j++,k++){
                    if(vis[j]>vis[mx]){
                        pd=false;
                        break;
                    }
                }
                if(pd){
                    for(int j=mx,k=0;k<i;j++,k++){
                        vis[j]+=i;
                    }
                    a[i]--;
                    dfs(cs+1);
                    if(ans)return;
                    a[i]++;
                    for(int j=mx,k=0;k<i;j++,k++){
                        vis[j]-=i;
                    }
                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&s,&n);
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            a[tmp]++;
            sum+=tmp*tmp;
            if(tmp>s/2)cnt++;
        }
        if(cnt>1||sum!=s*s){
            printf("HUTUTU!\n");
            continue;
        }
        ans=false;
        dfs(0);
        if(ans){
            printf("KHOOOOB!\n");
        }else{
            printf("HUTUTU!\n");
        }
    }
    return 0;
}

