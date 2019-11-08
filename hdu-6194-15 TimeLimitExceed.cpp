
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rrank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
    /* for(int ii=1;ii<=n;ii++){
        if(ii>=maxn)while(1);
        if(sa[ii]>=maxn||sa[ii]<0)while(1);
     }*/
     for(i=1;i<=n;i++) rrank[sa[i]]=i;
     for(i=0;i<n;height[rrank[i++]]=k)
     for(k?k--:0,j=sa[rrank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int RMQ[maxn];
int mm[maxn];
int best[30][maxn];
void initRMQ(int n)
{
     int i,j,a,b;
     for(mm[0]=-1,i=1;i<=n;i++)
     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
     for(i=1;i<=n;i++) best[0][i]=i;
     for(i=1;i<=mm[n];i++)
     for(j=1;j<=n+1-(1<<i);j++)
     {
       a=best[i-1][j];
       b=best[i-1][j+(1<<(i-1))];
       if(RMQ[a]<RMQ[b]) best[i][j]=a;
       else best[i][j]=b;
     }
     return;
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];b-=(1<<t)-1;
    if(t<0||t>=1000)while(1);
  //  if(a<0||a>=maxn)while(1);
  //  if(b<0||b>=maxn)while(1);
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
char str[maxn];
int sa[maxn],r[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(RMQ,0,sizeof(RMQ));
        memset(mm,0,sizeof(mm));
        memset(best,0,sizeof(best));
        memset(rrank,0,sizeof(rrank));
        memset(height,0,sizeof(height));
        memset(sa,0,sizeof(sa));
        memset(r,0,sizeof(r));
        memset(wa,0,sizeof(wa));
        memset(wb,0,sizeof(wb));
        memset(wv,0,sizeof(wv));
        memset(ws,0,sizeof(ws));
        int nn;
        scanf("%d%s",&nn,str);
        int len=strlen(str);
        for(int i=0;i<len;i++){
            r[i]=str[i];
        }
        da(r,sa,len+1,200);
        calheight(r,sa,len);
//        for(int i=0;i<=len;i++){
//            printf("%d ",sa[i]);
//        }
//        printf("\n");
//        for(int i=0;i<=len;i++){
//            printf("%d ",height[i]);
//        }
//        printf("\n");
//        for(int i=0;i<=len;i++){
//            printf("%d ",rrank[i]);
//        }
//        printf("\n");
        for(int i=2;i<=len;i++){
            RMQ[i]=height[i];
        }
        initRMQ(len);
        long long ans=0;
        for(int i=1;i<=len-nn+1;i++){
            int l=i,r=i+nn-1;
            int tmp=askRMQ(l+1,r);
            if(tmp<0||tmp>=maxn)while(1);
            int now=height[askRMQ(l+1,r)];
            int side=0;
            if(l>=2){
                tmp=askRMQ(l,r);
                if(tmp<0||tmp>=maxn)while(1);
            }
            if(l>=2)side=max(side,height[askRMQ(l,r)]);
            if(r+1<=len){
                tmp=askRMQ(l+1,r+1);
                if(tmp<0||tmp>=maxn)while(1);
            }
            if(r+1<=len)side=max(side,height[askRMQ(l+1,r+1)]);
            if(side<now)ans+=now-side;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

