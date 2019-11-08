
#include<cstdio>
#include<cstring>
#define ll long long
char s[10010];
bool hv[300][2];
int main(){
    freopen("boolean.in","r",stdin);
    freopen("boolean.out","w+",stdout);
    while(~scanf("%s",s)){
        int len=strlen(s);
        memset(hv,false,sizeof(hv));
        for(int i=0;i<len;++i){
            bool op=(s[i]=='~');
            while(s[i]!='|' && s[i]!=0)++i;
            hv[s[i-1]][op?1:0]=true;
        }
        int cnt=0;
        bool all=false;
        for(int i='A';i<='Z';++i){
            if(hv[i][0] && hv[i][1])all=true;
            if(hv[i][0] || hv[i][1])++cnt;
        }
        for(int i='a';i<='z';++i){
            if(hv[i][0] && hv[i][1])all=true;
            if(hv[i][0] || hv[i][1])++cnt;
        }
        ll ans=(1LL<<cnt);
        if(!all)--ans;
        printf("%lld\n",ans);
    }
    return 0;
}

