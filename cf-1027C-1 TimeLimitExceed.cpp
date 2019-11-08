
#include<cstdio>
#include<cstring>
int cnt[10010];
int add[10010],addn;
int main(){
    int t,a;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        addn=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            ++cnt[a];
        }
        bool fin=false;
        int r1,r2;
        for(int i=1;i<10001;++i){
            if(cnt[i]>1){
                add[addn++]=i;
                if(cnt[i]>3){
                    fin=true;
                    r1=i;
                    break;
                }
            }
        }
        if(fin){
            printf("%d %d %d %d\n",r1,r1,r1,r1);
            continue;
        }
        r1=add[0];r2=add[1];
        for(int i=2;i<addn;++i){
            if((double)r1/r2+(double)r2/r1>(double)add[i-1]/add[i]+(double)add[i]/add[i-1]){
                r1=add[i-1];
                r2=add[i];
            }
        }
        printf("%d %d %d %d\n",r1,r1,r2,r2);
    }
    return 0;
}

