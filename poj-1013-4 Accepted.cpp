
#include<cstdio>
#include<cstring>
using namespace std;
char s1[10][100],s2[10][100],s3[10][100];
int w[20];
bool u[20],d[20];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s%s",s1[0],s2[0],s3[0]);
        scanf("%s%s%s",s1[1],s2[1],s3[1]);
        scanf("%s%s%s",s1[2],s2[2],s3[2]);
        for(int i=0;i<12;i++)w[i]=5;
        for(int i=0;i<12;i++){
            w[i]=4;
            u[i]=true;
            for(int j=0;j<3;j++){
                int len=strlen(s1[j]);
                int x=0,y=0;
                for(int k=0;k<len;k++){
                    x+=w[s1[j][k]-'A'];
                    y+=w[s2[j][k]-'A'];
                }
                if((x==y&&strcmp(s3[j],"even"))||(x<y&&strcmp(s3[j],"down"))||(x>y&&strcmp(s3[j],"up"))){
                    u[i]=false;
                    break;
                }
            }
            w[i]=5;
        }
        int cnt=0,ans;
        for(int j=0;j<12;j++){
            if(u[j]){
                cnt++;
                ans=j;
            }
        }
        if(cnt==1){
            printf("%c is the counterfeit coin and it is light.\n",'A'+ans);
            continue;
        }
        for(int i=0;i<12;i++){
            w[i]=6;
            d[i]=true;
            for(int j=0;j<3;j++){
                int len=strlen(s1[j]);
                int x=0,y=0;
                for(int k=0;k<len;k++){
                    x+=w[s1[j][k]-'A'];
                    y+=w[s2[j][k]-'A'];
                }
                if((x==y&&strcmp(s3[j],"even"))||(x<y&&strcmp(s3[j],"down"))||(x>y&&strcmp(s3[j],"up"))){
                    d[i]=false;
                    break;
                }
            }
            w[i]=5;
        }
        for(int j=0;j<12;j++){
            if(d[j]){
                printf("%c is the counterfeit coin and it is heavy.\n",'A'+j);
                break;
            }
        }
    }
    return 0;
}

