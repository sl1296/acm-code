


#include<cstdio>
#include<cstring>
using namespace std;
char s[100010];
int cnt[26][100010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        printf("Case #%d:\n",z);
        memset(cnt,0,sizeof(cnt));
        int n,q;
        scanf("%d%d%s",&n,&q,s);
        int len=strlen(s);
        for(int i=1;i<=len;i++){
            for(int j=0;j<26;j++)cnt[j][i]=cnt[j][i-1];
            cnt[s[i-1]-'A'][i]++;
        }
        for(int i=0;i<q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            int ans;
            for(int j=0;j<26;j++){
                ans=cnt[j][r]-cnt[j][l-1];
                if(ans)break;
            }
            printf("%d\n",ans);
        }
    }
}



