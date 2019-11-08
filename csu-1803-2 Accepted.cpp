
#include<cstdio>
#define ll long long
int a[3]={2,7,3};
int b[3]={5,1,2};
int n,m;
ll ans;
int c[3];
void dfs(int x,int now){
    if(x==3){
//        printf("now=%d %d %d %d\n",now,c[0],c[1],c[2]);
        ll tmp1=m/(2016/now);
        ll tmp2=n/now;
//        printf("tmp1=%lld tmp2=%lld\n",tmp1,tmp2);
        if(c[0]<b[0])tmp2-=n/(now*2);
        if(c[1]<b[1])tmp2-=n/(now*7);
        if(c[2]<b[2])tmp2-=n/(now*3);
        if(c[0]<b[0] && c[1]<b[1])tmp2+=n/(now*2*7);
        if(c[0]<b[0] && c[2]<b[2])tmp2+=n/(now*2*3);
        if(c[1]<b[1] && c[2]<b[2])tmp2+=n/(now*3*7);
        if(c[0]<b[0] && c[1]<b[1] && c[2]<b[2])tmp2-=n/(now*2*3*7);
//        printf("tmp1=%lld tmp2=%lld\n",tmp1,tmp2);
        ans+=tmp1*tmp2;
        return;
    }
    for(int i=0;i<=b[x];++i){
        c[x]=i;
        dfs(x+1,now);
        now*=a[x];
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        ans=0;
        dfs(0,1);
        printf("%lld\n",ans);
    }
    return 0;
}

