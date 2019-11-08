
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20010];
int dv[1000],dc;
bool ans;
void dfs(int now,int x,int y){
    if(now==-1){
        if(x==y)ans=true;
        return;
    }
    if(x<y){
        dfs(now-1,x+dv[now],y);
        if(ans)return;
        dfs(now-1,x,y+dv[now]);
        if(ans)return;
    }else{
        dfs(now-1,x,y+dv[now]);
        if(ans)return;
        dfs(now-1,x+dv[now],y);
        if(ans)return;
    }
}
int main(){
    int a,b,c,d,e,f,cas=1;
    int aa,bb,cc,dd,ee,ff;
    while(~scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)){
        if(!a&&!b&&!c&&!d&&!e&&!f)break;
        printf("Collection #%d:\n",cas++);
        if((a+b+c+d+e+f)&1){
            printf("Can't be divided.\n");
            continue;
        }
        dc=0;
        aa=a/2;bb=b/2;cc=c/2;dd=d/2;ee=e/2;ff=f/2;
        if(a&1)dv[dc++]=1;
        if(b&1)dv[dc++]=2;
        if(c&1)dv[dc++]=3;
        if(d&1)dv[dc++]=4;
        if(e&1)dv[dc++]=5;
        if(f&1)dv[dc++]=6;
        ans=false;
        for(int i=0;i<4;i++){
            sort(dv,dv+dc);
            dfs(dc-1,0,0);
            if(ans)break;
            if(aa){
                aa--;
                dv[dc++]=1;
                dv[dc++]=1;
            }
            if(bb){
                bb--;
                dv[dc++]=2;
                dv[dc++]=2;
            }
            if(cc){
                cc--;
                dv[dc++]=3;
                dv[dc++]=3;
            }
            if(dd){
                dd--;
                dv[dc++]=4;
                dv[dc++]=4;
            }
            if(ee){
                ee--;
                dv[dc++]=5;
                dv[dc++]=5;
            }
            if(ff){
                ff--;
                dv[dc++]=6;
                dv[dc++]=6;
            }
        }
        if(ans){
            printf("Can be divided.\n");
        }else{
            printf("Can't be divided.\n");
        }
        printf("\n");
    }
    return 0;
}

