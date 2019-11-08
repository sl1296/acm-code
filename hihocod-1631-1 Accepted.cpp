
#include<bits/stdc++.h>
using namespace std;
#define maxn 111
int v[maxn],c[maxn];
int main(){
    int m,n,x;
    while(scanf("%d%d%d",&m,&n,&x)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&c[i]);
        sort(c,c+n);
        memset(v,0,sizeof(v));
        for(int i=0;i<min(n,m);i++)
            v[i]+=c[i];
        m-=min(n,m);
        while(x--){
            for(int i=0;i<n;i++){
                if(v[i]==0) continue;
                v[i]--;
                if(v[i]==0&&m&&x){
                    v[i]+=c[i];
                    m--;
                }
            }
        }
        int p=0;
        for(int i=0;i<n;i++)
            if(v[i]) p++;
        printf("%d %d\n",m,p);
    }
    return 0;
}

