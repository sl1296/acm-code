
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char z[100000];
char ge[30];
bool is[200];
int main(){
    int cas;
    while(scanf("%d",&cas),cas!=-1){
        printf("Round %d\n",cas);
        scanf("%s%s",z,ge);
        memset(is,false,sizeof(is));
        int num=0;
        int len=strlen(z);
        for(int i=0;i<len;i++){
            if(is[z[i]]==false){
                is[z[i]]=true;
                num++;
            }
        }
        int wrong=0,right=0;
        int l=strlen(ge);
        for(int i=0;i<l;i++){
            if(is[ge[i]]){
                right++;
                is[ge[i]]=false;
            }else{
                wrong++;
            }
            if(wrong==7)break;
        }
        if(wrong==7)printf("You lose.\n");
        else if(right==num)printf("You win.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}

