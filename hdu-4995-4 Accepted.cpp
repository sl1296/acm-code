
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
        }
        double ans=0;
        int q;
        for(int i=0;i<m;i++){
            scanf("%d",&q);
            int s=ma[q],l=s-1,r=s+1;
            double sum=0;
            for(int j=0;j<k;j++){
                bool is;
                if(l<0)is=false;
                else if(r>=n)is=true;
                else if(a[r].x-a[s].x!=a[s].x-a[l].x)is=a[r].x-a[s].x>a[s].x-a[l].x;
                else is=a[r].id>a[l].id;
                if(is){
                    sum+=a[l].v;
                    l--;
                }else{
                    sum+=a[r].v;
                    r++;
                }
            }
            sum/=k;
            ans+=sum;
            a[s].v=sum;
        }
        printf("%.6f\n",ans);
    }
    return 0;
}

