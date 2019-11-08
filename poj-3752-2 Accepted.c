
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110][110];
int main(){
    int m,n,i,j,x,y,k;
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(s,0,sizeof(s));
        for(i=0;i<n+2;i++)s[0][i]=s[m+1][i]=1;
        for(i=1;i<=m;i++)s[i][0]=s[i][n+1]=1;
        x=y=1;k=0;s[1][1]='A';
        while(1){
            while(!s[x][y+1]){y++;k++;if(k>25)k=0;s[x][y]=k+'A';}
            while(!s[x+1][y]){x++;k++;if(k>25)k=0;s[x][y]=k+'A';}
            while(!s[x][y-1]){y--;k++;if(k>25)k=0;s[x][y]=k+'A';}
            while(!s[x-1][y]){x--;k++;if(k>25)k=0;s[x][y]=k+'A';}
            if(s[x][y+1])break;
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                printf("   %c",s[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

