
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std ;
const int maxn = 1000005 ;

int wa[maxn],wb[maxn],wv[maxn],wss[maxn];
int cmp(int *r,int a,int b,int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m) {
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) wss[i]=0;
    for(i=0; i<n; i++) wss[x[i]=r[i]]++;
    for(i=1; i<m; i++) wss[i]+=wss[i-1];
    for(i=n-1; i>=0; i--) sa[--wss[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p) {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) wss[i]=0;
        for(i=0; i<n; i++) wss[wv[i]]++;
        for(i=1; i<m; i++) wss[i]+=wss[i-1];
        for(i=n-1; i>=0; i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int rrank[maxn],height[maxn];
void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1; i<=n; i++) rrank[sa[i]]=i;
    for(i=0; i<n; height[rrank[i++]]=k)
        for(k?k--:0,j=sa[rrank[i]-1]; r[i+k]==r[j+k]; k++);
    return;
}
int RMQ[maxn];
int mm[maxn];
int best[40][maxn];
void initRMQ(int n) {
    int i,j,a,b;
    for(mm[0]=-1,i=1; i<=n; i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(i=1; i<=n; i++) best[0][i]=i;
    for(i=1; i<=mm[n]; i++)
        for(j=1; j<=n+1-(1<<i); j++) {
            a=best[i-1][j];
            b=best[i-1][j+(1<<(i-1))];
            if(RMQ[a]<RMQ[b]) best[i][j]=a;
            else best[i][j]=b;
        }
    return;
}
int askRMQ(int a,int b) {
    int t;
    t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];
    b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b) {
    int t;
    a=rrank[a];
    b=rrank[b];
    if(a>b) {
        t=a;
        a=b;
        b=t;
    }
    return(height[askRMQ(a+1,b)]);
}

char str[maxn] ;
int r[maxn] ;
int sa[maxn] ;
int main() {
    int t ;
    scanf("%d",&t) ;
    while(t--) {
        int k ;
        scanf("%d",&k) ;
        scanf("%s",str) ;
        int len = strlen(str) ;
        for(int i=0;i<len;i++){
            r[i] = str[i] ;
        }
        r[len] = 0;
        memset(sa,0,sizeof(sa));
        memset(height,0,sizeof(height));
        memset(RMQ,0,sizeof(RMQ));
        memset(mm,0,sizeof(mm));
        memset(best,0,sizeof(best));
        da(r,sa,len+1,200) ;
        calheight(r,sa,len) ;
//        for(int i=0; i<len; i++) {
//            printf("%d ",rrank[i]) ;
//        }
//        printf("\n") ;
//        for(int i=1; i<=len; i++) {
//            printf("%d ",sa[i]) ;
//        }
//        printf("\n") ;
//        for(int i=2; i<=len; i++) {
//            printf("%d ",height[i]) ;
//        }
//        printf("\n") ;


        for(int i=2; i<=len; i++) {
            RMQ[i] = height[i] ;
        }
        initRMQ(len) ;
        LL ans =  0;
        k--;
        for(int i=1;i<=len-k;i++){
            int l = i ;
            int r = i+k ;
            int minx = height[askRMQ(l+1,r)] ;
            int x1 = l-1<=0?0:height[askRMQ(l,r)] ;
            int x2 = r+1>len?0:height[askRMQ(l+1,r+1)] ;
//            printf("%d %d\n",i+1,i+k) ;
//            printf("minx = %d  x1 = %d x2 = %d\n",minx,x1,x2) ;
            if(max(x1,x2)>=minx)continue ;
            else ans+=minx-max(x1,x2) ;
        }
        printf("%I64d\n",ans) ;
    }
}
/*
2
2
abcabc
3
abcabcabcabc

*/

