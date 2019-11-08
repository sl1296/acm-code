
#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],x[100010],id[100010],num[100010],len[100010],r[100010];
bool vis[100010];
int coun[100010],tim[100010];
int main(){
//    freopen("02.in","r",stdin);
//    freopen("02+.out","w",stdout);
    int n,m,q,k;
    while(~scanf("%d%d%d",&n,&m,&q)){
        for(int i=0;i<m;++i)scanf("%d%d",&a[i],&b[i]);
        vector<int> ask[12],asc[12];
        for(int i=0;i<q;++i){
            scanf("%d",&k);
            int iid=k%m;
//            if(iid==0)iid=m;
            ask[iid].push_back(i);
            asc[iid].push_back(k/m);
        }
        iota(x,x+n,0);
        for(int i=0;i<m;++i)reverse(x+a[i]-1,x+b[i]);
//        for(int i=0;i<n;++i)printf("%d ",x[i]);printf("\n");
        memset(vis,false,sizeof(vis));
        int cc=0;
        vector<int> zq[100010];
        for(int i=0;i<n;++i){
            if(!vis[i]){
                int now=i,cnt=0;
                do{
                    vis[now]=true;
                    id[now]=cc;
                    num[now]=cnt;
                    now=x[now];
                    ++cnt;
                }while(now!=i);
//                printf("cnt=%d\n",cnt);
                len[cc++]=cnt;
                now=i;
                do{
                    zq[cnt].push_back(now);
//                    printf("%d ",now);
                    now=x[now];
                }while(now!=i);
//                printf("\n");
            }
        }
//        for(int i=0;i<n;++i)printf("%d %d\n",id[i],num[i]);
//        for(int i=0;i<zq[1].size();++i)printf("%d ",zq[1][i]);printf("\n");
//        for(int i=0;i<zq[2].size();++i)printf("%d ",zq[2][i]);printf("\n");
//        for(int i=0;i<zq[3].size();++i)printf("%d ",zq[3][i]);printf("\n");
//        for(int i=0;i<zq[4].size();++i)printf("%d ",zq[4][i]);printf("\n");
//        for(int i=0;i<zq[5].size();++i)printf("%d ",zq[5][i]);printf("\n");
        iota(x,x+n,0);
        int tt=1;
        memset(tim,0,sizeof(tim));
        memset(r,0,sizeof(r));
        for(int i=0;i<m;++i){
//            printf("i=%d\n",i);
//            for(int j=0;j<n;++j)printf("%d ",x[j]);printf("\n");
            for(int j=1;j<=n;++j){
                if(zq[j].size()){
                    int sz=zq[j].size();
//                    printf("j=%d\n",j);
                    for(int l=0;l<sz;l+=j){
                        for(int ll=0;ll<j;++ll){
                            int pos=zq[j][l+ll];
//                            printf("%d %d %d\n",l,ll,pos);
                            if(id[x[pos]]==id[pos]){
                                int cs=(num[pos]-num[x[pos]]+j)%j;
//                                printf("= %d %d %d\n",num[pos],num[x[pos]],cs);
                                if(tim[cs]!=tt){
                                    tim[cs]=tt;
                                    coun[cs]=0;
                                }
                                ++coun[cs];
                            }
                        }
                    }
                    sz=ask[i].size();
                    for(int l=0;l<sz;++l){
                        int add=asc[i][l]%j;
                        if(tim[add]==tt)r[ask[i][l]]+=coun[add];
                    }
                    ++tt;
                }
            }
            reverse(x+a[i]-1,x+b[i]);
        }
        for(int i=0;i<q;++i){
            printf("%d\n",r[i]);
        }
    }
    return 0;
}
/*
5 1 2
2 4
1
2
*/

