
#include<cstdio>
int a[200010],r[200010],g[200010],pre[200010];
int ps[200010],pe[200010];
bool can[200010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(!ps[a[i]])ps[a[i]]=i;
        pe[a[i]]=i;
    }
    int cnt=0;
    for(int i=q;i>0;--i){
        if(!ps[i])continue;
        for(int j=ps[i];j<=pe[i];++j){
            if(a[j]&&a[j]<i){
                printf("NO\n");
                return 0;
            }
            if(r[j])j=g[j];
            if(j>pe[i])break;
            r[j]=i;
            if(cnt==0&&a[j]==0)can[j]=true;
        }
        int from=ps[i];
        while(pre[from]){
//            printf("%d %d\n",from,pre[from]);
            from=pre[from];
        }
        int to=pe[i]+1;
        while(g[to]){
            to=g[to];
        }
        g[from]=to;
        pre[to]=from;
//        printf("%d->%d\n",from,to);
        ++cnt;
    }
    if(!ps[q]){
        bool pd=false;
        for(int i=1;i<=n;++i){
            if(r[i]==0||can[i]){
                pd=true;
                r[i]=q;
                break;
            }
        }
        if(!pd){
            printf("NO\n");
            return 0;
        }
    }
    for(int i=1;i<=n;++i){
        if(r[i]==0){
            int pos=i,mx=q;
            if(i>1)mx=r[i-1];
            while(pos<=n&&r[pos]==0)++pos;
            if(pos<=n)mx=r[pos];
            for(int j=i;j<pos;++j)r[j]=mx;
            i=pos;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;++i){
        if(i-1)printf(" ");
        printf("%d",r[i]);
    }
    printf("\n");
    return 0;
}

