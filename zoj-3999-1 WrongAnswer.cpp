
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll x;
char sa[10010],sb[10010];
struct node{
    ll a[10];
    node(){}
    node(char* s){
        int num,pw;
        memset(a,0,sizeof(a));
        for(int i=0;s[i];){
//            printf("i=%d %s\n",i,&s[i]);
            //-3
            //-x
            //-3x
            //-x^3
            //-3x^3
            if(s[i+1]!='x'){
                num=s[i+1]-48;
                if(s[i]=='-')num*=-1;
                ++i;
            }else{
                num=1;
                if(s[i]=='-')num*=-1;
            }
            ++i;
            if(s[i]=='x'){
                ++i;
                if(s[i]=='^'){
                    pw=s[i+1]-48;
                    i+=2;
                }else{
                    pw=1;
                }
            }else{
                pw=0;
            }
            a[pw]+=num;
//            printf("%d %d\n",pw,num);
        }
    }
//    void out(){
//        for(int i=0;i<10;++i){
//            printf("%d ",a[i]);
//        }
//        printf("\n");
//    }
    ll cal(){
        ll ans=a[0],xx=x;
        for(int i=1;i<10;++i){
            ans+=xx*a[i];
            xx*=x;
        }
        return ans;
    }
    bool ch(){
        for(int i=0;i<10;++i)if(a[i])return false;
        return true;
    }
    node d(){
        node ret;
        memset(ret.a,0,sizeof(ret.a));
        for(int i=1;i<10;++i){
            ret.a[i-1]=a[i]*i;
        }
        return ret;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        sa[0]=sb[0]='+';
        scanf("%s%s%lld",&sa[1],&sb[1],&x);
        node fz,fm;
        if(sa[1]=='+' || sa[1]=='-')fz=node(&sa[1]);else fz=node(sa);
        if(sb[1]=='+' || sb[1]=='-')fm=node(&sb[1]);else fm=node(sb);
//        fz.out();
//        fm.out();
        ll cfz,cfm;
        bool inf=false;
        while(1){
            cfz=fz.cal();
            cfm=fm.cal();
//            printf("m=%lld z=%lld\n",cfm,cfz);
            if(cfm!=0)break;
            if(fm.ch()){
                inf=true;
                break;
            }
            fz=fz.d();
            fm=fm.d();
//            fz.out();
//            fm.out();
        }
        if(inf){
            printf("INF\n");
        }else{
            if(cfz==0){
                printf("0\n");
            }else{
                int op=1;
                if(cfz<0){
                    op*=-1;
                    cfz=-cfz;
                }
                if(cfm<0){
                    op*=-1;
                    cfm=-cfm;
                }
                if(op==-1)printf("-");
                ll gcd=__gcd(cfz,cfm);
                cfz/=gcd;
                cfm/=gcd;
//                printf("%lld\n",gcd);
                if(cfm==1)printf("%lld\n",cfz);
                else printf("%lld/%lld\n",cfz,cfm);
            }
        }
    }
    return 0;
}
/*
2
x^2-2x+1
x^2-1
1
9x^8
-9x^9
9

9
8x^2+6x+2x^3
4x+3+x^2
9
*/

