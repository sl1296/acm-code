
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt[100010];
int a[100010];
char out[100010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(cnt,0,sizeof(cnt));
        int n;
        bool pd=false;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("Case %d: ",z);
        if(n&1){
            printf("invalid\n");
            continue;
        }
        for(int i=0;i<n;i++){
            if(a[i]<n){
                cnt[a[i]]++;
            }else{
                pd=true;
                break;
            }
        }
        if(pd){
            printf("invalid\n");
            continue;
        }
        int now=0;
        for(int i=0;i<n;i++){
            if(cnt[now+1]){
                cnt[now+1]--;
                out[i]='(';
                now++;
            }else{
                if(now-1<0){
                    pd=true;
                    break;
                }else if(cnt[now-1]){
                    cnt[now-1]--;
                    out[i]=')';
                    now--;
                }else{
                    pd=true;
                    break;
                }
            }
        }
        out[n]=0;
        if(pd){
            printf("invalid\n");
        }else{
            printf("%s\n",out);
        }
    }
    return 0;
}


