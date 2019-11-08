
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e10;
struct node{
    ll a[5];
    node(int x=0){memset(a,0,sizeof(a));a[0]=x;}
    bool operator < (const node &p) const{
        for(int i=4;i>=0;--i)if(a[i]!=p.a[i])return a[i]<p.a[i];
        return false;
    }
    bool operator == (const node &p) const{
        return a[0]==p.a[0]&&a[1]==p.a[1]&&a[2]==p.a[2]&&a[3]==p.a[3]&&a[4]==p.a[4];
    }
    node operator * (const int &p) const{
        node ret;
        for(int i=0;i<5;++i)ret.a[i]=a[i]*p;
        for(int i=0;i<4;++i){
            if(ret.a[i]>=mod){
                ret.a[i+1]+=ret.a[i]/mod;
                ret.a[i]%=mod;
            }
        }
        return ret;
    }
    node operator - (const node &p) const{
        node ret;
        for(int i=0;i<5;++i)ret.a[i]=a[i]-p.a[i];
        for(int i=0;i<4;++i){
            if(ret.a[i]<0){
                ret.a[i]+=mod;
                ret.a[i+1]--;
            }
        }
        return ret;
    }
    void out(){
        bool hv=false;
        for(int i=4;i>=0;--i){
            if(a[i])hv=true;
            if(hv)printf("%lld",a[i]);
        }
        if(!hv)printf("0");
    }
};
inline node dis(node a,node b){
    return a<b?b-a:a-b;
}
node x[10][100010];
int main(){
    for(int i=1;i<100000;++i)x[1][i]=node(i);
    for(int i=2;i<10;++i)for(int j=1;j<100000;++j)x[i][j]=x[i-1][j]*j;
//    for(int i=1;i<100;++i){
//        for(int j=0;j<10;++j){
//            x[j][i].out();
//            printf(" ");
//        }
//        printf("\n");
//    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,z,sx,sy;
        scanf("%d%d",&n,&z);
        node ans=x[n][z];
        for(int i=1;i<z;++i){
            node res=x[n][z]-x[n][i];
            int pos=lower_bound(x[n]+1,x[n]+100000,res)-x[n];
            if(pos>0 && pos<i){
                node dd=dis(x[n][pos],res);
                if(dd<ans){
                    ans=dd;
                    sx=pos;
                    sy=i;
                }
            }
            --pos;
            if(pos>0 && pos<i){
                node dd=dis(x[n][pos],res);
                if(dd<ans){
                    ans=dd;
                    sx=pos;
                    sy=i;
                }
            }
            pos+=2;
            if(pos>0 && pos<i){
                node dd=dis(x[n][pos],res);
                if(dd<ans){
                    ans=dd;
                    sx=pos;
                    sy=i;
                }
            }
        }
        printf("%d %d ",sx,sy);
        ans.out();
        printf("\n");
    }
    return 0;
}

