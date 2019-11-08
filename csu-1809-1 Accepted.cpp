
#include<cstdio>
#include<algorithm>
using namespace std;
char s[100010];
int c[100010];
int cx2[100010],c0[100010],c2[100010];
int main(){
    int n,q,a,b;
    while(~scanf("%d%d%s",&n,&q,&s[1])){
        for(int i=1;i<=n;++i){
            if(s[i]=='('){
                c[i]=c[i-1]+1;
            }else{
                c[i]=c[i-1]-1;
            }
            if(c[i]<-2)cx2[i]=cx2[i-1]+1;else cx2[i]=cx2[i-1];
            if(c[i]<0)c0[i]=c0[i-1]+1;else c0[i]=c0[i-1];
            if(c[i]<2)c2[i]=c2[i-1]+1;else c2[i]=c2[i-1];
        }
        for(int i=0;i<q;++i){
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            if(c[n]!=0){
                printf("No\n");
            }else{
                bool pd=true;
                if(s[a]==s[b]){
                    if(c0[n]>0){
                        printf("No\n");
                    }else{
                        printf("Yes\n");
                    }
                }else if(s[a]=='('){
                    if(c0[a-1]>0)pd=false;
                    if(c2[b-1]-c2[a-1]>0)pd=false;
                    if(c0[n]-c0[b-1]>0)pd=false;
                    if(pd){
                        printf("Yes\n");
                    }else{
                        printf("No\n");
                    }
                }else{
                    if(c0[a-1]>0)pd=false;
                    if(cx2[b-1]-cx2[a-1]>0)pd=false;
                    if(c0[n]-c0[b-1]>0)pd=false;
                    if(pd){
                        printf("Yes\n");
                    }else{
                        printf("No\n");
                    }
                }
            }
        }
    }
    return 0;
}

