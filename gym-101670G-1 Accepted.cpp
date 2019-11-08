
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000010];
int s[1000010];
int cnt[1000010];
int main(){
    int n,k,l;
    while(~scanf("%d%d",&n,&k)){
        int now=0;
        for(int i=0;i<n;++i){
            s[i]=now;
            scanf("%d",&l);
            for(int j=0;j<l;++j){
                scanf("%d",&a[now+j]);
            }
            now+=l;
        }
        s[n]=now;
        int all=0;
        for(int i=0;i<now;++i){
            ++cnt[a[i]];
            if(cnt[a[i]]==1)++all;
        }
        for(int i=0;i<now;++i)--cnt[a[i]];
        if(all<k){
            printf("-1\n");
            continue;
        }
        all=0;
        int pp=1,tmp=s[1]-s[0];
        for(int i=0;i<s[1];++i){
            ++cnt[a[i]];
            if(cnt[a[i]]==1)++all;
        }
        while(all<k){
            for(int i=s[pp];i<s[pp+1];++i){
                ++cnt[a[i]];
                if(cnt[a[i]]==1)++all;
            }
            tmp+=s[pp+1]-s[pp];
            ++pp;
            if(pp==n)pp=0;
        }
        int ans=tmp;
        for(int i=1;i<n;++i){
            tmp-=s[i]-s[i-1];
            for(int j=s[i-1];j<s[i];++j){
                --cnt[a[j]];
                if(cnt[a[j]]==0)--all;
            }
            while(all<k){
                for(int j=s[pp];j<s[pp+1];++j){
                    ++cnt[a[j]];
                    if(cnt[a[j]]==1)++all;
                }
                tmp+=s[pp+1]-s[pp];
                ++pp;
                if(pp==n)pp=0;
            }
            ans=min(ans,tmp);
        }
        printf("%d\n",ans);
        for(int i=1;i<=k;++i)cnt[i]=0;
    }
    return 0;
}
/*
4 3
4 1 3 1 3
1 2
2 3 3
1 1
*/

