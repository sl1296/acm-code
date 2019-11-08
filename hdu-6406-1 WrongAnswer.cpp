
#include<bits/stdc++.h>
using namespace std;
int a[100010],pos[100010],val[100010],pn;
vector<int> ve[100010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        pos[0]=0;
        val[0]=a[0];
        pn=1;
        int now=a[0];
        for(int i=1;i<n;++i){
            if(a[i]>now){
                now=a[i];
                val[pn]=a[i];
                pos[pn++]=i;
            }
        }
        pos[pn]=n;
        for(int i=0;i<pn;++i){
            int pre=i?pos[i-1]:0;
            for(int j=pos[i]+1;j<pos[i+1];++j){
                if(a[j]>pre){
                    pre=a[j];
                    ve[i].push_back(a[j]);
                }
            }
        }
        while(m--){
            int p,q;
            scanf("%d%d",&p,&q);
            --p;
            int pa=lower_bound(pos,pos+pn,p)-pos;
            if(pos[pa]!=p){
                if(pa==pn){
                    if(q>val[pn-1]){
                        printf("%d\n",pn+1);
                    }else{
                        printf("%d\n",pn);
                    }
                }else{
                    if(q>val[pa]){
                        int pb=upper_bound(val+pa,val+pn,q)-(val+pa);
                        printf("%d\n",pn-pb+1);
                    }else{
                        printf("%d\n",pn);
                    }
                }
            }else{
                if(q>val[pa]){
                    int pb=upper_bound(val+pa,val+pn,q)-(val+pa);
                    printf("%d\n",pn-pb+1);
                }else if(q==val[pa]){
                    printf("%d\n",pn);
                }else{
                    int pb=upper_bound(ve[pa].begin(),ve[pa].end(),q)-ve[pa].begin();
                    int ans=ve[pa].size()-pb+pn;
                    if(pa&&q<=val[pa-1])--ans;
                    printf("%d\n",ans);
                }
            }
        }
        for(int i=0;i<pn;++i)ve[i].clear();
    }
    return 0;
}

