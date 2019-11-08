
#include<cstdio>
int ss[300010],tt[300010];
int val[400010],pre[400010],nxt[400010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q,use=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;++i)ss[i]=tt[i]=-1;
        while(q--){
            int op;
            scanf("%d",&op);
            if(op==1){
                int x,y;
                scanf("%d%d",&x,&y);
                if(ss[x]==-1){
                    val[use]=y;
                    pre[use]=-1;
                    nxt[use]=-1;
                    ss[x]=use;
                    tt[x]=use;
                    ++use;
                }else{
                    nxt[tt[x]]=use;
                    val[use]=y;
                    pre[use]=tt[x];
                    nxt[use]=-1;
                    tt[x]=use;
                    ++use;
                }
            }else if(op==2){
                int x;
                scanf("%d",&x);
                if(ss[x]==-1){
                    printf("EMPTY\n");
                }else{
                    printf("%d\n",val[tt[x]]);
                    if(ss[x]==tt[x]){
                        ss[x]=tt[x]=-1;
                    }else{
                        tt[x]=pre[tt[x]];
                        nxt[tt[x]]=-1;
                    }
                }
            }else{
                int x,y;
                scanf("%d%d",&x,&y);
                if(ss[y]!=-1){
                    if(ss[x]==-1){
                        ss[x]=ss[y];
                        tt[x]=tt[y];
                        ss[y]=tt[y]=-1;
                    }else{
                        nxt[tt[x]]=ss[y];
                        pre[ss[y]]=tt[x];
                        tt[x]=tt[y];
                        ss[y]=tt[y]=-1;
                    }
                }
            }
        }
    }
    return 0;
}

