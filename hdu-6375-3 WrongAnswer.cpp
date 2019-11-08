
#include<cstdio>
#include<algorithm>
using namespace std;
int ss[150010],ee[150010],len[150010];
int t[400010],nxt[400010],pre[400010],pos[400010];
int use[400010],usec;
int unuse[400010],unusec;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x)
{
    char c=nc();x=0;
    if(c==EOF)    return false;
    for(;c>'9'||c<'0';c=nc());
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    return true;
}
int main(){
    unusec=400005;
    for(int i=0;i<400005;++i)unuse[i]=i;
    int n,q;
    while(rea(n)){
        rea(q);
        for(int i=1;i<=n;++i){
            ss[i]=ee[i]=-1;
            len[i]=0;
        }
        while(q--){
            int x,a,b,c;
            rea(x);rea(a);rea(b);
            if(x==1){
                rea(c);
                if(len[a]){
                    if(b==0){
                        --unusec;
                        if(pre[ss[a]]!=-1)swap(pre[ss[a]],nxt[ss[a]]);
                        pre[ss[a]]=unuse[unusec];
                        nxt[pre[ss[a]]]=ss[a];
                        ss[a]=pre[ss[a]];
                        pre[ss[a]]=-1;
                        t[ss[a]]=c;
                        pos[ss[a]]=usec;
                        use[usec++]=ss[a];
                    }else{
                        --unusec;
                        if(nxt[ee[a]]!=-1)swap(pre[ee[a]],nxt[ee[a]]);
                        nxt[ee[a]]=unuse[unusec];
                        pre[nxt[ee[a]]]=ee[a];
                        ee[a]=nxt[ee[a]];
                        nxt[ee[a]]=-1;
                        t[ee[a]]=c;
                        pos[ee[a]]=usec;
                        use[usec++]=ee[a];
                    }
                }else{
                    --unusec;
                    ee[a]=ss[a]=unuse[unusec];
                    t[ss[a]]=c;
                    pre[ss[a]]=nxt[ss[a]]=-1;
                    pos[ss[a]]=usec;
                    use[usec++]=ss[a];
                }
                ++len[a];
            }else if(x==2){
                if(len[a]){
                    if(b==0){
                        printf("%d\n",t[ss[a]]);
                        use[pos[ss[a]]]=use[usec-1];
                        --usec;
                        unuse[unusec++]=ss[a];
                        int now=ss[a];
                        if(nxt[ss[a]]==-1)ss[a]=pre[ss[a]];
                        else ss[a]=nxt[ss[a]];
                        if(len[a]>1){
                            if(pre[ss[a]]==now)pre[ss[a]]=-1;
                            else nxt[ss[a]]=-1;
                        }else{
                            ee[a]=-1;
                        }
                    }else{
                        printf("%d\n",t[ee[a]]);
                        use[pos[ee[a]]]=use[usec-1];
                        --usec;
                        unuse[unusec++]=ee[a];
                        int now=ee[a];
                        if(pre[ee[a]]==-1)ee[a]=nxt[ee[a]];
                        else ee[a]=pre[ee[a]];
                        if(len[a]>1){
                            if(pre[ee[a]]==now)pre[ee[a]]=-1;
                            else nxt[ee[a]]=-1;
                        }else{
                            ss[a]=-1;
                        }
                    }
                    --len[a];
                }else{
                    printf("-1\n");
                }
            }else{
                rea(c);
                if(len[b]){
                    if(len[a]){
                        if(c==0){
                            if(pre[ss[b]]==-1)pre[ss[b]]=ee[a];
                            else nxt[ss[b]]=ee[a];
                            if(pre[ee[a]]==-1)pre[ee[a]]=ss[b];
                            else nxt[ee[a]]=ss[b];
                            ee[a]=ee[b];
                            len[a]+=len[b];
                        }else{
                            if(pre[ee[b]]==-1)pre[ee[b]]=ee[a];
                            else nxt[ee[b]]=ee[a];
                            if(pre[ee[a]]==-1)pre[ee[a]]=ee[b];
                            else nxt[ee[a]]=ee[b];
                            ee[a]=ss[b];
                            len[a]+=len[b];
                        }
                    }else{
                        if(c==0){
                            ss[a]=ss[b];
                            ee[a]=ee[b];
                        }else{
                            ss[a]=ee[b];
                            ee[a]=ss[b];
                        }
                        len[a]=len[b];
                    }
                    ss[b]=ee[b]=-1;
                    len[b]=0;
                }
            }
        }
        for(int i=0;i<usec;++i)unuse[unusec++]=use[i];
        usec=0;
    }
    return 0;
}

