
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct node{
    int id;
    double c,v,t,hc,ht;
    bool operator < (const node &p) const{
        if(t!=p.t)return t<p.t;
        return id<p.id;
    }
    void out(){
        printf("id=%d c=%f v=%f t=%f hc=%f ht=%f\n",id,c,v,t,hc,ht);
    }
};
double a[100010];
node x[100010];
int nxt[100010];
int pre[100010];
int main(){
    int n;
    double f;
    while(~scanf("%d%lf",&n,&f)){
        set<node> se;
        for(int i=0;i<n;++i){
            scanf("%lf",&a[i]);
            pre[i]=i-1;
            nxt[i]=i+1;
            x[i]=(node){i,a[i],f,a[i]/f,0.0,0.0};
            se.insert(x[i]);
        }
        nxt[n-1]=-2;
        double ans1,ans2;
        for(int i=0;i<n;++i){
//            printf("i=%d\n",i);
            node now=(*se.begin());
            se.erase(se.begin());
//                now.out();
            if(i==n-1){
                ans2=now.t;
//                printf("ans2 %f\n",ans2);
            }
            if(now.id==n-1){
                ans1=now.t;
//                printf("ans1 %f\n",ans1);
                if(pre[n-1]!=-1)nxt[pre[n-1]]=-2;
            }else{
                int ch=nxt[now.id];
//                printf("ch=%d\n",ch);
                if(ch!=-2){
//                        x[ch].out();
                    se.erase(x[ch]);
                    x[ch].hc+=(now.t-x[ch].ht)*x[ch].v;
                    x[ch].v+=now.v;
                    x[ch].ht=now.t;
                    x[ch].t=x[ch].ht+(x[ch].c-x[ch].hc)/x[ch].v;
                    se.insert(x[ch]);
//                        x[ch].out();
                    pre[ch]=pre[now.id];
                    if(pre[ch]!=-1)nxt[pre[ch]]=ch;
                }else{
                    if(pre[now.id]!=-1)nxt[pre[now.id]]=-2;
                }
            }
//            for(int i=0;i<n;++i)printf("%d ",pre[i]);printf("\n");
//            for(int i=0;i<n;++i)printf("%d ",nxt[i]);printf("\n");
        }
        printf("%.8f %.8f\n",ans1,ans2);
    }
    return 0;
}
/*
4 2
1 2 3 4
*/

