
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[20];
bool iip[1100][35];
bool ans1[35],ans2[35];
int re1[5],re2[5];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int p=0;
            int l=strlen(s);
            for(int j=0;j<4;j++){
                int ip=s[p]-'0';
                p++;
                while(s[p]!='.' && s[p]!=0){
                    ip=ip*10+s[p]-'0';
                    p++;
                }
                p++;
                for(int k=j*8+7;k>j*8-1;k--){
                    iip[i][k]=ip%2;
                    ip/=2;
                }
               // for(int jj=0;jj<32;jj++)printf("%d",iip[i][jj]);
              //  printf("\n");
            }
        }
        memset(ans1,false,sizeof(ans1));
        memset(ans2,false,sizeof(ans2));
        for(int i=0;i<32;i++){
            bool tmp=iip[0][i];
            int j;
            for(j=1;j<n;j++){
                if(iip[j][i]!=tmp)break;
            }
            if(j<n)break; else{ans1[i]=tmp;ans2[i]=true;}
        }
        for(int i=0;i<4;i++){
            re1[i]=re2[i]=0;
            for(int j=0;j<8;j++){
                re1[i]=re1[i]*2+ans1[i*8+j];
                re2[i]=re2[i]*2+ans2[i*8+j];
            }
        }
        for(int i=0;i<4;i++){
            if(i)printf(".");
            printf("%d",re1[i]);
        }
        printf("\n");
        for(int i=0;i<4;i++){
            if(i)printf(".");
            printf("%d",re2[i]);
        }
        printf("\n");
    }
}

