
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200010],s[200010],e[200010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            s[i]=e[i]=0;
        }
        a[n]=0;
        s[0]=a[0];
        for(int i=1;i<=n;++i){
            if(a[i]>a[i-1]){
                s[i]=a[i]-a[i-1];
            }else if(a[i]<a[i-1]){
                e[i]=a[i-1]-a[i];
            }
        }
//        for(int i=0;i<=n;++i)printf("%d ",s[i]);printf("\n");
//        for(int i=0;i<=n;++i)printf("%d ",e[i]);printf("\n");
//        printf("e3=%d\n",e[3]);
        int ep=1,dec;
        bool ch=true;
        for(int i=0;i<n;++i){
//                 printf("e3=%d\n",e[3]);
//            printf("i=%d\n",i);
            while(s[i]){
//                 printf("e3=%d\n",e[3]);
                while(e[ep]==0){
//                     printf("e3=%d\n",e[3]);
//                    printf("ep=%d e=%d\n",ep,e[ep]);
                    ++ep;
                }
                if(ep<i+3){
                    ch=false;
                    goto en;
                }
//                printf("%d %d %d\n",i,ep,min(e[ep],s[i]));
                dec=min(e[ep],s[i]);
                e[ep]-=dec;
                s[i]-=dec;
            }
        }
        en:
        if(ch)printf("Case #%d: Yes\n",z);
        else printf("Case #%d: No\n",z);
    }
    return 0;
}

