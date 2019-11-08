
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
char s[10][10];
char in[1000000];
map<char,int> tx,ty;
int main(){
    tx['A']=-1;
    ty['A']=0;
    tx['B']=1;
    ty['B']=0;
    tx['L']=0;
    ty['L']=-1;
    tx['R']=0;
    ty['R']=1;
    int cas=0;
    while(1){
        memset(s,0,sizeof(s));
        gets(&s[1][1]);
        if(strcmp(&s[1][1],"Z")==0)break;
        for(int i=2;i<6;i++)gets(&s[i][1]);
        int x,y;
        for(int i=1;i<6;i++){
            for(int j=1;j<6;j++){
                if(s[i][j]==' '){
                    x=i;
                    y=j;
                }
            }
        }
        bool is=true;
        while(1){
            gets(in);
            int l=strlen(in);
            int i;
            for(i=0;i<l;i++){
                if(in[i]==' ')continue;
                if(in[i]=='0')break;
                if(is){
                    if(s[x+tx[in[i]]][y+ty[in[i]]]){
                        s[x][y]=s[x+tx[in[i]]][y+ty[in[i]]];
                        x=x+tx[in[i]];
                        y=y+ty[in[i]];
                        s[x][y]=' ';
                    }else{
                        is=false;
                    }
                }
            }
            if(in[i]=='0')break;
        }
        if(cas)printf("\n");
        cas++;
        printf("Puzzle #%d:\n",cas);
        if(is==false){
            printf("This puzzle has no final configuration.\n");
        }else{
            for(int i=1;i<6;i++){
                for(int j=1;j<6;j++){
                    if(j!=1)printf(" ");
                    printf("%c",s[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

