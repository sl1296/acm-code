
#include<cstdio>
#include<algorithm>
int a[1000010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    int r=0;
    for(int i=0;i<n;++i){
        while(i+1<n && a[i+1]-a[i]<=m){
            ++i;
        }
        ++r;
    }
    printf("%d\n",r);
    return 0;
}

