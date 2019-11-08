


#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=-1;
        for(int i=n-3;i>=0;--i){
            if(a[i]+a[i+1]>a[i+2]){
                ans=a[i]+a[i+1]+a[i+2];
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



