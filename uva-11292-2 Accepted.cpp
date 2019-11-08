
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int dr[20010],pe[20010];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        if(n+m==0)break;
        for(int i=0;i<n;i++){
            scanf("%d",&dr[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&pe[i]);
        }
        sort(dr,dr+n);
        sort(pe,pe+m);
        int c=0;
        int ans=0;
        for(int i=0;i<m;i++){
            if(pe[i]>=dr[c]){
                c++;
                ans+=pe[i];
                if(c==n)break;
            }
        }
        if(c==n)printf("%d\n",ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
//
}

