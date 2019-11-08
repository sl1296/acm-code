
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll cal[10];
int le[10];
ll pw[50];
ll a[2500010];
inline int len(ll x){
    int cnt=0;
    while(x){
        x/=10;
        cnt++;
    }
    return cnt;
}
inline ll gt(int k){
    ll ret=0;
    int x=0;
    for(int i=k-1;i>=0;--i){
        ret+=cal[i]*pw[x];
        x+=le[i];
    }
    return ret;
}
int zs[1010],zsn;
int fj[50],fjc[50],fjn;
int fm[1000],fmn;
void dfs(int cs,int now){
    if(cs==fjn){
        fm[fmn++]=now;
        return;
    }
    for(int i=0;i<=fjc[cs];++i){
        dfs(cs+1,now);
        now*=fj[cs];
    }
}
int main(){
    pw[0]=1;
    for(int i=1;i<17;++i)pw[i]=pw[i-1]*10;
    ll all=0;
    for(int i=2;i<1010;++i){
        if(!zs[i]){
            for(int j=i*i;j<1010;j+=i){
                zs[j]=1;
            }
        }
    }
    for(int i=2;i<1010;++i){
        if(!zs[i]){
            zs[zsn++]=i;
        }
    }
    for(int i=1;i<100000;++i){
//        printf("i=%d\n",i);
        int tmp=i;
        fjn=fmn=0;
        for(int j=0;zs[j]*zs[j]<=tmp;++j){
//            printf("j=%d tmp=%d zs=%d\n",j,tmp,zs[j]);
            if(tmp%zs[j]==0){
                fjc[fjn]=0;
                do{
                    tmp/=zs[j];
                    ++fjc[fjn];
                }while(tmp%zs[j]==0);
                if(fjc[fjn]>1){
                    fjc[fjn]>>=1;
                    fj[fjn++]=zs[j];
                }
            }
        }
        dfs(0,1);
        for(int tt=0;tt<fmn;++tt){
//            printf("i=%d tt=%d\n",i,fm[tt]);
            for(int j=2;;++j){
                tmp=i;
                cal[0]=tmp;
                tmp/=fm[tt];
                cal[1]=tmp*j;
                tmp/=fm[tt];
                cal[2]=tmp*j*j;
                le[0]=len(cal[0]);le[1]=len(cal[1]);le[2]=len(cal[2]);
                int x=le[0]+le[1]+le[2];
                if(x>15)break;
                for(int k=3;;++k){
                    a[all++]=gt(k);
                    if(cal[k-1]%fm[tt])break;
                    cal[k]=cal[k-1]/fm[tt]*j;
                    le[k]=len(cal[k]);
                    x+=le[k];
                    if(x>15)break;
                }
            }
        }
    }
//    printf("all=%d\n",all);
    sort(a,a+all);
    all=unique(a,a+all)-a;
//    printf("all=%d\n",all);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        ll xx,yy;
        scanf("%lld%lld",&xx,&yy);
        int p1=upper_bound(a,a+all,yy)-a;
        int p2=upper_bound(a,a+all,xx-1)-a;
//        printf("%d %d\n",p2,p1);
        printf("Case #%d: %d\n",z,p1-p2);
    }
    return 0;
}

