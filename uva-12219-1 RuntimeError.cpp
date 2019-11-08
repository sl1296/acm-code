
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char s[50010];
struct tree{
    bool have;
    char s[5];
    int l,r;
    tree(){
        memset(s,0,sizeof(s));
        l=r=0;
        have=false;
    }
    bool operator < (const tree &p) const{
        if(have!=p.have)return have<p.have;
        if(l!=p.l)return l<p.l;
        for(int i=0;i<5;i++){
            if(s[i]!=p.s[i])return s[i]<p.s[i];
        }
        return r<p.r;
    }
};
int last[50010];
tree mmap[50010];
tree stak[50010];
int now[50010];
map<tree,int> ma;
int ans;
void dfs(tree x){
    int now=ma[x];
    if(last[now]){
        printf("%d",last[now]);
        return;
    }
    last[now]=++ans;
    printf("%s",x.s);
    if(x.have){
        printf("(");
        dfs(mmap[x.l]);
        printf(",");
        dfs(mmap[x.r]);
        printf(")");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        memset(last,0,sizeof(last));
        ans=0;
        scanf("%s",s);
        int len=strlen(s);
        ma.clear();
        stak[0]=tree();
        int cs=0,cc;
        now[0]=0;
        int cnt=0;
        for(int i=0;i<len;){
          //  printf("i=%d cs=%d now=%d\n",i,cs,now[cs]);
            if(now[cs]==0){
                cc=0;
                while(s[i]!='('&&s[i]!=')'&&s[i]!=','&&s[i]!=0){
                    stak[cs].s[cc++]=s[i++];
                }
            //    printf("name:%s\n",stak[cs].s);
                if(s[i]!='('){
                    if(ma[stak[cs]]==0){
                        ma[stak[cs]]=++cnt;
                        mmap[cnt]=stak[cs];
                    }
                    now[cs]=ma[stak[cs]];
                  //  printf("id=%d back\n",now[cs]);
                    cs--;
                    if(cs<0)break;
                }else{
                  //  printf("to l\n");
                    now[cs]=1;
                    stak[cs].have=true;
                    cs++;
                    stak[cs]=tree();
                    now[cs]=0;
                    i++;
                }
            }else if(now[cs]==1){
             //   printf("id=%d to r\n",now[cs+1]);
                now[cs]=2;
                stak[cs].l=now[cs+1];
                cs++;
                stak[cs]=tree();
                now[cs]=0;
                i++;
            }else{
            //    printf("id=%d\n",now[cs+1]);
                stak[cs].r=now[cs+1];
                if(ma[stak[cs]]==0){
                    ma[stak[cs]]=++cnt;
                    mmap[cnt]=stak[cs];
                }
                now[cs]=ma[stak[cs]];
             //   printf("end back id=%d\n",now[cs]);
                cs--;
                if(cs<0)break;
                i++;
            }
        }
        dfs(stak[0]);
        printf("\n");
    }
    return 0;
}

