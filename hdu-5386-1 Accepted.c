
#include <stdio.h>
int n,m;
int a[110][110];
typedef struct op{
    char op[3];
    int x,y;
}op;
op ope[510];
void solve(){
    int count=0,i,j,ans[510];
    while(count<m){
        for(i=0;i<m;i++){
            if(!ope[i].x)continue;
            if(ope[i].op[0]=='L'){
                for(j=1;j<=n;j++){
                    if(a[j][ope[i].x] && a[j][ope[i].x]!=ope[i].y)break;
                }
                if(j>n){
                    ans[count]=i+1;
                    count++;
                    for(j=1;j<=n;j++)a[j][ope[i].x]=0;
                    ope[i].x=0;
                }
            }else{
                for(j=1;j<=n;j++){
                    if(a[ope[i].x][j] && a[ope[i].x][j]!=ope[i].y)break;
                }
                if(j>n){
                    ans[count]=i+1;
                    count++;
                    for(j=1;j<=n;j++)a[ope[i].x][j]=0;
                    ope[i].x=0;
                }
            }
        }
    }
    for(i=m-1;i>-1;i--)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
        for(i=0;i<m;i++)scanf("%s%d%d",ope[i].op,&ope[i].x,&ope[i].y);
        solve();
    }
}

