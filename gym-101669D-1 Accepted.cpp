
#include<cstdio>
int x[100010],fa[100010],cc[100010];
int ffind(int x){
    return fa[x]==x?x:fa[x]=ffind(fa[x]);
}
int main(){
    int m,n,k,c,ans=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=100000;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        scanf("%d",&k);
        for(int j=0;j<k;++j){
            scanf("%d",&c);
            ++cc[c];
            if(x[c]==0)x[c]=i;
            else{
                int ta=ffind(x[c]);
                int tb=ffind(i);
                if(ta!=tb){
                    ++ans;
                    fa[ta]=tb;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(cc[i]!=2)while(1);
    }
    printf("%d\n",ans);
    return 0;
}

