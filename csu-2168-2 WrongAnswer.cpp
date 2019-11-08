
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a[50],b[50],k[100010],r[100010];
int x[20][100010];
bool vis[20][100010];
int use[20][100010];
int cir[10][100][100];
int xb[100],val[100];
int tmp[100010];
int main(){
    int n,m,q;
    while(~scanf("%d%d%d",&n,&m,&q)){
        memset(use,false,sizeof(use));
        for(int i=0;i<m;++i){
            scanf("%d%d",&a[i],&b[i]);
            --a[i];
            --b[i];
        }
        vector<int> ask[10];
        for(int i=0;i<q;++i){
            scanf("%d",&k[i]);
            ask[k[i]%m].push_back(i);
        }
//            printf("ask\n");
//            for(int i=0;i<m;++i){
//                for(int j=0;j<ask[i].size();++j){
//                    printf("%d ",ask[i][j]);
//                }
//                printf("\n");
//            }
        for(int i=0;i<n;++i)x[0][i]=i;
            printf("cal\n");
        for(int i=1;i<2*m;++i){
            for(int j=0;j<n;++j)x[i][j]=x[i-1][j];
            int id=(i-1)%m,ss=a[id],ee=a[id]+(b[id]-a[id])/2;
            for(int j=ss;j<=ee;++j)swap(x[i][j],x[i][b[id]-j+ss]);
                for(int j=0;j<n;++j)printf("%d ",x[i][j]);printf("\n");
        }
        for(int i=m+1;i<2*m;++i){
            int pre=i-m;
            for(int j=0;j<n;++j)tmp[x[pre][j]]=j;
            for(int j=0;j<n;++j)x[i][j]=tmp[x[i][j]];
        }
        memset(vis,false,sizeof(vis));
        memset(cir,0,sizeof(cir));
        vector<vector<int> > cir[10];
        vector<int> len[10];
//            printf("find\n");
        for(int i=m;i<2*m;++i){
//                printf("i=%d\n",i);
            int pre=i-m;
            vector<int> num[100];
            vector<vector<int> > num;
            for(int j=0;j<n;++j){
                if(!vis[i][j]){
                    int now=j,cnt=0;
                    do{
                        ++cnt;
                        vis[i][now]=true;
                        now=x[i][now];
                    }while(now!=j);
                    now=j;
                    if(!use[i][cnt]){
                        val[]
                    }
//                    if(cnt>=30)while(1);
//                        printf("j=%d cnt=%d\n",j,cnt);
                    do{
//                            printf("%d ",now);
                        num[cnt].push_back(now);
                        now=x[i][now];
                    }while(now!=j);
//                    printf("\n");
                }
            }
//                printf("end\n");
            for(int i=1;i<100;++i){
//                    printf("i=%d\n",i);
                int sz=num[i].size();
                for(int j=0;j<sz;j+=i){
                    for(int l=0;l<i;++l){
                        xb[l]=num[i][j+l];
                        val[l]=x[pre][num[i][j+l]];
                    }
//                        for(int ii=0;ii<i;++ii)printf("%d ",xb[ii]);printf("\n");
//                        for(int ii=0;ii<i;++ii)printf("%d ",val[ii]);printf("\n");
                    for(int l=0;l<i;++l){
                        int ccc=0;
                        for(int ll=0;ll<i;++ll)if(xb[ll]==val[ll])++ccc;
                        cir[pre][i][l]+=ccc;
//                            printf("pre=%d i=%d l=%d ccc=%d cir=%d\n",pre,i,l,ccc,cir[pre][i][l]);
                        int ttt=val[0];
                        for(int ll=1;ll<i;++ll)val[ll-1]=val[ll];
                        val[i-1]=ttt;
                    }
                }
            }
        }
//            printf("ask\n");
        for(int i=0;i<m;++i){
//                printf("i=%d\n",i);
            int sz=ask[i].size();
            for(int j=0;j<sz;++j){
                r[ask[i][j]]=0;
                int iid=k[ask[i][j]]/m;
//                        printf("k=%d iid=%d\n",k[ask[i][j]],iid);
                for(int l=1;l<100;++l){
                    int ix=iid%l;
                    r[ask[i][j]]+=cir[i][l][ix];
//                            printf("l=%d ix=%d cir=%d r=%d\n",l,ix,cir[i][l][ix],r[ask[i][j]]);
                }
            }
        }
//        printf("q=%d\n",q);
        for(int i=0;i<q;++i){
            printf("%d\n",r[i]);
        }
    }
    return 0;
}

