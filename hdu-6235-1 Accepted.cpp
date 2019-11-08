
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int s=1,e=n,c=0;
        while(1){
            if(s<=e){
                if(c)printf(" ");
                printf("%d",s);
                ++c;++s;
            }else{
                break;
            }
            if(s<=e){
                if(c)printf(" ");
                printf("%d",e);
                ++c;--e;
            }else{
                break;
            }
        }
        printf("\n");
    }
    return 0;
}


