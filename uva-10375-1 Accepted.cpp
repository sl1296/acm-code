
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
int zs[10010],zsn,e[10010];
void ad(int n,int d){
    int i,ls,j;
    for(i=2;i<=n;i++){
        ls=i;
        for(j=0;j<zsn;j++){
            while(ls%zs[j]==0){
                ls/=zs[j];
                e[j]+=d;
            }
            if(ls==1)break;
        }
    }
}
int main(){
    int p,q,r,s,i,j,maxn;
    double ans;
    for(i=2;i<10010;i++)if(!zs[i])for(j=i*i;j<10010;j+=i)zs[j]=1;
    for(i=2;i<10010;i++){
        if(!zs[i]){
            zs[zsn]=i;
            zsn++;
        }
    }
    while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF){
        memset(e,0,sizeof(e));
        ad(p,1);ad(q,-1);ad(p-q,-1);ad(r,-1);ad(s,1);ad(r-s,1);
        ans=1;
        maxn=p>r?p:r;
        for(i=0;i<=maxn;i++)ans*=pow(zs[i],e[i]);
        printf("%.5lf\n",ans);
    }
    return 0;
}

