
#include<bits/stdc++.h>
using namespace std;
char s1[200],s2[200],tmp[200];
int x1[100],x2[100],x3[200];
void cal(char* s,int* x){
    memset(x,0,sizeof(x1));
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int f=i;
        int now=1,pos=1;
        if(s[i]!='x'){
            while(s[i]!='x'&&s[i]!=0)i++;
            for(int j=f;j<i;j++)tmp[j-f]=s[j];
            tmp[i-f]=0;
            now=atoi(tmp);
            if(strcmp(tmp,"-")==0)now=-1;
        }
        if(s[i]!='x')pos=0;
        else{
            if(s[i+1]=='^'){
                i=f=i+2;
                while(s[i]!='+'&&s[i]!='-'&&s[i]!=0)i++;
                for(int j=f;j<i;j++)tmp[j-f]=s[j];
                tmp[i-f]=0;
                pos=atoi(tmp);
                i--;
            }
        }
        x[pos]=now;
    }
}
int main(){
    while(~scanf("%s%s",s1,s2)){
        cal(s1,x1);
        cal(s2,x2);
        memset(x3,0,sizeof(x3));
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                x3[i+j]+=x1[i]*x2[j];
            }
        }
        bool f=false;
        for(int i=100;i>=0;i--){
            if(x3[i]){
                if(f)printf(" ");
                printf("%d",x3[i]);
                f=true;
            }
        }
        printf("\n");
    }
    return 0;
}

