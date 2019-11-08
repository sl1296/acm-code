
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int l,r;
    bool operator < (const node &p) const{
        if(l!=p.l)return l<p.l;
        return r<p.r;
    }
};
node a[5010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a,a+n);
        int p=0;
        for(int i=0;i<n;i++){
            while(i+1<n&&a[i+1].l==a[i].l)i++;
            a[p++]=a[i];
        }
        int ans=0;
        int cnt=0;
        for(int i=p-1;i>=0;i--){
            if(a[i].r>cnt){
                cnt=a[i].r;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

