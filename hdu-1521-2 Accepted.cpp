
#include <cstdio>
#include <cstring>
double c1[110],c2[110],jc[110];
int a[110];
int main() {
    int n,m;
    jc[0]=1;
    for(int i=1;i<101;i++)jc[i]=jc[i-1]*i;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=a[0];i++)c1[i]=1/jc[i];
        for(int i=1;i<n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k+j<=m&&k<=a[i];k++){
                    c2[j+k]+=c1[j]/jc[k];
                }
            }
            for(int j=0;j<=m;j++)c1[j]=c2[j],c2[j]=0;
        }
        printf("%.0f\n", c1[m]*jc[m]);
    }
    return 0;
}

