
#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int id;
    double x;
    bool operator < (const node &p) const{
        return x<p.x;
    }
};
int a[200010],cnt[200010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        int n,m;
        scanf("%d%d",&n,&m);
        double avg=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            avg+=a[i];
        }
        avg/=m;
        priority_queue<node> qu;
        for(int i=0;i<n;++i){
            cnt[i]=1;
            double pre=a[i]/(double)cnt[i]-avg,now=a[i]/(double)(cnt[i]+1)-avg;
            qu.push((node){i,pre*pre*cnt[i]-now*now*(cnt[i]+1)});
        }
        for(int i=n;i<m;++i){
            node nn=qu.top();
            qu.pop();
            ++cnt[nn.id];
            double pre=a[nn.id]/(double)cnt[nn.id]-avg,now=a[nn.id]/(double)(cnt[nn.id]+1)-avg;
            qu.push((node){nn.id,pre*pre*cnt[nn.id]-now*now*(cnt[nn.id]+1)});
        }
        double ans=0;
        for(int i=0;i<n;++i){
            double tmp=a[i]/(double)cnt[i]-avg;
            ans+=tmp*tmp*cnt[i];
        }
        ans/=m;
        printf("Case #%d: %.10f\n",z,ans);
    }
    return 0;
}

