
#include <stdio.h>
char z[2010][2010];
int main(){
    int i,j,m,n,c,c2,d=1,x=0,o=0;
    char p,p2,r=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",z[i]);
    for(i=0;i<n;i++){z[n][i]=0;z[i][n]=0;}z[n][n]=0;
    for(i=0;i<n;i++){
        p=c=p2=c2=0;
        for(j=0;j<n+1;j++){
            if(z[i][j]=='X')x++;
            if(z[i][j]=='O')o++;
            if(z[i][j]!=p){
                if(c>m && p!='.'){
                    printf("ERROR");
                    return 0;
                }else if(c==m && p!='.'){
                    if(r==0){
                        r=p;
                    }else{
                        printf("ERROR");
                        return 0;
                    }
                }
                p=z[i][j];
                c=1;
            }else{
                c++;
            }
            if(z[j][i]!=p2){if(c2>m && p2!='.'){printf("ERROR");return 0;}else if(c2==m && p2!='.'){if(r==0){r=p2;}else{printf("ERROR");return 0;}}p2=z[j][i];c2=1;}else{c2++;}
            if(z[i][j]=='.')d=0;
        }
    }
    if(x>o+1 || x<o){printf("ERROR");return 0;}
    for(i=m-1;i<2*n-m;i++){
        p=c=0;
        for(j=0;j<=i+1;j++){
            if(z[j][i-j]!=p){if(c>m && p!='.'){printf("ERROR");return 0;}else if(c==m && p!='.'){if(r==0){r=p;}else{printf("ERROR");return 0;}}p=z[i][j];c=1;}else{c++;}
        }
    }
    for(i=n-m;i>=m-n;i--){
        p=c=0;
        for(j=(i>0?0:(-i));j<=(i>0?(n-i-1):(n-1))+1;j++){
            if(z[j][j+i]!=p){if(c>m && p!='.'){printf("ERROR");return 0;}else if(c==m && p!='.'){if(r==0){r=p;}else{printf("ERROR");return 0;}}p=z[i][j];c=1;}else{c++;}
        }
    }
    if(r=='X'){printf("X WINS");} else if(r=='O'){printf("O WINS"); }else{if(d){printf("DRAW");} else{ printf("IN PROGRESS");}}
    return 0;
}

