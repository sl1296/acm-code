
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int a[300010],n;
inline int pd(int x){
    ll cnt=0,cc=0,cnt2=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]>x+1){
            cnt+=(a[i]-x)/2;
            if((a[i]-x)%2==0)cc++;
        }else if(a[i]<x){
            cnt2+=x-a[i];
        }
    }
    if(cnt2>cnt)return 2;
    if(cnt2+cc<cnt)return 1;
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ss=0,ee=100000000;
        while(ss<ee){
            int mid=ee-(ee-ss)/2;
            int ret=pd(mid);
            if(ret==1)ss=mid+1;
            else if(ret==2) ee=mid-1;
            else ss=mid;
        }
        printf("%d\n",ss);
    }
    return 0;
}

