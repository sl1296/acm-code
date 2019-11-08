
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[1010],pc;
int num[1000010];
int fa[100010];
int ffind(int x){
    if(fa[x]==x)return x;
    return fa[x]=ffind(fa[x]);
}
int use[1000010],usec;
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
    memset(num,-1,sizeof(num));
    int t;
    scanf("%d",&t);
    while(t--){
        usec=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
          /*  for(int j=0;j<pc;j++){
                if(a[i]%prime[j]==0){
                    if(num[j]==-1){
                        num[j]=i;
                    }else{
                        int fa1=ffind(i);
                        int fa2=ffind(num[j]);
                        if(fa1!=fa2)fa[fa1]=fa2;
                    }
                }
            }*/
            for(int j=0;j<pc;j++){
                if(a%prime[j]==0){
                    while(a%prime[j]==0)a/=prime[j];
                    if(num[prime[j]]==-1){
                        num[prime[j]]=i;
                        use[usec++]=prime[j];
                    }else{
                        int fa1=ffind(i);
                        int fa2=ffind(num[prime[j]]);
                        if(fa1!=fa2)fa[fa1]=fa2;
                    }
                    if(a==1)break;
                }
            }
            if(a>1){
                if(num[a]==-1){
                    num[a]=i;
                }else{
                    int fa1=ffind(i);
                    int fa2=ffind(num[a]);
                    if(fa1!=fa2)fa[fa1]=fa2;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==fa[i])ans++;
        }
        printf("Case %d: %d\n",cas++,ans);
        for(int i=0;i<usec;i++){
            num[use[i]]=-1;
        }
    }
    return 0;
}


