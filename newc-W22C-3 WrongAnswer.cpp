
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char f[1010],g[1010];
int fx[1010],gx[1010],fz,gz;
inline void add(vector<int> &a,vector<int> &b){
//    printf("add");
    a.resize(max(a.size(),b.size()));
    for(int i=0;i<b.size();++i)a[i]+=b[i];
    b.clear();
//    printf("add");
}
inline void mul(vector<int> &a,vector<int> &b){
    vector<int> c(a.size()+b.size());
    for(int i=0;i<c.size();++i)c[i]=0;
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b.size();++j){
            c[i+j+1]+=a[i]*b[j];
        }
    }
    a=c;
    b.clear();
}
inline void cal(char *s,int *x,int &siz){
    vector<int> ve[1010],op;
    int len=strlen(s),now=0;
    for(int i=0;i<len;++i){
        if(s[i]=='x'){
            ve[now].push_back(1);
            ++now;
        }else if(s[i]=='*'){
            op.push_back(2);
        }else if(s[i]=='('){
            op.push_back(3);
        }else if(s[i]=='+'){
            while(op.size()&&op[op.size()-1]==2){
                mul(ve[now-2],ve[now-1]);
                --now;
                op.pop_back();
            }
            if(!i||i&&s[i-1]=='('){
                ve[now].push_back(0);
                ++now;
            }
            op.push_back(1);
        }else if(s[i]==')'){
            while(op.size()&&op[op.size()-1]!=3){
                if(op[op.size()-1]==1){
                    add(ve[now-2],ve[now-1]);
                }else{
                    mul(ve[now-2],ve[now-1]);
                }
                --now;
                op.pop_back();
            }
            op.pop_back();
        }
//        printf("i=%d op sz=%d\n",i,op.size());
//        for(int i=0;i<op.size();++i)printf("%d ",op[i]);
//        printf("\nnow=%d\n",now);
//        for(int i=0;i<now;++i){
//            printf("sz=%d ",ve[i].size());
//            for(int j=0;j<ve[i].size();++j)printf("%d ",ve[i][j]);
//            printf("\n");
//        }
    }
    while(op.size()){
//        printf("%d\n",op.size());
        if(op[op.size()-1]==1){
            add(ve[now-2],ve[now-1]);
        }else{
            mul(ve[now-2],ve[now-1]);
        }
        --now;
        op.pop_back();
    }
    --now;
    siz=ve[now].size();
    for(int i=0;i<siz;++i)x[i]=ve[now][i];
//    printf("siz=%d\n",siz);
}
int main(){
    scanf("%s%s",f,g);
    cal(f,fx,fz);
    cal(g,gx,gz);
//    printf("%d %d\n",fz,gz);
//    for(int i=0;i<fz;++i)printf("%d ",fx[i]);printf("\n");
//    for(int i=0;i<gz;++i)printf("%d ",gx[i]);printf("\n");
    if(fz>gz)printf("1/0\n");
    else if(fz<gz)printf("0/1\n");
    else{
        int gcd=__gcd(fx[fz-1],gx[gz-1]);
        printf("%d/%d",fx[fz-1]/gcd,gx[gz-1]/gcd);
    }
    return 0;
}

