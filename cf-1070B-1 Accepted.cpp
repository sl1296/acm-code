
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define maxn 200010
char s[maxn][30];
int ss[50],ts;
int ch[maxn*32][2],tot;
bool val[maxn*32];
void dd(char *s){
    int p=1;
    for(int j=0;j<4;++j){
        int now=0;
        while(s[p]!='.' && s[p]!=0 && s[p]!='/') now=now*10+s[p]-48,++p;
        for(int k=j*8+7;k>=j*8;--k){
            ss[k]=now&1;
            now>>=1;
        }
        ++p;
    }
    if(s[p-1]=='/'){
        ts=0;
        while(s[p]!=0){
            ts=ts*10+s[p]-48;
            ++p;
        }
    }else{
        ts=32;
    }
}
void insert(){
    int u=0;
    for(int i=0;i<ts;i++){
        int v=ss[i];
        if(!ch[u][v]) ch[u][v]=++tot;
        u=ch[u][v];
    }
    val[u]=true;
}
set<pp> st;
int ty;
bool query(){
    int u=0;
    if(val[u]) return false;
    ll ans=0;
    for(int i=0;i<ts;i++){
        int v=ss[i];
        u=ch[u][v];
        if(v) ans|=(1LL<<i);
        if(!u){
            st.insert(make_pair(ans,i+1));
            return true;
        }else if(val[u]){
            return false;
        }
    }
    if(ty) return false;
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%s",s[i]);
    for(int i=0;i<n;++i){
        if(s[i][0]=='+'){
            dd(s[i]);
            ty=1;
            insert();
        }
    }
    bool flag=true;
    for(int i=0;i<n&&flag;i++){
        if(s[i][0]=='-'){
            dd(s[i]);
            flag&=query();
        }
    }
    if(!flag) printf("-1\n");
    else if(!ty){
        printf("1\n");
        printf("0.0.0.0/0\n");
    }else{
        printf("%d\n",st.size());
        for(auto e : st){
            for(int i=0;i<4;i++){
                int ans=0;
                for(int j=0;j<8;j++)
                    ans=ans*2+(e.first>>(i*8+j)&1);
                printf("%d%c",ans,i==3?'/':'.');
            }
            printf("%d\n",e.second);
        }
    }
    return 0;
}

