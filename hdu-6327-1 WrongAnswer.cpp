
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int m;
ll a[110],v[110];
ll zs[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};//25
ll mx[30]={7,5,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
ll fj[110][30];
//ll fj2[110][30];
ll tj[4][30][10];
ll zhs[5][5]={
{1},
{1,1},
{1,2,1},
{1,3,3,1},
{1,4,6,4,1}
};
//ll x4;
//bool isx4;
//int inzs[100010],inzsn;
//bool inuse[100010];
//int inka[900],inkan;
//ll mx3[900];
//ll fj3[4][900][40];
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll q=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
ll inv(ll a,ll n){
    ll x,y,d=exgcd(a,n,x,y);
    if(d==1)return (x%n+n)%n;
    else return -1;
}
//void cal(){
//    memset(inuse,false,sizeof(inuse));
//    memset(fj3,0,sizeof(fj3));
//    memset(mx3,0,sizeof(mx3));
//    isx4=true;
//    x4=1;
//    for(int i=1;i<=m;i++){
//        ll tmp=v[i];
//        for(int j=0;inzs[j]*inzs[j]<=tmp;j++){
//            if(tmp%inzs[j]==0){
//                if(!inuse[j]){
//                    inuse[j]=true;
//                    inka[inkan++]=inzs[j];
//                }
//                while(tmp%inzs[j]==0){
//                    tmp/=inzs[j];
//                }
//            }
//        }
//        if(tmp>1){
//            inka[inkan++]=tmp;
//        }
//    }
//    sort(inka,inka+inkan);
//    inkan=unique(inka,inka+inkan)-inka;
//    printf("%d\n",inkan);
//    for(int i=0;i<inkan;i++)printf("%d ",inka[i]);
//    printf("\n");
//    for(int i=1;i<=m;i++){
//        ll tmp=v[i];
//        for(int j=0;j<inkan;j++){
//            ll cnt=0;
//            while(tmp%inka[j]==0){
//                cnt++;
//                tmp/=inka[j];
//            }
//            fj3[0][j][cnt]++;
//            mx3[j]=max(mx3[j],cnt);
//        }
//    }
//    //*4
//    for(int i=3;i<4;i++){
//        for(int j=0;j<inkan;j++){
//            for(int k=0;k<=mx3[j];k++){
//                ll tmp=0;
//                for(int l=k+1;l<=mx3[j];l++){
//                    tmp+=fj3[0][j][l];
//                }
//                for(int l=1;l<i+2;l++){
//                    ll cc=zhs[i+1][l];
//                    int mm=0;
//                    for(;mm<l;mm++)cc*=fj3[0][j][k];
//                    for(;mm<i+1;mm++)cc*=tmp;
//                    fj3[i][j][k]+=cc;
////                    if(i==1&&j==0&&k==1)printf("l=%d tmp=%lld zhs[%d][%d]=%lld cc=%lld",l,tmp,i+1,l,zhs[i+1][l],cc);
//                }
//            }
//        }
//    }
//    printf("fj3\n");
//    for(int i=0;i<4;i++){
//        if(i==1)i+=2;
//        printf("i=%d\n",i);
//        for(int j=0;j<inkan;j++){
//            printf("%d(%lld):",inka[j],mx3[j]);
//            for(int k=0;k<=mx3[j];k++){
//                printf("%lld ",fj3[i][j][k]);
//            }
//            printf("\n");
//        }
//    }
//    printf("fj3\n");
//    ll ivx=inv(m*m*m*m,mod);
//    for(int i=0;i<inkan;i++){
//        ll now=1;
//        ll sum=0;
//        for(int j=0;j<=mx3[i];j++){
//            printf("i=%d j=%d\n",i,j);
//            fj3[3][i][j]=fj3[3][i][j]*ivx%mod;
//            sum+=fj3[3][i][j]*now%mod;
//            printf("%lld %lld %lld\n",fj3[3][i][j],sum,now);
//            if(sum>=mod)sum-=mod;
//            now*=inka[i];
//        }
//        x4=x4*sum%mod;
//    }
//}
int main(){
//    printf("%lld\n",inv(729,mod)*1073%mod);//475994519
//    for(ll i=2;i<100001;i++){
//        if(!inzs[i]){
//            for(ll j=i*i;j<100001;j+=i){
//                inzs[j]=1;
//            }
//        }
//    }
//    inzsn=0;
//    for(int i=2;i<100001;i++){
//        if(!inzs[i]){
//            inzs[inzsn++]=i;
//        }
//    }
    for(ll ii=1;ii<101;ii++){
        ll tmp=ii;
        for(int jj=0;jj<25;jj++){
            while(tmp%zs[jj]==0){
                fj[ii][jj]++;
                tmp/=zs[jj];
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
//        isx4=false;
        int n;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&v[i]);
        }
        //fj2
//        memset(fj2,0,sizeof(fj2));
//        for(ll ii=1;ii<=m;ii++){
//            ll tmp=v[ii];
//            for(int jj=0;jj<25;jj++){
//                while(tmp%zs[jj]==0){
//                    fj[ii][jj]++;
//                    tmp/=zs[jj];
//                }
//                fj2[ii][jj]=min(fj2[ii][jj],mx[jj]-1);
//            }
//        }
        //tj
        memset(tj,0,sizeof(tj));
        for(int i=1;i<=m;i++){
            for(int j=0;j<25;j++){
                tj[0][j][fj[i][j]]++;
            }
        }
        for(int i=1;i<4;i++){
            for(int j=0;j<25;j++){
                for(int k=0;k<mx[j];k++){
                    ll tmp=0;
                    for(int l=k+1;l<mx[j];l++){
                        tmp+=tj[0][j][l];
                    }
//                    tj[i][j][k]=tj[0][j][k]*(i+1);
//                    for(int l=0;l<i;l++){
//                        tj[i][j][k]*=tmp;
//                    }
                    for(int l=1;l<i+2;l++){
                        ll cc=zhs[i+1][l];
                        int mm=0;
                        for(;mm<l;mm++)cc*=tj[0][j][k];
                        for(;mm<i+1;mm++)cc*=tmp;
                        tj[i][j][k]+=cc;
//                        if(i==1&&j==0&&k==1)printf("l=%d tmp=%lld zhs[%d][%d]=%lld cc=%lld",l,tmp,i+1,l,zhs[i+1][l],cc);
                    }
                }
            }
        }
        ll iv[4]={inv(m,mod),inv(m*m,mod),inv(m*m*m,mod),inv(m*m*m*m,mod)};
//        printf("tj::start\n");
//        for(int i=0;i<4;i++){
//            printf("i=%d\n",i);
//            for(int j=0;j<25;j++){
//                printf("%lld:",zs[j]);
//                for(int k=0;k<mx[j];k++){
//                    printf("%lld ",tj[i][j][k]);
//                }
//                printf("\n");
//            }
//        }
//        printf("tj::end\n");
        for(int i=0;i<4;i++){
            for(int j=0;j<25;j++){
                for(int k=0;k<mx[j];k++){
                    tj[i][j][k]=tj[i][j][k]*iv[i]%mod;
                }
            }
        }
//        printf("tj::start\n");
//        for(int i=0;i<4;i++){
//            printf("i=%d\n",i);
//            for(int j=0;j<25;j++){
//                printf("%lld:",zs[j]);
//                for(int k=0;k<mx[j];k++){
//                    printf("%lld ",tj[i][j][k]);
//                }
//                printf("\n");
//            }
//        }
//        printf("tj::end\n");
        ll ans=1;
        for(int i=3;i<n;i++){
//            printf("i=%d\n",i);
            int cnt=0;
            ll se;
            bool sc=false;
            if(a[i-3]==0)cnt++;else se=sc?__gcd(a[i-3],se):(sc=true,a[i-3]);
            if(a[i-2]==0)cnt++;else se=sc?__gcd(a[i-2],se):(sc=true,a[i-2]);
            if(a[i-1]==0)cnt++;else se=sc?__gcd(a[i-1],se):(sc=true,a[i-1]);
            if(a[i]==0)cnt++;else se=sc?__gcd(a[i],se):(sc=true,a[i]);
//            printf("cnt=%d se=%lld\n",cnt,se);
            if(cnt==0){
//                printf("ans*%lld\n",se);
                ans=ans*v[se]%mod;
            }else/* if(cnt<4)*/{
                //se fen jie yin shu
                int ys[110],ysn=0;
                if(cnt==4){
                    ysn=m;
                    for(int j=0;j<m;j++)ys[j]=j+1;
                }else{
                    for(int j=1;j<=se;j++){
                        if(se%j==0){
                            ys[ysn++]=j;
                        }
                    }
                }
//                printf("ysn=%d\n",ysn);
//                for(int i=0;i<ysn;i++)printf("%d ",ys[i]);
//                printf("\n");
                //gen ju yu chu li suan yin shu gailv
                //suan yinshu jiaquan pingjun
                ll now=0;
                ll div=0;
                for(int j=0;j<ysn;j++){
//                    printf("j=%d ys[j]=%d\n",j,ys[j]);
                    ll mul=1;
                    for(int k=0;k<25;k++){
                        mul=mul*tj[cnt-1][k][fj[ys[j]][k]]%mod;
                    }
//                    printf("mul=%lld v[ys[j]]=%lld\n",mul,v[ys[j]]);
                    div=div+mul;
                    mul=mul*v[ys[j]]%mod;
                    if(div>=mod)div-=mod;
                    now+=mul;
                    if(now>=mod)now-=mod;
//                    printf("now=%lld\n",now);
                }
                now=now*inv(div,mod)%mod;
                //cheng
//                printf("ans*%lld\n",now);
                ans=ans*now%mod;
            }
//else{
//                if(!isx4)cal();
//                ans=ans*x4%mod;
//            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

