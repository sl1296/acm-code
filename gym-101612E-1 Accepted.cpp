
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
#define maxn 300010
int n,a[maxn];
bool cl[1000010],bj[1000010],zs[1000010];
int zc[1000010],zf[1000010][10],zfc[1000010][10];
void dfs(int u,int i,ll x){
    if(i==zc[u]){
        if(x!=u)bj[x]=true;
        return;
    }
    for(int j=0;j<=zfc[u][i];++j){
        dfs(u,i+1,x);
        x*=zf[u][i];
    }
}
inline void init(){
    for(int i=2;i<1000010;++i){
        if(!zs[i]){
            zf[i][0]=i;
            zc[i]=1;
            for(ll j=i+i;j<1000010;j+=i){
                zs[j]=true;
                zf[j][zc[j]++]=i;
            }
        }
    }
    cl[1]=true;
    for(int i=0;i<n;++i){
        if(!cl[a[i]]){
            bj[1]=true;
            cl[a[i]]=true;
            int tmp=a[i],cnt=1;
            for(int j=0;j<zc[a[i]];++j){
                while(tmp%zf[a[i]][j]==0){
                    tmp/=zf[a[i]][j];
                    ++zfc[a[i]][j];
                }
            }
            dfs(a[i],0,1);
        }
    }
}
int num[1000010];
int b[maxn],c[maxn];
int main(){
    freopen("equal.in","r",stdin);
    freopen("equal.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        num[a[i]]++;
    }
    init();
    int l1=0,l2=0;
    int cnt=0;
    for(int i=1;i<=1000000;i++){
        if(!num[i]) continue;
        cnt++;
        if(bj[i]) b[l1++]=num[i];
        c[l2++]=num[i];
    }
    sort(b,b+l1);
    sort(c,c+l2);
    for(int i=1;i<l1;i++)
        b[i]+=b[i-1];
    for(int i=1;i<l2;i++)
        c[i]+=c[i-1];
    for(int k=0;k<=n;k++){
        int ans=upper_bound(b,b+l1,k)-b;
        ans=max(ans,upper_bound(c,c+l2,k)-c-1);
        printf("%d%c",cnt-ans,k==n?'\n':' ');
    }
    return 0;
}

