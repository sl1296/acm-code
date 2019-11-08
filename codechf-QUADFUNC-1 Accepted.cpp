
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
struct fs{
    ll fz,fm;
    fs(ll a=0,ll b=0){
        ll cc=__gcd(a,b);
        fz=a/cc;fm=b/cc;
        if(fm<0)fm=-fm,fz=-fz;
    }
    fs operator + (const fs &p) const{
        ll cm=fm/__gcd(fm,p.fm)*p.fm;
        return (fs){cm/fm*fz+cm/p.fm*p.fz,cm};
    }
    fs operator - (const fs &p) const{
        ll cm=fm/__gcd(fm,p.fm)*p.fm;
        return (fs){cm/fm*fz-cm/p.fm*p.fz,cm};
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,d,e,f,l,r;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&l,&r);
        a-=d;
        b-=e;
        c-=f;
        fs ans=fs(0,1);
        ans=ans+fs(a*r*r*r,3);
        ans=ans+fs(b*r*r,2);
        ans=ans+fs(c*r,1);
        ans=ans-fs(a*l*l*l,3);
        ans=ans-fs(b*l*l,2);
        ans=ans-fs(c*l,1);
        if(ans.fz<0)ans.fz=-ans.fz;
        printf("%lld/%lld\n",ans.fz,ans.fm);
    }
    return 0;
}

