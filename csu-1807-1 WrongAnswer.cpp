
#include<cstdio>
#define ll long long
int a[100010],p0[100010],cp0,p1[100010],cp1,px1[100010],cpx1;
int pt,ptc;
int r[100010];
ll dp[100010];
int main(){
    for(int i=2;i<100005;++i){
        dp[i]=dp[i-1]+i-1+i-2;
    }
    int n;
    while(~scanf("%d",&n)){
        cp0=cp1=cpx1=ptc=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            if(a[i]==0){

            }else if(a[i]==i+1){
                p0[cp0++]=i;
            }else if(a[i]==i+2){
                p1[cp1++]=i;
            }else if(a[i]==i){
                px1[cpx1++]=i;
            }else{
                pt=i;
                ptc++;
            }
        }
//        printf("%d %d %d %d\n",ptc,cp0,cp1,cpx1);
        if(ptc>1){
            printf("0\n");
        }else if(ptc==1){
            for(int i=0;i<n;++i)r[i]=i+1;
            r[pt]=a[pt];
            int ad=a[pt]>pt?-1:1;
            for(int i=a[pt];i>pt;i+=ad){
                r[i]+=ad;
            }
            bool pd=true;
            for(int i=0;i<n;++i){
                if(a[i]!=r[i] && a[i]!=0){
                    pd=false;
                    break;
                }
            }
            if(pd){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }else{
//            printf("ee\n");
            if(cp1>0 && cpx1>0){
                if(cp1==1 && cpx1==1 && p1[0]+1==px1[0]){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
            }else{
                if(cp1>0){
//                    printf("cp1--\n");
                    bool pd=true;
                    for(int i=0;i<cp0;++i){
                        if(p0[i]>=p1[0] && p0[i]<=p1[cp1-1]+1){
                            pd=false;
                            break;
                        }
                    }
                    if(pd){
                        int ss=p1[0]-1,ee=p1[cp1-1]+2;
                        while(ss>=0 && a[ss]==0)ss--;
                        while(ee<n && a[ee]==0)ee++;
                        ll ans=(p1[0]-ss)*(ll)(ee-p1[cp1-1]-1);
                        printf("%lld\n",ans);
                    }else{
                        printf("0\n");
                    }
                }else if(cpx1>0){
                    bool pd=true;
                    for(int i=0;i<cp0;++i){
                        if(p0[i]>=px1[0]-1 && p0[i]<=px1[cpx1-1]){
                            pd=false;
                            break;
                        }
                    }
                    if(pd){
                        int ss=px1[0]-2,ee=px1[cpx1-1]+1;
                        while(ss>=0 && a[ss]==0)ss--;
                        while(ee<n && a[ee]==0)ee++;
                        ll ans=(px1[0]-ss-1)*(ll)(ee-px1[cpx1-1]);
                        printf("%lld\n",ans);
                    }else{
                        printf("0\n");
                    }
                }else{
                    int pre=0;
                    ll ans=0;
                    for(int i=0;i<cp0;++i){
                        ans+=dp[p0[i]-pre];
                        pre=p0[i]+1;
                    }
                    ans+=dp[n-pre];
                    printf("%lld\n",ans);
                }
            }
        }
    }
    return 0;
}

