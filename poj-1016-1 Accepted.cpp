
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
string ch(string x){
    int cnt[10]={0};
    char tmp[100];
    int sz=x.size();
    for(int i=0;i<sz;i++){
        cnt[x[i]-'0']++;
    }
    string ret;
    for(int i=0;i<10;i++){
        if(cnt[i]){
            int cc=0;
            while(cnt[i]){
                tmp[cc++]=cnt[i]%10+48;
                cnt[i]/=10;
            }
            for(cc--;cc>=0;cc--){
                ret+=tmp[cc];
            }
            ret+=i+'0';
        }
    }
    return ret;
}
char s[10010];
int main(){
    while(1){
        scanf("%s",&s);
        if(strcmp(s,"-1")==0)break;
        map<string,int> ma;
        string now=s;
        ma[now]=1;
        string xx=ch(now);
        if(xx==now){
            printf("%s is self-inventorying\n",s);
            continue;
        }
        ma[xx]=2;
        now=xx;
        bool fin=false;
        for(int i=3;i<=16;i++){
            now=ch(now);
            int id=ma[now];
            if(id){
                fin=true;
                if(id==i-1){
                    printf("%s is self-inventorying after %d steps\n",s,id-1);
                }else{
                    printf("%s enters an inventory loop of length %d\n",s,i-id);
                }
                break;
            }
            ma[now]=i;
        }
        if(!fin)printf("%s can not be classified after 15 iterations\n",s);
    }
    return 0;
}

