
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int u[100100],v[100100];
int n;
bool pd(int x){
    int p=a[0],q=x-a[0];
    u[0]=p;v[0]=0;
    for(int i=1;i<n;i++){
        if(i%2){
            u[i]=min(p-u[i-1],a[i]);
            v[i]=a[i]-u[i];
        }else{
            v[i]=min(q-v[i-1],a[i]);
            u[i]=a[i]-v[i];
        }
    }
    if(u[n-1])return false;
    return true;
}
int main(){
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        if(n==1){
            printf("%d\n",a[0]);
            continue;
        }
        a[n]=a[0];
        int l=0,r=0,m;
        for(int i=0;i<n;i++)l=max(l,a[i]+a[i+1]);
        if(n%2){
            for(int i=0;i<n;i++)r=max(r,a[i]*3);
            while(l<r){
                m=l+(r-l)/2;
                if(pd(m))r=m;else l=m+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}

