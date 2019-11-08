
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
node a[50010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            int l=a[i].l,r=a[i].r;
            while(i+1<n&&a[i+1].l<=r){
                i++;
                r=max(a[i].r,r);
            }
            printf("%d %d\n",l,r);
        }
    }
    return 0;
}

