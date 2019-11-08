
#include<cstdio>
#include<cstring>
int a[50010],n,ans[50010],m,t;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))a[i]+=v;
}
int query(int x){
    int re=0;
    for(int i=x;i>0;i=i-lowbit(i))re+=a[i];
    return re;
}
int main(){
    while(~scanf("%d",&n)){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)update(i,1);
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            int l=1,r=n;
            while(r>l){
                int m=l+(r-l)/2;
                int re=query(m);
                if(re>t){
                    r=m-1;
                }else if(re<t){
                    l=m+1;
                }else{
                    r=m;
                }
            }
            update(l,-1);
            ans[i+1]=l;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&t);
            if(i)printf(" ");
            printf("%d",ans[t]);
        }
        printf("\n");
    }
    return 0;
}

