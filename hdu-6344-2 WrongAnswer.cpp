
#include<cstdio>
#include<cstring>
int a[1100];
char s[1010][12];
int ss[1010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(a,0,sizeof(a));
        memset(ss,0,sizeof(ss));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='B')ss[i]|=(1<<j);
            }
//            printf("x%d\n",ss[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                a[ss[i]^ss[j]]++;
            }
        }
        int cm=n*(n-1)/2-k,en=(1<<m)-1,ans=0;
        for(int i=0;i<en;i++){
//            printf("y%d\n",a[i]);
            if(a[i]<=cm)ans++;
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}

