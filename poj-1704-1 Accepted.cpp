
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int s[101],tt[10001],k;
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int g(int x){
    int mex[101],i;
    memset(mex,0,sizeof(mex));
    if(tt[x]!=-1)return tt[x];
    if(x-s[0]<0)return tt[x]=0;
    for(i=0;i<k && x-s[i]>=0;i++)mex[g(x-s[i])]=1;
    for(i=0;;i++)if(!mex[i])return tt[x]=i;
}
int main(){
    int n,t,a,ans,i;
    while(1){
        scanf("%d",&k);
        if(!k)break;
        memset(tt,-1,sizeof(tt));
        tt[0]=0;
        for(i=0;i<k;i++)scanf("%d",&s[i]);
        qsort(s,k,sizeof(int),*cmp);
        scanf("%d",&t);
        while(t--){
            ans=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                ans^=g(a);
            }
            if(!ans)printf("L"); else printf("W");
        }
        printf("\n");
    }
    return 0;
}

