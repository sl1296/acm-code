
//adxtm
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        ll pd=1;
        for(int i=0;i<n;i++)pd*=10;
        ll e=k;
        int ans=k;
        map<int,int> s;
        while(!s[e]){
            s[e]=false;
            if(e>ans)ans=e;
            e=e*e;
            while(e>=pd)e/=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}

