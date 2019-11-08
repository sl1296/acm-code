
#include<cstdio>
#define ll long long
ll a[1030][1030];
int op,n;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int y,int v){
    for(int i=x;i<=n;i+=lowbit(i))for(int j=y;j<=n;j+=lowbit(j))a[i][j]+=v;
}
ll query(int x,int y){
    ll re=0;
    for(int i=x;i>0;i-=lowbit(i))for(int j=y;j>0;j-=lowbit(j))re+=a[i][j];
    return re;
}
int main(){
   int cc=0;
    scanf("%d%d",&op,&n);
    while(1){
        int a,b,c,d;
        scanf("%d",&op);
        if(op==3)break;
        if(op==1){
            scanf("%d%d%d",&a,&b,&c);
            a++;b++;
            cc++;
            update(a,b,c);
        }else{
            scanf("%d%d%d%d",&a,&c,&b,&d);
            a++;b++;c++;d++;cc+=4;
            printf("%lld\n",query(b,d)-query(a-1,d)-query(b,c-1)+query(a-1,c-1));
        }
        if(cc>3000001)while(1);
    }
}

