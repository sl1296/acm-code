
#include<cstdio>
#include<algorithm>
using namespace std;
int x[1000];
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;++i){
        scanf("%d",&x[i]);
    }
    bool ch=true;
    int ans=0;
    for(int i=0;i<n/2;++i){
        if(x[i]==2&&x[n-i-1]==2){
            ans+=min(a,b)*2;
        }else if(x[i]==2){
            if(x[n-i-1]==0)ans+=a;else ans+=b;
        }else if(x[n-i-1]==2){
            if(x[i]==0)ans+=a;else ans+=b;
        }else if(x[i]!=x[n-i-1]){
            ch=false;
            break;
        }
    }
    if(n%2==1 && x[n/2]==2)ans+=min(a,b);
    if(!ch)ans=-1;
    printf("%d\n",ans);
    return 0;
}

