
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll inf=1e18;
char s[100],c[100],*pp[100];
bool use[300];
char x[100],xt[100]="()*+-01=",pre[100],cx;
//bool oo;
ll cal(char *ss,int len,char* pp[]){
//    if(oo){
//        printf("cal:");
//        for(int i=0;i<len;++i)printf("%c",ss[i]);
//        printf("\n");
//    }
//    if(oo)printf("%d %d %d %d\n",pp[0],pp[1],pp[2],ss);
    while(len>1 && ss[0]=='(' && ss[len-1]==')' && pp[len-1]==ss)++ss,len-=2;
    if(len==0)return inf;
//    if(oo){
//        printf("cal2:");
//        for(int i=0;i<len;++i)printf("%c",ss[i]);
//        printf("\n");
//    }
    bool fin=false;
    ll ret=0;
    int now=0,pos=0,op=1;
    for(int i=0;i<len;++i){
        if(ss[i]=='(')++now;
        else if(ss[i]==')')--now;
        if(now==0 && (ss[i]=='+' || (ss[i]=='-' && i>0 && ss[i-1]!='+' && ss[i-1]!='-' && ss[i-1]!='*'))){
            ll add=cal(&ss[pos],i-pos,&pp[pos]);
            if(add==inf)return inf;
            if(op)ret+=add;else ret-=add;
            if(ss[i]=='+')op=1;else op=0;
            pos=i+1;
            fin=true;
        }
    }
    if(fin){
        ll add=cal(&ss[pos],len-pos,&pp[pos]);
        if(add==inf)return inf;
        if(op)ret+=add;else ret-=add;
        return ret;
    }
//    if(oo)printf("id* %s\n",ss);
    now=0;pos=0;ret=1;
    for(int i=0;i<len;++i){
        if(ss[i]=='(')++now;
        else if(ss[i]==')')--now;
        if(now==0 && ss[i]=='*'){
            ll add=cal(&ss[pos],i-pos,&pp[pos]);
            if(add==inf)return inf;
            ret*=add;
            pos=i+1;
            fin=true;
        }
    }
    if(fin){
        ll add=cal(&ss[pos],len-pos,&pp[pos]);
        if(add==inf)return inf;
        ret*=add;
        return ret;
    }
    if(ss[0]=='-'){
        ll add=cal(&ss[1],len-1,&pp[1]);
//        if(oo)printf("add=%lld\n",add);
        if(add==inf)return inf;
        return -add;
    }
//    if(oo)printf("he len=%d\n",len);
    if(ss[0]=='0' && len>1)return inf;
    ret=0;
    for(int i=0;i<len;++i){
        ret<<=1;
        if(ss[i]!='0' && ss[i]!='1')return inf;
        else if(ss[i]=='1')++ret;
//        if(oo)printf("i=%d ret=%d\n",i,ret);
    }
    return ret;
}
bool chk(char *ss,char *pp[]){
//    if(oo)printf("ch:%s %d %d\n",ss,ss,pp);
    int now=0;
    char *tmp[100];
    for(int i=0;ss[i];++i){
        if(ss[i]=='('){
            tmp[now++]=&ss[i];
        }else if(ss[i]==')'){
            --now;
            if(now<0)return false;
            pp[i]=tmp[now];
//            printf("cc:i=%d %d %d %d\n",i,pp[i],&pp[i],tmp[now]);
        }
    }
    if(now)return false;
    return true;
}
int main(){
    scanf("%s",s);
    for(int i=0;s[i];++i)use[s[i]]=true;
    for(int i='A';i<='Z';++i)if(use[i])x[cx++]=i;
    for(int i='a';i<='z';++i)if(use[i])x[cx++]=i;
    if(cx>8){
        printf("0\n");
    }else if(cx==0){
//        oo=true;
        int pos,cnt=0;
        for(int i=0;s[i];++i){
            if(s[i]=='=')++cnt,pos=i;
        }
        if(cnt==1){
            s[pos]=0;
            if(chk(s,pp) && chk(&s[pos+1],&pp[pos+1])){
                ll aa=cal(s,strlen(s),pp);
                ll bb=cal(&s[pos+1],strlen(&s[pos+1]),&pp[pos+1]);
//                    printf("%lld %lld\n",aa,bb);
                if(aa!=inf && bb!=inf && aa==bb){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
            }else{
                printf("0\n");
            }
        }else{
            printf("0\n");
        }
    }else{
        int ans=0;
//        printf("c=%d pp=%d\n",c,pp);
        do{
            bool pd=false;
            for(int i=0;i<cx;++i)if(pre[i]!=xt[i])pd=true;
            if(pd){
                strcpy(c,s);
                int pos,cnt=0;
                for(int i=0;c[i];++i){
                    for(int j=0;j<cx;++j){
                        if(c[i]==x[j]){
                            c[i]=xt[j];
                            break;
                        }
                    }
                    if(c[i]=='='){
                        ++cnt;
                        pos=i;
                    }
                }
                if(cnt==1){
                    c[pos]=0;
//                        if(strcmp(c,"0")==0 && strcmp(&c[pos+1],"-(0)")==0)oo=true;
//                        if(oo)printf("%s %s\n",c,&c[pos+1]);
                    if(chk(c,pp) && chk(&c[pos+1],&pp[pos+1])){
                        int la=strlen(c);
                        int lb=strlen(&c[pos+1]);
                        ll aa=cal(c,la,pp);
                        ll bb=cal(&c[pos+1],lb,&pp[pos+1]);
//                        if(oo)printf("%lld %lld\n",aa,bb);
                        if(aa!=inf && bb!=inf && aa==bb){
//                            printf("%s %s\n",c,&c[pos+1]);
//                        printf("aa=%lld bb=%lld\n",aa,bb);
                            ++ans;
                        }
//                        if(strcmp(c,"0")==0 && strcmp(&c[pos+1],"-(0)")==0)oo=false;
                    }
                }
                strcpy(pre,xt);
            }
        }while(next_permutation(xt,xt+8));
        printf("%d\n",ans);
    }
    return 0;
}

