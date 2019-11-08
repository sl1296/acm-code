
#include<cstdio>
#include<cstring>
char s[200010],t[200010];
int main(){
    int n,m;
    scanf("%d%d%s%s",&n,&m,s,t);
    int pos=-1;
    for(int i=0;i<n;++i){
        if(s[i]=='*'){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        if(strcmp(s,t)){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }else{
        if(m<n-1){
            printf("NO\n");
        }else{
            bool pd=true;
            for(int i=0;i<pos;++i){
                if(s[i]!=t[i]){
                    pd=false;
                    break;
                }
            }
            if(pd){
                for(int i=n-1,j=m-1;i>pos;--i,--j){
                    if(s[i]!=t[j]){
                        pd=false;
                        break;
                    }
                }
            }
            if(pd){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}

