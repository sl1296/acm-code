
#include<cstdio>
#define ll long long
int euler[40000001];
ll ans[20000001];
int main(){
    for(int i=1;i<40000001;i++)euler[i]=i;
    for(int i=2;i<40000001;i++)if(euler[i]==i)for(int j=i;j<40000001;j+=i)euler[j]=euler[j]/i*(i-1);
    for(int i=1;i<20000001;i++){
        ans[i]=ans[i-1]+euler[i*2]/2;
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
}

