
#include<bits/stdc++.h>
using namespace std;
int a[100010],pos[100010],val[100010],pn;
vector<int> ve[100010];
int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out+.txt","w",stdout);
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
//            printf("i=%d a=%d\n",i,a[i]);
            if(a[i]>now){
                now=a[i];
                val[pn]=a[i];
                pos[pn++]=i;
//                printf("%d %d %d\n",pos[pn-1],val[pn-1],now);
            }
        }
        pos[pn]=n;
        for(int i=0;i<pn;++i){
            int pre=i?val[i-1]:0;
//            printf("i=%d pre=%d s=%d t=%d\n",i,pre,pos[i]+1,pos[i+1]);
            for(int j=pos[i]+1;j<pos[i+1];++j){
                if(a[j]>pre){
                    pre=a[j];
                    ve[i].push_back(a[j]);
//                    printf("j=%d %d\n",j,a[j]);
                }
            }
        }
        while(m--){
            int p,q;
            scanf("%d%d",&p,&q);
            --p;
            int pa=lower_bound(pos,pos+pn,p)-pos;
//            printf("pa=%d pos[pa=%d\n",pa,pos[pa]);
            if(pos[pa]!=p){
                if(pa==pn){
                    if(q>val[pn-1]){
                        printf("%d\n",pn+1);
                    }else{
                        printf("%d\n",pn);
                    }
                }else{
//                    printf("not end\n");
                    if(q>val[pa]){
                        int pb=upper_bound(val+pa,val+pn,q)-(val+pa);
                        printf("%d\n",pn-pb+1);
                    }else if(q==val[pa]){
                        printf("%d\n",pn);
                    }else if(q>val[pa-1]){
                        printf("%d\n",pn+1);
                    }else{
                        printf("%d\n",pn);
                    }
                }
            }else{
//                printf("==\n");
                if(q>val[pa]){
                    int pb=upper_bound(val+pa,val+pn,q)-(val+pa);
                    printf("%d\n",pn-pb+1);
                }else if(q==val[pa]){
                    printf("%d\n",pn);
                }else{
//                    printf("<val\n");
                    int pb=upper_bound(ve[pa].begin(),ve[pa].end(),q)-ve[pa].begin();
//                    printf("sz=%d\n",ve[pa].size());
//                    for(int i=0;i<ve[pa].size();++i)printf("%d ",ve[pa][i]);printf("\n");
//                    printf("pb=%d\n",pb);
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
/*
10
20 10000
30419 22256 18685 8666 6054 19658 25267 22060 7315 26013 31149 25632 5201 19155 20739 1148 3683 24687 17653 18834
5 31149
*/

