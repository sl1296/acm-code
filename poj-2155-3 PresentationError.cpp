
#include<cstdio>
#include<cstring>
int a[1010][1010];
int n;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int y){
    for(int i=x;i<=n;i+=lowbit(i))for(int j=y;j<=n;j+=lowbit(j))a[i][j]++;
}
int query(int x,int y){
    int re=0;
    for(int i=x;i>0;i-=lowbit(i))for(int j=y;j>0;j-=lowbit(j))re=(re+a[i][j])&1;
    return re;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int q;
        scanf("%d%d",&n,&q);
        memset(a,0,sizeof(a));
        while(q--){
            char op[5];
            int a,b,c,d;
            scanf("%s",op);
            if(op[0]=='C'){
                scanf("%d%d%d%d",&a,&b,&c,&d);
                update(a,b);
                update(a,d+1);
                update(c+1,b);
                update(c+1,d+1);
            }else{
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b));
            }
        }
    }
    return 0;
}

