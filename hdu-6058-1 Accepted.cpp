
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500010],pre[500010],nex[500010],b[500010],tq[200];
bool cmp(int x,int y){
    return a[x]<a[y];
}
/*void out(int n){
    printf("a:");
    for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\nb:");
    for(int i=0;i<n;i++)printf("%d ",b[i]);printf("\npre:");
    for(int i=0;i<n;i++)printf("%d ",pre[i]);printf("\nnex:");
    for(int i=0;i<n;i++)printf("%d ",nex[i]);printf("\n");
}*/
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll ans=0;
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            pre[i]=i-1;
            nex[i]=i+1;
            b[i]=i;
        }
        nex[n-1]=-1;
        sort(b,b+n,cmp);
      //  out(n);
        for(int i=0;i<n;i++){
            if(n-i<k)break;
         //   printf("i=%d\n",i);
          //  out(n);
            tq[100]=b[i];
            int s=99,e=101,now=b[i];
            while(s>99-k&&pre[now]!=-1){
                now=pre[now];
                tq[s--]=now;
            }
            now=b[i];
            while(e<101+k&&nex[now]!=-1){
                now=nex[now];
                tq[e++]=now;
            }
            if(s>99-k)tq[s--]=-1;
            if(e<101+k)tq[e++]=n;
         //   printf("s=%d e=%d\n",s,e);
         //   for(int j=s+1;j<e;j++)printf("%d(%d) ",tq[j],j);printf("\n");
            for(int j=s+1;j<100&&j+k+1<e;j++){
            //    printf("  j=%d %d~%d %d~%d\n",j,j,j+1,j+k,j+k+1);
                ll le=tq[j+1]-tq[j];
                ll ri=tq[j+k+1]-tq[j+k];
                ans+=le*ri*a[b[i]];
             //   printf("  ans=%lld %lld %lld %d\n",ans,le,ri,a[b[i]]);
            }
            now=b[i];
            if(pre[now]!=-1)nex[pre[now]]=nex[now];
            if(nex[now]!=-1)pre[nex[now]]=pre[now];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

