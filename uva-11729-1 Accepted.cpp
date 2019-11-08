
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct no{
    int b,j;
    bool operator < (const no &p) const{
        return p.j<j;
    }
};
no a[1005];
int main(){
    int n;
    int cas=0;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&a[i].b,&a[i].j);
        }
        sort(a,a+n);
        int ans=0;
        int tmp=0;
        for(int i=0;i<n;i++){
            tmp+=a[i].b;
            ans=max(ans,tmp+a[i].j);
        }
        cas++;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}

