
#include<bits/stdc++.h>
using namespace std;
struct no{
    int id;
    int x;
    double v;
    bool operator < (const no &p) const{
        return p.x>x;
    }
};
no a[100010];
map<int,int> ma;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ma.clear();
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++){
            scanf("%d%lf",&a[i].x,&a[i].v);
            a[i].id=i+1;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            ma[a[i].id]=i;
           // printf("%d %d %lf\n",a[i].id,a[i].x,a[i].v);
        }
        double ans=0;
        int q;
        for(int i=0;i<m;i++){
            scanf("%d",&q);
            int s=ma[q],l=s-1,r=s+1,ne,ve,pd;
            double sum=0;
           // printf("%d %d %d\n",l,s,r);
            for(int j=0;j<k;j++){
                pd=9999999;
                if(l>-1 && pd>a[s].x-a[l].x){
                    pd=a[s].x-a[l].x;
                    ve=a[l].v;
                    ne=l;
                }
             //   printf("pd=%d ",pd);
                if(r<n && pd>a[r].x-a[s].x){
                    pd=a[r].x-a[s].x;
                    ve=a[r].v;
                    ne=r;
                }
              //  printf("pd=%d ",pd);
                if(ve==a[r].v)r++;else l--;
                sum+=ve;
             //   printf("ve=%d,ne=%d\n",ve,ne);
            }
            sum/=k;
            ans+=sum;
          //  printf("sum,%f\n",sum);
            a[s].v=sum;
        }
        printf("%.6f\n",ans);
    }
    return 0;
}

