
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
string in[120010];
char inn[100000];
string ans[120010];
map<string,int> ma;
int main(){
    int cnt=0;
    while(~scanf("%s",inn)){
        in[cnt]=inn;
        ma[in[cnt++]]=1;
    }
    int cc=0;
    for(int i=0;i<cnt;i++){
        int len=in[i].size();
        for(int j=1;j<len;j++){
            if(ma[in[i].substr(0,j)]&&ma[in[i].substr(j,len-j)]){
                ans[cc++]=in[i];
                break;
            }
        }
    }
    sort(ans,ans+cc);
    for(int i=0;i<cc;i++){
        printf("%s\n",ans[i].c_str());
    }
    return 0;
}

