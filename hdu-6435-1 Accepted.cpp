
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[65];
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int n,m,k,s,x[6];
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<64;i++) v[i]=-1e15;
        for(int i=0;i<n;i++){
            scanf("%d",&s);
            for(int j=0;j<k;j++)
                scanf("%d",&x[j]);
            for(int j=0;j<1<<k;j++){
                 ll sum=s;
                 for(int l=0;l<k;l++){
                    if(j>>l&1) sum+=x[l];
                    else sum-=x[l];
                 }
                 v[j]=max(v[j],sum);
            }
        }
        ll ans=0;
        for(int i=0;i<m;i++){
            scanf("%d",&s);
            for(int j=0;j<k;j++)
                scanf("%d",&x[j]);
            for(int j=0;j<1<<k;j++){
                 ll sum=s;
                 for(int l=0;l<k;l++){
                    if(j>>l&1) sum-=x[l];
                    else sum+=x[l];
                 }
                 ans=max(ans,sum+v[j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

