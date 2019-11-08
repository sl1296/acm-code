
#include<cstdio>
int main(){
    int t,a;
    scanf("%d",&t);
    while(t--){
        int c=0;
        bool pd=false;
        for(int i=0;i<30;++i){
            scanf("%d",&a);
            if(a==1){
                ++c;
                if(c>5)pd=true;
            }else{
                c=0;
            }
        }
        if(pd)printf("#coderlifematters\n");
        else printf("#allcodersarefun\n");
    }
    return 0;
}

