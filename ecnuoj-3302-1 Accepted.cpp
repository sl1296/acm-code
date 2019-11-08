
#include<bits/stdc++.h>
using namespace std;
int n,x,y;
long long a[10000010];
int main(){
    scanf("%d%d%d",&n,&x,&y);
    a[1]=x;
    for(int i=2;i<=n;i++){
        if(i&1){
            a[i]=min(a[i-1]+x,a[(i+1)/2]+x+y);
        }else{
            a[i]=min(a[i-1]+x,a[i/2]+y);
        }
    }
    printf("%lld\n",a[n]);
    return 0;
}

