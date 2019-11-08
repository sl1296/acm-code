
#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[20][20];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
        int ans=9999999;
        for(int x=0;x<(1<<n);x++){
            bool br=false;
            int tans=0;
            for(int i=0;i<n;i++){
                b[0][i]=a[0][i];
                if(x&1<<i){
                    if(b[0][i]){br=true;break;}else{tans++;b[0][i]++;}
                }
            }
            if(br)continue;
            int xx[4]={0,-1,0};
            int yy[4]={-1,0,1};
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                   // printf("i=%d j=%d ",i,j);
                    b[i][j]=a[i][j];
                    int sum=b[i][j];
                    for(int k=0;k<3;k++){
                        int tx=i-1+xx[k];
                        int ty=j+yy[k];
                       // printf("tx=%d ty=%d ",tx,ty);
                        if(tx<0||ty<0||tx>=n||ty>=n)continue;
                        sum+=b[tx][ty];
                    }
                  //  printf("sum=%d\n",sum);
                    if(sum%2)if(b[i][j]){br=true;break;}else{tans++;b[i][j]++;}
                }
                if(br)break;
            }
            if(br)continue;
            ans=min(ans,tans);
          //  printf("ans=%d\n",tans);
          //  for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",b[i][j]);printf("\n");}getchar();
        }
        if(ans==9999999)ans=-1;
        printf("Case %d: %d\n",z,ans);
    }
    return 0;
}

