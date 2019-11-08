
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int x[10];
int m[40][40];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int l;
        scanf("%d",&l);
        for(int i=0;i<l;i++){
            scanf("%d",&x[i]);
        }
        int cursor = 0;
        for (int i = 0;i<40 ; ++i) {
            for (int j = 0; j <= i; ++j) {
                m[j][i - j] = x[cursor];
                cursor = (cursor + 1) % l;
            }
        }
        int q,zq=2*l;
        scanf("%d",&q);
        while(q--){
            int x0,y0,x1,y1;
            scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
            int xs=x0/zq,xe=x1/zq,ys=y0/zq,ye=y1/zq;
            ll ans=0;
            int aax=x0%zq,aay=y0%zq;
            int bbx=x1%zq,bby=y1%zq;
//            printf("-%d %d %d %d\n",xs,xe,ys,ye);
//            printf("-%d %d %d %d\n",aax,bbx,aay,bby);
//            printf("%d %d %d %d\n",aax,min(zq,x1-x0+1),aay,min(zq,y1-y0+1));
            for(int i=aax;i<min(zq,aax+x1-x0+1);i++){
                for(int j=aay;j<min(zq,aay+y1-y0+1);j++){
//                    printf("%d %d\n",i,j);
                    ans+=m[i][j];
                }
            }
            if(ye-ys>1){
                ll tmp=0;
                for(int i=aax;i<min(zq,aax+x1-x0+1);i++){
                    for(int j=0;j<zq;j++){
                        tmp+=m[i][j];
                    }
                }
                ans+=tmp*(ye-ys-1);
            }
            if(ye>ys){
                for(int i=aax;i<min(zq,aax+x1-x0+1);i++){
                    for(int j=0;j<=bby;j++){
                        ans+=m[i][j];
                    }
                }
            }
            if(xe-xs>1){
                ll tmp=0;
                for(int i=0;i<zq;i++){
                    for(int j=aay;j<min(zq,aay+y1-y0+1);j++){
                        tmp+=m[i][j];
                    }
                }
                ans+=tmp*(xe-xs-1);
            }
            if(xe-xs>1&&ye-ys>1){
                ll tmp=0;
                for(int i=0;i<zq;i++){
                    for(int j=0;j<zq;j++){
                        tmp+=m[i][j];
                    }
                }
                ans+=tmp*(xe-xs-1)*(ye-ys-1);
            }
            if(xe-xs>1&&ye>ys){
                ll tmp=0;
                for(int i=0;i<zq;i++){
                    for(int j=0;j<=bby;j++){
                        tmp+=m[i][j];
                    }
                }
                ans+=tmp*(xe-xs-1);
            }
            if(xe>xs){
                for(int i=0;i<=bbx;i++){
                    for(int j=aay;j<min(zq,aay+y1-y0+1);j++){
                        ans+=m[i][j];
                    }
                }
            }
            if(xe>xs&ye-ys>1){
                ll tmp=0;
                for(int i=0;i<=bbx;i++){
                    for(int j=0;j<zq;j++){
                        tmp+=m[i][j];
                    }
                }
                ans+=tmp*(ye-ys-1);
            }
            if(xe>xs&&ye>ys){
                for(int i=0;i<=bbx;i++){
                    for(int j=0;j<=bby;j++){
                        ans+=m[i][j];
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

