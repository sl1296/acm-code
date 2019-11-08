
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int a[100010],b[100010],e[100010];
int fa[100010];
bool is[100010];
int change[100010],cgc;
int ans[100010];
struct node{
    int a,b;
    bool operator < (const node &p) const{
        if(a!=p.a)return a<p.a;
        return b<p.b;
    }
};
map<node,int> ma;
vector<vector<int> > ve(100010);
int ffind(int x){
  //  printf(" %d %d\n",x,fa[x]);
    if(fa[x]==x){
        return x;
    }
    fa[x]=ffind(fa[x]);
    return fa[x];
}
int main(){
    int l;
    while(~scanf("%d",&l)){
        for(int i=0;i<l;i++){
            scanf("%d%d%d",&a[i],&b[i],&e[i]);
        }
        int acc=0;
        int p=0;
        for(int i=1;i<100005;i++)fa[i]=i,ve[i].clear();
        cgc=0;
        while(p<l){
            memset(is,false,sizeof(is));
            ma.clear();
            int from=p;
            for(int i=0;i<cgc;i++){
                is[change[i]]=false;
                fa[change[i]]=change[i];
                ve[change[i]].clear();
            }
            //printf("acc=%d\n",acc);
            for(;p<l;p++){
               // printf("p=%d\n",p);
                if(a[p]==b[p]){
                    if(e[p]==1)continue;
                    else{
                        p++;
                        break;
                    }
                }
                if(e[p]==1){
                    if(is[a[p]]&&is[b[p]]){
                        int f1=ffind(a[p]);
                        int f2=ffind(b[p]);
                      //  printf("%d %d\n",f1,f2);
                        if(ma[(node){f1,f2}]){
                            p++;
                            break;
                        }else{
                            int sz1=ve[f1].size();
                            int sz2=ve[f2].size();
                            if(sz1<sz2){
                                fa[f1]=f2;
                                for(int j=0;j<sz1;j++){
                                    int now=ve[f1][j];
                                    if(ma[(node){f2,now}]==0){
                                        ma[(node){f2,now}]=1;
                                        ma[(node){now,f2}]=1;
                                        ve[f2].push_back(now);
                                        ve[now].push_back(f2);
                                    }
                                }
                            }else{
                                fa[f2]=f1;
                                for(int j=0;j<sz2;j++){
                                    int now=ve[f2][j];
                                    if(ma[(node){f1,now}]==0){
                                        ma[(node){f1,now}]=1;
                                        ma[(node){now,f1}]=1;
                                        ve[f1].push_back(now);
                                        ve[now].push_back(f1);
                                    }
                                }
                            }
                        }
                    }else if(is[a[p]]&&is[b[p]]==false){
                        fa[b[p]]=ffind(a[p]);
                        is[b[p]]=true;
                        change[cgc++]=b[p];
                    }else if(is[b[p]]&&is[a[p]]==false){
                        fa[a[p]]=ffind(b[p]);
                        is[a[p]]=true;
                        change[cgc++]=a[p];
                    }else{
                        fa[b[p]]=ffind(a[p]);
                        is[a[p]]=is[b[p]]=true;
                        change[cgc++]=a[p];
                        change[cgc++]=b[p];
                    }
                }else{
                    if(is[a[p]]&&is[b[p]]){
                        int f1=ffind(a[p]);
                        int f2=ffind(b[p]);
                        if(f1==f2){
                            p++;
                            break;
                        }else{
                            if(ma[(node){f1,f2}]==0){
                                ma[(node){f1,f2}]=1;
                                ma[(node){f2,f1}]=1;
                                ve[f1].push_back(f2);
                                ve[f2].push_back(f1);
                            }
                        }
                    }else if(is[a[p]]&&is[b[p]]==false){
                        int f1=ffind(a[p]);
                        is[b[p]]=true;
                        change[cgc++]=b[p];
                        ma[(node){f1,b[p]}]=1;
                        ma[(node){b[p],f1}]=1;
                        ve[f1].push_back(b[p]);
                        ve[b[p]].push_back(f1);
                    }else if(is[b[p]]&&is[a[p]]==false){
                        int f2=ffind(b[p]);
                        is[a[p]]=true;
                        change[cgc++]=a[p];
                        ma[(node){a[p],f2}]=1;
                        ma[(node){f2,a[p]}]=1;
                        ve[a[p]].push_back(f2);
                        ve[f2].push_back(a[p]);
                    }else{
                        is[a[p]]=is[b[p]]=true;
                        change[cgc++]=a[p];
                        change[cgc++]=b[p];
                        ma[(node){a[p],b[p]}]=1;
                        ma[(node){b[p],a[p]}]=1;
                        ve[a[p]].push_back(b[p]);
                        ve[b[p]].push_back(a[p]);
                    }
                }
            }
            ans[acc++]=p-from;
        }
        printf("%d\n",acc);
        for(int i=0;i<acc;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

