
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define maxn 155
int v[maxn][maxn];
int seq[maxn],pre[maxn];
int n,m,p;
namespace IO {
    const int MX = 3e6; //1e7Õ¼ÓÃÄÚ´æ11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
int main(){
//    freopen("data.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    IO::begin();
    while(IO::read(n)){
        IO::read(m);
        IO::read(p);
        int maxv=-inf;
        int A=1,B=n,C=1,D=m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                IO::read(v[i][j]);
                maxv=max(maxv,v[i][j]);
            }
        }
        int maxx=-inf;
        for(int i=1;i<=n;i++){
            for(int k=0;k<=m;k++) seq[k]=0;
            for(int j=i;j<=n;j++){
                int minv=0,sum=0,c=0;
                for(int k=1;k<=m;k++){
                    seq[k]+=v[j][k];
                    sum+=seq[k];
                    if(sum<minv){
                        minv=sum;
                        c=k+1;
                    }
                    minv=min(minv,sum);
                    if(sum-minv>maxx){
                        maxx=sum-minv;
                        A=i;B=j;C=c;D=k;
                    }else if(sum-minv==maxx){
                        A=i;B=min(B,j);C=max(C,c);D=min(D,k);
                    }
                }
            }
        }
//        printf("%d\n",maxx);
        int L=maxx-maxv+p,R=maxx;
        while(L<R){
            int mid=(L+R)/2;
//            printf("------%d : \n",mid);
            int x1=A,x2=B,y1=C,y2=D;
            for(int i=1;i<=n&&x1<=x2&&y2<=y2;i++){
                for(int k=0;k<=m;k++) seq[k]=0;
                for(int j=i;j<=n&&x1<=x2&&y2<=y2;j++){
                    for(int k=1;k<=m;k++){
                        seq[k]+=v[j][k];
                        pre[k]=pre[k-1]+seq[k];
                    }
                    int minv=0,sum=0;
                    int rr=min(m,y2);
                    for(int k=1;k<=rr;k++){
                        sum+=seq[k];
                        if(sum-minv>mid){
                            y2=min(y2,k);
                            x1=i;
                            x2=min(x2,j);
                            break;
                        }
                        minv=min(minv,sum);
                    }
                    minv=pre[m];
                    int ll=max(0,y1-1);
                    for(int k=m-1;k>=ll;k--){
                        if(pre[k]+mid<minv){
//                            printf("%d %d %d : %d %d\n",i,j,k,pre[k],minv);
                            y1=max(y1,k+1);
                            x1=i;
                            x2=min(x2,j);
                            break;
                        }
                        minv=max(minv,pre[k]);
                    }
                }
            }
//            printf("***%d %d %d %d\n",x1,x2,y1,y2);
            bool flag=false;
            if(x1<=x2&&y2<=y2){
                int c=-1000;
                for(int i=x1;i<=x2;i++){
                    for(int j=y1;j<=y2;j++)
                        if(v[i][j]>c) c=v[i][j];
                }
                if(maxx-c+p<=mid) flag=true;
            }
            if(flag) R=mid;
            else L=mid+1;
        }
        printf("%d\n",L);
    }
    return 0;
}
/*
3 3 -10
-100 4 4
4 -10 4
4 4 1
*/

