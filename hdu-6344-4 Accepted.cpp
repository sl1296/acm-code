


#include<cstdio>
#include<cstring>
int a[1100],b[1100];
char s[1010][12];
int ss[1010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
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
        int en=1<<m;
        for(int i=0;i<en;i++){
            for(int j=i+1;j<en;j++){
                if((i|j)==j){
                    b[j]+=a[i];
                }
            }
            b[i]+=a[i];
        }
        int cm=n*(n-1)/2-k,ans=0;
        for(int i=0;i<en;i++){
//            printf("y%d %d\n",a[i],b[i]);
            if(b[i]<=cm)ans++;
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
/*
5 3 1
AAA
AAB
ABA
BBB
BAA
*/



