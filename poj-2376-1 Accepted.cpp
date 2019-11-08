
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int l,r;
    bool operator < (const node &p) const{
        return l<p.l;
    }
};
node a[25010];
int main(){
    int n,t;
    while(~scanf("%d%d",&n,&t)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a,a+n);
        int en=1;
        int p=0;
        int ans=0;
        while(en<=t){
            int mi=-1;
            for(;p<n;p++){
                if(a[p].l>en)break;
                mi=max(mi,a[p].r);
            }
            if(mi==-1){
                ans=-1;
                break;
            }
            ans++;
            en=mi+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

