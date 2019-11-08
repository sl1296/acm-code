
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<vector>
using namespace std;
#define ll long long
vector<ll> ve;
map<string,int> ma;
const ll mod=1LL<<47;
int cnt=1;
ll multi(ll a,ll b){
    ll ans=0;
    while(b){
        if(b&1)ans=(ans+a)%mod;
        b>>=1;
        a=(a+a)%mod;
    }
    return ans;
}
int main(){
    char op[50],va[50],vb[50];
    ll v;
    ve.push_back(0);
    while(~scanf("%s",op)){
        if(strcmp(op,"def")==0){
            scanf("%s%I64d",va,&v);
            v=(v%mod+mod)%mod;
            int now=ma[va];
            if(!now){
                ma[va]=cnt;
                ve.push_back(v);
                ++cnt;
            }else{
                ve[now]=v;
            }
            printf("%s = %I64d\n",va,v);
        }else if(strcmp(op,"add")==0){
            scanf("%s%s",va,vb);
            int ka=ma[va];
            int kb=ma[vb];
            ll tmp;
            if(kb){
                tmp=ve[kb];
            }else{
                sscanf(vb,"%lld",&tmp);
                tmp=(tmp%mod+mod)%mod;
            }
            ve[ka]=(ve[ka]+tmp)%mod;
            printf("%s = %I64d\n",va,ve[ka]);
        }else if(strcmp(op,"sub")==0){
            scanf("%s%s",va,vb);
            int ka=ma[va];
            int kb=ma[vb];
            ll tmp;
            if(kb){
                tmp=ve[kb];
            }else{
                sscanf(vb,"%lld",&tmp);
                tmp=(tmp%mod+mod)%mod;
            }
            ve[ka]=((ve[ka]-tmp)%mod+mod)%mod;
            printf("%s = %I64d\n",va,ve[ka]);
        }else if(strcmp(op,"mul")==0){
            scanf("%s%s",va,vb);
            int ka=ma[va];
            int kb=ma[vb];
            ll tmp;
            if(kb){
                tmp=ve[kb];
            }else{
                sscanf(vb,"%lld",&tmp);
                tmp=(tmp%mod+mod)%mod;
            }
            ve[ka]=multi(ve[ka],tmp)%mod;
            printf("%s = %I64d\n",va,ve[ka]);
        }else if(strcmp(op,"div")==0){
            scanf("%s%s",va,vb);
            int ka=ma[va];
            int kb=ma[vb];
            ll tmp;
            if(kb){
                tmp=ve[kb];
            }else{
                sscanf(vb,"%lld",&tmp);
                tmp=(tmp%mod+mod)%mod;
            }
            ve[ka]=ve[ka]/tmp;
            printf("%s = %I64d\n",va,ve[ka]);
        }else{
            scanf("%s%s",va,vb);
            int ka=ma[va];
            int kb=ma[vb];
            ll tmp;
            if(kb){
                tmp=ve[kb];
            }else{
                sscanf(vb,"%lld",&tmp);
                tmp=(tmp%mod+mod)%mod;
            }
            ve[ka]=ve[ka]%tmp;
            printf("%s = %I64d\n",va,ve[ka]);
        }
    }
    return 0;
}

