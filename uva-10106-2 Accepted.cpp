
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
char s1[300],s2[300];
bigint quickpow(bigint a,bigint n){
    bigint ret=0;
    while(0<n){
        if(n%2==1)ret=ret+a;
        a=a+a;
        n=n/2;
    }
    return ret;
}
int main(){
    while(~scanf("%s%s",s1,s2)){
        bigint a=s1,b=s2;
        quickpow(a,b).output();
    }
    return 0;
}

