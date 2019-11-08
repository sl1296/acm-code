
#include<cstdio>
#include<algorithm>
using namespace std;
int a[110][110],b[110][110];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                scanf("%d",&a[i][j]);
            }
        }
        b[0][0]=a[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0)b[i][j]=b[i-1][j]+a[i][j];
                else if(j==i)b[i][j]=b[i-1][j-1]+a[i][j];
                else b[i][j]=max(b[i-1][j-1]+a[i][j],b[i-1][j]+a[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,b[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}


