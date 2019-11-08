
#include<cstdio>
using namespace std;
struct stu{
    int a,b,c;
    bool q;
};
stu s[15];
int st[15];
int main(){
    int n,cas=1;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        int qq=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            s[i].q=s[i].a>=s[i].c;
            if(s[i].q)qq++;
            st[i]=s[i].c;
        }
        int sq=qq;
        int tt=1;
        if(qq==n)goto a;
        int tmp;
        while(1){
            tmp=0;
            for(int i=0;i<n;i++){
                if(s[i].c==s[i].a+s[i].b){
                    s[i].c=1;
                    s[i].q=true;
                }else if(s[i].c==s[i].a){
                    if(qq<n-qq){
                        s[i].c++;
                        s[i].q=false;
                    }else{
                        s[i].c=1;
                    }
                }else{
                    s[i].c++;
                }
                if(s[i].q)tmp++;
            }
            qq=tmp;
            tt++;
            if(qq==n){
                break;
            }else if(qq==sq){
                bool is=true;
                for(int i=0;i<n;i++){
                    if(s[i].c!=st[i]){
                        is=false;
                        break;
                    }
                }
                if(is){
                    tt=-1;
                    break;
                }
            }
        }
        a:
        printf("Case %d: %d\n",cas++,tt);
    }
    return 0;
}

