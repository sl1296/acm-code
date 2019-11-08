
#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
vector<int> vec;
vector<int> g[maxn];
char s[maxn][maxn];
bool used[maxn];
int tmp[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<n;j++){
            if(s[i][j]=='0') g[j].push_back(i);
        }
    }
    vec.push_back(0);
    used[0]=true;
    int p=0;
    while(true){
        int o=0;
        for(int i=p;i<vec.size();i++){
            int t=vec[i];
            for(int j=0;j<g[t].size();j++){
                if(used[g[t][j]]) continue;
                used[g[t][j]]=true;
                tmp[o++]=g[t][j];
            }
        }
        if(!o) break;
        p=vec.size();
        for(int i=0;i<o;i++)
            vec.push_back(tmp[i]);
    }
    if(vec.size()<n) printf("impossible\n");
    else{
        for(int i=vec.size()-1;i>=0;i--)
            printf("%d%c",vec[i],i?' ':' ');
    }
    return 0;
}

