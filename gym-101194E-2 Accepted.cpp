
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
    friend bool operator > (const bigint& u,const bigint& v);
    friend bool operator <= (const bigint& u,const bigint& v);
    friend bool operator >= (const bigint& u,const bigint& v);
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
bool operator > (const bigint& u,const bigint& v){
    return v<u;
}
bool operator <= (const bigint& u,const bigint& v){
    return !(v<u);
}
bool operator >= (const bigint& u,const bigint& v){
    return !(u<v);
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

struct bigfs{
    bigint fz,fm;
    bigfs(bigint u=0,bigint v=0){
        fz=u;fm=v;
    }
    bigfs operator + (const bigfs &p) const{
        if(fm==p.fm)return bigfs(fz+p.fz,fm);
        return bigfs(fz*p.fm+fm*p.fz,fm*p.fm);
    }
    bigfs operator - (const bigfs &p) const{
        if(fm==p.fm)return bigfs(fz-p.fz,fm);
        return bigfs(fz*p.fm-p.fz*fm,fm*p.fm);
    }
    bigfs operator * (const bigfs &p) const{
        return bigfs(fz*p.fz,fm*p.fm);
    }
    bigfs operator / (const bigfs &p) const{
        return bigfs(fz*p.fm,fm*p.fz);
    }
    bool operator == (const bigfs &p) const{
        return fm==p.fm&&fz==p.fz;
    }
    bool operator < (const bigfs &p) const{
        if(!fm.flag^p.fm.flag){
            return fz*p.fm<p.fz*fm;
        }else{
            return fz*p.fm>p.fz*fm;
        }
    }
    bool operator > (const bigfs &p) const{
        return p<(*this);
    }
    bool operator <= (const bigfs &p) const{
        return !(p<(*this));
    }
    bool operator >= (const bigfs &p) const{
        return !((*this)<p);
    }
};



int main(){
    int t;
    bigfs x;
    scanf("%d",&t);
    //bigint fz[110],fm[110];
    bigfs fx[110];
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            double t1,t2;
            scanf("%lf:%lf",&t1,&t2);
            bigint tt1=(int)(t1*1000+0.5);
            bigint tt2=(int)(t2*1000+0.5);
//            fz[i]=tt1;
//            fm[i]=tt1+tt2;
            fx[i]=bigfs(tt1,tt1+tt2);
        }
//        for(int i=0;i<n;i++){
//            for(int j=i+1;j<n;j++){
//                if(fm[i]*fz[j]<fz[i]*fm[j]){
//                    swap(fm[i],fm[j]);
//                    swap(fz[i],fz[j]);
//                }
//            }
//        }
        sort(fx,fx+n);
       // bigint tfz=0,tfm=1;
        bigfs tfx=bigfs(0,1);
        bigfs one=bigfs(1,1);
        int cnt=0;
        for(int i=0;i<n;i++){
//            tfz=tfz*fm[i]+tfm*fz[i];
//            tfm=tfm*fm[i];
            tfx=tfx+fx[i];
//            if(tfz>=tfm)break;
            if(tfx>=one)break;
            cnt++;
        }
        printf("Case #%d: %d\n",z,cnt);
    }
    return 0;
}

