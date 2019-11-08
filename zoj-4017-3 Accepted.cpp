
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,ca=-1,cb=-1;
        scanf("%d%d",&n,&m);
        vector<vector<char> > a(n,vector<char>(m+1));
        for(int i=0;i<n;++i){
            scanf("%s",a[i].data());
            for(int j=0;j<m;++j){
                a[i][j]-=48;
                if(i==0 && a[i][j]>1){
                    if(ca==-1)ca=j;
                    else cb=j;
                }
            }
        }
//        printf("ca=%d cb=%d\n",ca,cb);
        vector<char> rr(n+1),xx(n+1);
        scanf("%s%s",rr.data(),xx.data());
        for(int i=0;i<n;++i)rr[i]-=48,xx[i]-=48;
        vector<bool> vis(n,false);
        vector<char> val1(n),val2(n);
        for(int i=0;i<n;++i){
//            printf("i=%d\n",i);
            val1[i]=rr[i];
            for(int j=0;j<m;++j){
                if(j!=ca && j!=cb){
                    val1[i]^=a[i][j];
                }
            }
            int id=(ca+i)%n;
//            printf("id=%d\n",id);
            val2[i]=xx[id];
            for(int j=0;j<m;++j){
                if(j!=ca && j!=cb){
                    val2[i]^=a[((id-j)%n+n)%n][j];
//                    printf("%d %d\n",(id+n+n-j)%n,j);
                }
            }
//            printf("v:%d %d\n",val1[i],val2[i]);
        }
        int dec=cb-ca;
        bool ch=true;
        int ans1=0,ans2=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                int ca=1,cb=0,now=i,pos=0;
                if(val1[now]){
                    if(pos==0)++cb,pos=1;else ++ca,pos=0;
                }else{
                    if(pos==0)++ca;else ++cb;
                }
                vis[now]=true;
                int nxt=((now-dec)%n+n)%n;
//                printf("ca%d cb%d\n",ca,cb);
                while(!vis[nxt]){
//                    printf("now=%d\n",now);
//                    printf("val:%d\n",val2[now]);
                    if(val2[now]){
                        if(pos==0)++cb,pos=1;else ++ca,pos=0;
                    }else{
                        if(pos==0)++ca;else ++cb;
                    }
//                printf("ca%d cb%d\n",ca,cb);
                    now=((now-dec)%n+n)%n;
                    vis[now]=true;
//                    printf("val:%d\n",val1[now]);
                    if(val1[now]){
                        if(pos==0)++cb,pos=1;else ++ca,pos=0;
                    }else{
                        if(pos==0)++ca;else ++cb;
                    }

//                printf("ca%d cb%d\n",ca,cb);
                    nxt=((now-dec)%n+n)%n;
                }
//                printf("%d %d\n",ca,cb);
                if(pos==0 && val2[now]==1 || pos==1 && val2[now]==0){
                    ch=false;
                    break;
                }
                ans1+=min(ca,cb);
                ans2+=max(ca,cb);
            }
        }
        if(ch==false){
            printf("No Solution\n");
        }else{
            printf("%d %d\n",ans1,ans2);
        }
    }
    return 0;
}

