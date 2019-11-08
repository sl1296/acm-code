
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
char x[110],s[110];
bool hv[110];
struct num{
    int len;
    char x[500];
    int operator% (const int a) const{
        int now=0;
        for(int i=len-1;i>=0;--i){
            now=now*10+x[i];
            now%=a;
        }
        return now;
    }
    num operator/ (const int a) const{
        num ret;
        ret.len=len;
        int now=0;
        for(int i=len-1;i>=0;--i){
            now=now*10+x[i];
            ret.x[i]=now/a;
            now%=a;
        }
        while(ret.len>1 && ret.x[ret.len-1]==0)--ret.len;
        return ret;
    }
    void out(){
        for(int i=len-1;i>=0;--i){
            printf("%c",x[i]<10?x[i]+'0':x[i]-10+'A');
        }
        printf("\n");
    }
};
vector<char> dp[500][100];
int dpn[500][100];
int main(){
    freopen("digits.in","r",stdin);
    freopen("digits.out","w",stdout);
    int n;
    scanf("%d%s%s",&n,x,s);
    for(int i=0;x[i];++i){
        if(x[i]<='9')hv[x[i]-'0']=true;
        else hv[x[i]-'A'+10]=true;
    }
    num in;
    in.len=strlen(s);
    for(int i=0;i<in.len;++i){
        in.x[i]=s[in.len-i-1]-'0';
    }
    num ch;
    if(n==10)ch=in;
    else{
        ch.len=0;
        while(in.len!=1 || in.x[0]!=0){
            ch.x[ch.len++]=in%n;
            in=in/n;
        }
        if(ch.len==0){
            ch.len=1;
            ch.x[0]=0;
        }
    }
//    ch.out();
    for(int i=0;i<36;++i){
        if(hv[i] && (i-ch.x[0])%n==0){
            int pos=50+(ch.x[0]-i)/n;
            dp[0][pos].push_back(i);
            dpn[0][pos]=1;
//            printf("i=%d pos=%d\n",i,pos);
        }
    }
    for(int i=1;i<ch.len;++i){
//        printf("i=%d\n",i);
        for(int j=50-35;j<=50+35;++j){
            if(dp[i-1][j].size()){
                int now=j-50+ch.x[i];
                for(int k=0;k<36;++k){
                    if(hv[k] && (k-now)%n==0){
                        int pos=50+(now-k)/n;
//                        printf("now=%d k=%d pos=%d\n",now,k,pos);
                        if(dp[i][pos].size()==0){
                            dp[i][pos]=dp[i-1][j];
                            dp[i][pos].push_back(k);
                            dpn[i][pos]=dpn[i-1][j];
                        }else{
                            dpn[i][pos]=2;
                        }
                    }
                }
            }
        }
    }
    if(dp[ch.len-1][50].size()){
        if(dpn[ch.len-1][50]==1){
            printf("Unique\n");
        }else{
            printf("Ambiguous\n");
        }
        bool out=false;
        for(int i=dp[ch.len-1][50].size()-1;i>=0;--i){
            if(out==false){
                if(dp[ch.len-1][50][i]==0){
                    continue;
                }else{
                    out=true;
                }
            }
            if(dp[ch.len-1][50][i]<10){
                printf("%c",dp[ch.len-1][50][i]+'0');
            }else{
                printf("%c",dp[ch.len-1][50][i]-10+'A');
            }
        }
        if(out==false){
            printf("0\n");
        }
        printf("\n");
    }else{
        printf("Impossible\n");
    }
    return 0;
}

