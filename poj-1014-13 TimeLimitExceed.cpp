
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int a[20010];
int dv[1000],dc;
int tmp[1000],tc;
bool ans;
void check(){
    set<int> se;
    se.insert(0);
    int sum=0;
    for(int i=0;i<dc;i++){
        sum+=dv[i];
        tc=0;
        for(set<int>::iterator it=se.begin();it!=se.end();++it){
            tmp[tc++]=(*it)+dv[i];
        }
        for(int j=0;j<tc;j++){
            se.insert(tmp[j]);
        }
    }
    if(se.count(sum/2))ans=true;
}
int main(){
    int a,b,c,d,e,f,cas=1;
    int aa,bb,cc,dd,ee,ff;
    while(~scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)){
        if(!a&&!b&&!c&&!d&&!e&&!f)break;
        printf("Collection #%d:\n",cas++);
        if((a+b*2+c*3+d*4+e*5+f*6)&1){
            printf("Can't be divided.\n\n");
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
        for(int i=0;i<7;i++){
            check();
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
            if(a+b*2+c*3+d*4+e*5+f*6>100)while(1);
            printf("Can be divided.\n");
        }else{
            printf("Can't be divided.\n");
        }
        printf("\n");
    }
    return 0;
}

