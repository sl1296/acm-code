
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int b[100010],c[100010];
const ll mod=998244353;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        for(int i=0;i<n;i++)scanf("%d",&c[i]);
        if(b[0]!=c[0]||b[0]>n||b[0]<1){
            printf("0\n");
            continue;
        }
        int cnt=0;
        ll ans=1;
        for(int i=1;i<n;i++){
            if(b[i]>b[i-1]||c[i]<c[i-1]||(b[i]<b[i-1]&&c[i]>c[i-1])||b[i]<1||b[i]>n||c[i]<1||c[i]>n){
                ans=0;
                break;
            }else if(b[i]==b[i-1]&&c[i]==c[i-1]){
                if(cnt==0){
                    ans=0;
                    break;
                }
                ans=ans*cnt%mod;
            }else if(b[i]<b[i-1]&&c[i]==c[i-1]){
                cnt=cnt+b[i-1]-b[i];
            }else if(b[i]==b[i-1]&&c[i]>c[i-1]){
                cnt=cnt+c[i]-c[i-1];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

