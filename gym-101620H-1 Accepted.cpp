
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char in[10010];
int t;
struct cc{
    int x;
    string name;
    bool operator < (const cc &p) const{
        return name<p.name;
    }
};
struct node{
    bool open;
    string name;
    int sz;
    vector<cc> sn;
};
vector<node> ve;
int dfs(int x,string path){
    path+=ve[x].name;
    path+="/";
    int sz=ve[x].sn.size(),ret=ve[x].sz;
    for(int i=0;i<sz;++i){
        int tmp=dfs(ve[x].sn[i].x,path);
        if(tmp>=t && ve[ve[x].sn[i].x].sn.size())ve[x].open=true;
        ret+=tmp;
    }
//    printf("x=%d path=%s ret=%d\n",x,path.c_str(),ret);
    return ve[x].sz=ret;
}
void out(int x,string path){
    path+=ve[x].name;
    path+='/';
    int sz=ve[x].sn.size(),szx=0;
    for(int i=0;i<sz;++i){
        if(ve[ve[x].sn[i].x].sn.size())++szx;
    }
    if(szx==0)printf("  %s %d\n",path.c_str(),ve[x].sz);
    else if(ve[x].open==false)printf("+ %s %d\n",path.c_str(),ve[x].sz);
    else{
        printf("- %s %d\n",path.c_str(),ve[x].sz);
        for(int i=0;i<sz;++i){
            if(ve[ve[x].sn[i].x].sn.size())
            out(ve[x].sn[i].x,path);
        }
    }
}
int main(){
    int n,ad;
    scanf("%d",&n);
    ve.resize(1);
    ve[0].name.clear();
    ve[0].sz=0;
    ve[0].sn.clear();
    ve[0].open=false;
    for(int i=0;i<n;++i){
        scanf("%s%d",in,&ad);
        int len=strlen(in),now=0;
        for(int i=1;i<len;++i){
            string tmp="";
            while(in[i]!='/' && in[i]!=0){
                tmp+=in[i];
                ++i;
            }
            int pos=lower_bound(ve[now].sn.begin(),ve[now].sn.end(),(cc){0,tmp})-ve[now].sn.begin();
//            printf("%s %d\n",tmp.c_str(),pos);
            if(pos<ve[now].sn.size() && ve[now].sn[pos].name==tmp){
                now=ve[now].sn[pos].x;
            }else{
                ve[now].sn.push_back((cc){ve.size(),tmp});
                sort(ve[now].sn.begin(),ve[now].sn.end());
                node add;
                add.open=false;
                add.name=tmp;
                add.sz=0;
                add.sn.clear();
                ve.push_back(add);
                now=ve.size()-1;
            }
        }
        ve[now].sz+=ad;
    }
    scanf("%d",&t);
    dfs(0,"");
    out(0,"");
    return 0;
}
/*
9
/sys/kernel/notes 100
/cerc/problems/a/testdata/in 1000000
/cerc/problems/a/testdata/out 8
/cerc/problems/a/luka.cc 500
/cerc/problems/a/zuza.cc 5000
/cerc/problems/b/testdata/in 15
/cerc/problems/b/testdata/out 4
/cerc/problems/b/kale.cc 100
/cerc/documents/rules.pdf 4000
10000
*/

