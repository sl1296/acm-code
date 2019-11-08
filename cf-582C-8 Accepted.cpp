
#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[2000010],im[2000010],f[2000010],cnt[2000010],m[2000010];
__int64 ans;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int n,i,d,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(d=1;d<n;d++){
        if(n%d==0){
            memset(im,0,sizeof(im));
            for(i=0;i<d;i++){
                m[i]=a[i];
                for(j=i;j<n;j+=d)if(a[j]>m[i])m[i]=a[j];
                for(j=i;j<n*2;j+=d)if(a[j]==m[i])im[j]=1;
           // printf("%d %d %d\n",d,i,m[i]);for(j=0;j<2*n;j++)printf("%d ",im[j]);printf("\n");
            }
            f[0]=im[0];
            for(i=1;i<2*n;i++){
                if(im[i])f[i]=f[i-1]+1; else f[i]=0;
                if(f[i]>n-1)f[i]=n-1;
         //       printf("%d ",f[i]);
            }
    //        printf("\n");
            for(i=1;i<n/d;i++)cnt[i]=cnt[i-1]+(gcd(i,n/d)==1);
            for(i=n;i<n*2;i++)ans+=cnt[f[i]/d];
        //    printf("%d\n",ans);
        }
    }
    printf("%I64d\n",ans);
    return 0;
}

