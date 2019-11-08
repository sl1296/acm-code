
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int w,p;
    bool operator < (const node q) const{
        return w<q.w;
    }
};
int m[110];
node x[110][110];
int mx[110][110];
int cal[10010],cc;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        cc=0;
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
            for(int j=0;j<m[i];j++){
                scanf("%d%d",&x[i][j].w,&x[i][j].p);
                cal[cc++]=x[i][j].w;
            }
            sort(x[i],x[i]+m[i]);
            mx[i][m[i]-1]=x[i][m[i]-1].p;
            for(int j=m[i]-2;j>=0;j--){
                mx[i][j]=min(mx[i][j+1],x[i][j].p);
            }
        }
        sort(cal,cal+cc);
        cc=unique(cal,cal+cc)-cal;
        double ans=0;
        for(int i=0;i<cc;i++){
            bool pd=true;
            int sum=0;
            for(int j=0;j<n;j++){
                int pos=lower_bound(x[j],x[j]+m[j],(node){cal[i],0})-x[j];
                if(pos==m[j]){
                    pd=false;
                    break;
                }
                sum+=mx[j][pos];
            }
            if(!pd)continue;
            ans=max(ans,cal[i]/(double)sum);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

