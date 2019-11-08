
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int x,y;
    bool operator < (const node &p) const{
        int aa=min(x,y),bb=max(x,y);
        int ta=min(p.x,p.y),tb=max(p.x,p.y);
        if(aa!=ta)return aa<ta;
        if(bb!=tb)return bb<tb;
        return x<p.x;
    }
};
node a[500010];
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
        sort(a,a+n);
        bool ans=true;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(i+1<n&&a[i+1].x==a[i].x&&a[i+1].y==a[i].y)i++,cnt++;
            for(int j=1;j<=cnt;j++){
                if(i+cnt>=n||a[i+cnt].x!=a[i].y||a[i+cnt].y!=a[i].x){
                    ans=false;
                    break;
                }
            }
            if(!ans)break;
            i+=cnt;
        }
        if(ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

