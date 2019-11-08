
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
char s[110];
int d[110][110];
int c[110][110];
void prin(int i,int j){
    if(i>j)return;
    if(i==j){
        if(s[i]=='(' || s[i]==')')printf("()"); else printf("[]");
    }else{
        if(c[i][j]>=0){
            prin(i,c[i][j]);
            prin(c[i][j]+1,j);
        }else{
            if(s[i]=='('){
                printf("(");
                prin(i+1,j-1);
                printf(")");
            }else{
                printf("[");
                prin(i+1,j-1);
                printf("]");
            }
        }
    }
}
int main(){
    while(scanf("%s",s)!=EOF){
        memset(d,0,sizeof(d));
        memset(c,0,sizeof(c));
        c[0][0]=-1;
        int i,j,k,l,len=strlen(s),mmin;
        for(i=0;i<len;i++)d[i][i]=1;
        for(i=1;i<len;i++){
            for(j=0;j+i<len;j++){
                k=j+i;
                mmin=d[j][j]+d[j+1][k];
                c[j][k]=j;
                for(l=j+1;l<k;l++){
                    if(d[j][l]+d[l+1][k]<mmin){
                        mmin=d[j][l]+d[l+1][k];
                        c[j][k]=l;
                    }
                }
                d[j][k]=mmin;
                if((s[j]=='(' && s[k]==')') || (s[j]=='[' && s[k]==']')){
                    if(d[j+1][k-1]<mmin){
                        d[j][k]=d[j+1][k-1];
                        c[j][k]=-1;
                    }
                }
            }
        }
        prin(0,len-1);
        printf("\n");
    }
}

