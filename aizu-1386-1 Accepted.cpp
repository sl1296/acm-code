
#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    bool operator < (const node &p) const{
        if(x!=p.x)return x<p.x;
        return y<p.y;
    }
}a[200010];
int px[100010],py[100010],ps[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i].x,&a[i].y);
        px[a[i].x]++;
        py[a[i].y]++;
        ps[a[i].x]++;
        ps[a[i].y]--;
    }
    int ans1=0,ans2=0,cnt=0;
    for(int i=1;i<=100000;i++){
        px[i]+=px[i-1];
        py[i]+=py[i-1];
        cnt+=ps[i];
        ans2=max(ans2,cnt);
    }
    for(int i=0;i<n;i++){
        ans1=max(ans1,px[a[i].y-1]-py[a[i].x]);
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}

