
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const ll mod=998244353;
vector<vector<int> > ve(600010);
vector<vector<int> > val(600010);
bool use[600010];
ll re;
void dfs(int x,int f,ll vl,int cs,int st){
  //  printf("dfs x=%d vl=%lld\n",x,vl);
    use[x]=true;
    for(int i=0;i<2;i++){
        if(ve[x][i]==f)continue;
        if(ve[x][i]==st){
            re=re+vl;
            if(re>mod)re-=mod;
          //  printf("re=%lld\n",re);
            return;
        }
        ll ad=vl;
        if(cs&1)ad=ad*val[x][i]%mod;
        dfs(ve[x][i],x,ad,cs+1,st);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++){ve[i].clear();val[i].clear();use[i]=false;}
        for(int i=1;i<=n;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            ve[i].push_back(a+n);
            val[i].push_back(b);
            ve[i].push_back(c+n);
            val[i].push_back(d);
            ve[a+n].push_back(i);
            val[a+n].push_back(b);
            ve[c+n].push_back(i);
            val[c+n].push_back(d);
        }
        queue<int> dec;
        bool is=true;
        for(int i=n+1;i<=2*n;i++){
            if(ve[i].size()==0){
                is=false;
                break;
            }else if(ve[i].size()==1){
                dec.push(i);
            }
        }
        if(!is){
            printf("0\n");
            continue;
        }
        ll ans=1;
        while(!dec.empty()){
            int tmp=dec.front();
            dec.pop();
          //  printf("tmp=%d\n",tmp);
            int del=ve[tmp][0];
            ans=ans*val[tmp][0]%mod;
          //  printf("del=%d ans=%lld delsize=%d\n",del,ans,ve[del].size());
            use[tmp]=use[del]=true;
            for(int i=0;i<ve[del].size();i++){
                int ne=ve[del][i];
                if(ne==tmp)continue;
            //    printf(" i=%d ne=%d nesize=%d\n",i,ne,ve[ne].size());
                for(int j=0;j<ve[ne].size();j++){
             //       printf("  j=%d\n",j);
                    if(ve[ne][j]==del){
            //            printf("erase\n");
                        ve[ne].erase(ve[ne].begin()+j);
                        val[ne].erase(val[ne].begin()+j);
                        if(ve[ne].size()==0){
                            is=false;
                        }else if(ve[ne].size()==1){
                            dec.push(ne);
                        }
                        break;
                    }
                }
                if(!is)break;
            }
            if(!is)break;
        }
        if(!is){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            if(!use[i]){
                re=0;
                dfs(i,-1,1,1,i);
                ans=ans*re%mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

