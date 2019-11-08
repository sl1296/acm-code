
#include<cstdio>
#include<cstring>
int cnt[100010];
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))cnt[i]+=v;
}
int sum(int x){
    int r=0;
    for(int i=x;i>0;i-=lowbit(i))r+=cnt[i];
    return r;
}
int main(){
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,1);
            add(b+1,-1);
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",sum(i),i<n?' ':'\n');
        }
    }
    return 0;
}

