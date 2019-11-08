
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100010];
int prime[1010],pc;
int num[200];
int fa[100010];
int ffind(int x){
    if(fa[x]==x)return x;
    return fa[x]=ffind(fa[x]);
}
int cal[100010];
int main(){
    int cas=1;
    for(int i=2;i<1010;i++){
        if(prime[i]==0){
            for(int j=i*i;j<1010;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<1010;i++){
        if(prime[i]==0)prime[pc++]=i;
    }
    int t;
    scanf("%d",&t);
//    printf("%d\n",pc);
//    for(int i=0;i<pc;i++){
//        printf("%d ",prime[i]);
//    }
    while(t--){
        memset(num,-1,sizeof(num));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(int j=0;j<pc;j++){
                if(a[i]%prime[j]==0){
                    if(num[j]==-1){
                        num[j]=i;
                    }else{
                        int fa1=ffind(i);
                        int fa2=ffind(num[j]);
                        if(fa1!=fa2)fa[fa1]=fa2;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            cal[i-1]=ffind(i);
        }
        sort(cal,cal+n);
        int ans=unique(cal,cal+n)-cal;
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}


