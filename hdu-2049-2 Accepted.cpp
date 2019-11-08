
#include<cstdio>
#define ll long long
ll cp[25]={0,0,1};
int main(){
     int t;
     scanf("%d",&t);
     for(int i=3;i<22;i++)cp[i]=(i-1)*(cp[i-1]+cp[i-2]);
     while(t--){
        int m,n;
        scanf("%d%d",&n,&m);
        ll ans=1;
        for(int i=0;i<m;i++)ans=ans*(n-i)/(i+1);
        ans=ans*cp[m];
        printf("%I64d\n",ans);
    }
    return 0;
}

