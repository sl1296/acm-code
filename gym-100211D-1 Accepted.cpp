
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MM 10000
#define DLEN 4
struct bigint{
    int a[600],len;
    bool flag;
    bigint(){
        memset(a,0,sizeof(a));
        len=1;
        flag=true;
    }
    bigint(int v){
        memset(a,0,sizeof(a));
        len=0;
        flag=true;
        if(v<0){
            flag=false;
            v=-v;
        }
        do{
            a[len++]=v%MM;
            v/=MM;
        }while(v);
    }
    bigint(char* s){
        memset(a,0,sizeof(a));
        int L=strlen(s);
        flag=true;
        if(s[0]=='-'){
            flag=false;
            s++;
            L--;
        }
        len=L/DLEN;
        if(L%DLEN)len++;
        int index=0;
        for(int i=L-1;i>=0;i-=DLEN)
        {
            int t=0;
            int k=i-DLEN+1;
            if(k<0)k=0;
            for(int j=k;j<=i;j++)
                t=t*10+s[j]-'0';
            a[index++]=t;
        }
    }
    void output(){
        if(!flag)printf("-");
        printf("%d",a[len-1]);
        for(int i=len-2;i>=0;i--)printf("%04d",a[i]);
        printf("\n");
    }
    bool operator == (const bigint &p) const{
        if(p.len!=len)return false;
        if(p.flag!=flag)return false;
        for(int i=0;i<len;i++)if(p.a[i]!=a[i])return false;
        return true;
    }
    friend inline bool bigintcmp(const bigint& u,const bigint& v);
    friend inline void bigintadd(const bigint& u,const bigint& v,bigint& res);
    friend inline void bigintdec(const bigint& u,const bigint& v,bigint& res);
    friend bool operator < (const bigint& u,const bigint& v);
    friend bigint operator + (const bigint& u,const bigint& v);
    friend bigint operator - (const bigint& u,const bigint& v);
    friend bigint operator * (const bigint& u,const bigint& v);
    friend bigint operator / (const bigint& u,const int& v);
    friend int operator % (const bigint& u,const int& v);
};
inline bool bigintcmp(const bigint& u,const bigint& v){
    if(u.len<v.len)return true;
    if(u.len>v.len)return false;
    for(int i=u.len-1;i>=0;i--){
        if(u.a[i]!=v.a[i])return u.a[i]<v.a[i];
    }
    return false;
}
bool operator < (const bigint& u,const bigint& v){
    if(u.flag!=v.flag)return u.flag<v.flag;
    if(u.flag)return bigintcmp(u,v);
    else return bigintcmp(v,u);
}
inline void bigintadd(const bigint& u,const bigint& v,bigint& res){
    res.len=max(u.len,v.len);
    for(int i=0;i<res.len;i++){
        res.a[i]+=u.a[i]+v.a[i];
        if(res.a[i]>=MM){
            res.a[i+1]++;
            res.a[i]-=MM;
        }
    }
    if(res.a[res.len]>0)res.len++;
}
inline void bigintdec(const bigint& u,const bigint& v,bigint& res){
    res.len=u.len;
    for(int i=0;i<res.len;i++){
        res.a[i]+=u.a[i]-v.a[i];
        if(res.a[i]<0){
            res.a[i+1]--;
            res.a[i]+=MM;
        }
    }
    while(res.len>1&&res.a[res.len-1]==0)res.len--;
}
bigint operator + (const bigint &u,const bigint& v){
    bigint res;
    memset(res.a,0,sizeof(res.a));
    if(u.flag==v.flag){
        res.flag=u.flag;
        bigintadd(u,v,res);
    }else{
        if(u.flag){
            if(bigintcmp(u,v)){
                bigintdec(v,u,res);
                res.flag=false;
            }else{
                bigintdec(u,v,res);
                res.flag=true;
            }
        }else{
            if(bigintcmp(v,u)){
                bigintdec(u,v,res);
                res.flag=false;
            }else{
                bigintdec(v,u,res);
                res.flag=true;
            }
        }
    }
    return res;
}
bigint operator - (const bigint& u,const bigint& v){
    bigint res;
    memset(res.a,0,sizeof(res.a));
    if(u.flag!=v.flag){
        res.flag=u.flag;
        bigintadd(u,v,res);
    }else{
        if(u.flag){
            if(bigintcmp(u,v)){
                bigintdec(v,u,res);
                res.flag=false;
            }else{
                bigintdec(u,v,res);
                res.flag=true;
            }
        }else{
            if(bigintcmp(v,u)){
                bigintdec(u,v,res);
                res.flag=false;
            }else{
                bigintdec(v,u,res);
                res.flag=true;
            }
        }
    }
    return res;
}
bigint operator * (const bigint& u,const bigint& v){
    bigint res;
    memset(res.a,0,sizeof(res.a));
    res.flag=!u.flag^v.flag;
    for(int i=0;i<u.len;i++){
        int up=0;
        for(int j=0;j<v.len;j++){
            int temp=u.a[i]*v.a[j]+res.a[i+j]+up;
            res.a[i+j]=temp%MM;
            up=temp/MM;
        }
        res.a[i+v.len]+=up;
    }
    res.len=u.len+v.len;
    while(res.a[res.len-1]>=MM){
        res.a[res.len]+=res.a[res.len-1]/MM;
        res.a[res.len-1]%=MM;
        res.len++;
    }
    while(res.len>1&&res.a[res.len-1]==0)res.len--;
    if(res.len==1&&res.a[0]==0)res.flag=true;
    return res;
}
bigint operator / (const bigint& u,const int& v){
    bigint ret;
    memset(ret.a,0,sizeof(ret.a));
    int down=0;
    for(int i=u.len-1;i>=0;i--){
        ret.a[i]=(u.a[i]+down*MM)/v;
        down=u.a[i]+down*MM-ret.a[i]*v;
    }
    ret.len=u.len;
    while(ret.len>1&&ret.a[ret.len-1]==0)ret.len--;
    return ret;
}
int operator % (const bigint& u,const int& v){
    int d=0;
    for(int i=u.len-1;i>=0;i--)d=(d*MM%v+u.a[i])%v;
    return d;
}





int from[220000];
int to[220000];
int nnext[220000];
int cnt,cnt2;
int pre[1100];
int n,m,k,t1,t2;
int stk[220000];
int top;
int low[1100];
int dfn[1100];
int instack[1100];
int to2[220000];
int nnext2[220000];
int pre2[1100];
int belong [1100];
int pnum[1100];
int ind[1100];
int outd[1100];
int ntime,lian;
void init() {
    cnt=ntime=lian=cnt2=0;
    top=-1;
    for(int i=0; i<1100; i++) {
        pre[i]=-1;
        low[i]=dfn[i]=0;
        instack[i]=0;
        pre2[i]=-1;
        belong[i]=0;
        pnum[i]=0;
        ind[i]=outd[i]=0;
    }
}
void add_edge(int u,int v) {
    from[cnt]=u;
    to[cnt]=v;
    nnext[cnt]=pre[u];
    pre[u]=cnt++;
}
void tarjan(int u) {
    low[u]=dfn[u]=++ntime;
    stk[++top]=u;
    instack[u]=1;
    int v;
    for(int i=pre[u]; i!=-1; i=nnext[i]) {
        v=to[i];
        if(dfn[v]==0) {
            tarjan(v);
            low[u]=min(low[u], low[v]);
        } else if(instack[v]==1)
            low[u]=min(low[u], dfn[v]);
    }
    if(low[u]==dfn[u]) {
        lian++;
        do {
            v=stk[top--];
            instack[v]=0;
            //System.out.print(v+" ");
            belong[v]=lian;
            pnum[lian]++;
        } while(u!=v);
        //System.out.println();
    }
}
bigint CC[110][110];
int main() {
     freopen("police.in","r",stdin);
     freopen("police.out","w+",stdout);

    for(int i=0; i<110; i++)CC[i][0]=1;
    for(int i=1; i<110; i++) {
        for(int j=1; j<=i; j++) {
            CC[i][j]=CC[i-1][j-1]+CC[i-1][j];
        }
    }
    while(~scanf("%d%d%d",&n,&m,&k)) {
        init();
        for(int i=0; i<m; i++) {
            scanf("%d%d",&t1,&t2);
            add_edge(t1,t2);
        }
        for(int i=1; i<=n; i++) {
            if(dfn[i]==0)
                tarjan(i);
        }
        for(int i=0; i<cnt; i++) {
            int uu=belong[from[i]];
            int vv=belong[to[i]];
            if(uu==vv) continue;
            ind[vv]++;
            outd[uu]++;
        }
        int a[1100];
        int numa=0;
        int b;
        int suma=0;
        for(int i=1; i<=lian; i++) {
            if(ind[i]==0||outd[i]==0) {
                a[numa++]=pnum[i];
                suma+=pnum[i];
            }
        }
        b=n-suma;
        bigint tmp[220],mm[220],re[220];
        for(int i=0;i<220;i++)tmp[i]=0;
        for(int i=0; i<=b; i++){
            tmp[i]=CC[b][i];
        }
        for(int i=0; i<numa; i++) {
            	for(int j=0;j<110;j++){
            		re[j]=0;
            		mm[j]=0;
            	}
            for(int j=1; j<=a[i]; j++) {
                mm[j]=CC[a[i]][j];
            }
            for(int j=0; j<110; j++) {
                for(int kk=0; kk<=j; kk++) {
                    re[j]=re[j]+tmp[kk]*mm[j-kk];
                }
            }
            for(int j=0; j<110; j++) {
                tmp[j]=re[j];
            }
        }
        tmp[k].output();
    }
    return 0;
}

