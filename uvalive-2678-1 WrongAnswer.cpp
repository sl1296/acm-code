
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int l=0,r=0,sum=0,ans=n+1;
        while(r<n && sum<s){
            sum+=a[r];
            r++;
        }
        ans=min(r-l,ans);
        while(r<n){
            sum-=a[l];
            l++;
            while(r<n && sum<s){
                sum+=a[r];
                r++;
            }
            ans=min(r-l,ans);
        }
        do{
            ans=min(r-l,ans);
            sum-=a[l];
            l++;
        }while(sum>=s);
        printf("%d\n",ans);
    }
    return 0;
}

