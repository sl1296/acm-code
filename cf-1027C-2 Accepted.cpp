
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int r1=-1,r2=-1,pre=-1;
        for(int i=0;i<n;++i){
            int now=1;
            while(i+1<n&&a[i+1]==a[i]){
                ++i;
                ++now;
            }
            if(now>3){
                r1=r2=a[i];
            }else if(now>1){
                if(pre==-1)pre=a[i];
                else if(r1==-1){
                    r1=pre;
                    r2=a[i];
                    pre=a[i];
                }else{
                    if((double)r1/r2+(double)r2/r1>(double)pre/a[i]+(double)a[i]/pre){
                        r1=pre;
                        r2=a[i];
                    }
                    pre=a[i];
                }
            }
        }
        printf("%d %d %d %d\n",r1,r1,r2,r2);
    }
    return 0;
}

