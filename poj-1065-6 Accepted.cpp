
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
bool is[5010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
            is[i]=false;
        }
        int ans=0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(!is[i]){
                int mx=a[i].r;
                for(int j=i+1;j<n;j++){
                    if(a[j].r>=mx&&is[j]==false){
                        mx=a[j].r;
                        is[j]=true;
                    }
                }
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

