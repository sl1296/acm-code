
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char in[41][410];
char dp[41][90][410];
int pos[410],posn;
char tmp[410];
int ans[41];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)scanf("%s",in[i]);
        memset(dp,0,sizeof(dp));
        strcpy(dp[0][0],in[0]);
        posn=1;
        for(int i=0;i<m;i++)if(in[0][i]!=48)pos[posn++]=i;
        int en=min(m*n,85);
        for(int i=1;i<=en;i++){
            strcpy(dp[0][i],dp[0][i-1]);
            if(i<posn)dp[0][i][pos[i]]=48;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=en;j++){
                for(int k=0;k<=j&&k<=m;k++){
                  //  printf("i=%d j=%d k=%d\n",i,j,k);
                    if(dp[i-1][j-k][0]==0)continue;
                    posn=0;
                    for(int l=0;l<m;l++)if(dp[i-1][j-k][l]!=in[i][l])pos[posn++]=l;
                  //  printf("posn=%d\n",posn);
                    if(k>=posn){
                      //  printf("type1\n");
                        if((dp[i][j][0]&&strcmp(dp[i][j],dp[i-1][j-k])>0)||dp[i][j][0]==0)strcpy(dp[i][j],dp[i-1][j-k]);
                    }else if(k==0){
                     //   printf("type2\n");
                        if(strcmp(in[i],dp[i-1][j-k])>=0)strcpy(dp[i][j],in[i]);
                    }else{
                     //   printf("type3 %s %s\n",dp[i-1][j-k],in[i]);
                        strcpy(tmp,in[i]);
                        if(strcmp(tmp+pos[k-1]+1,dp[i-1][j-k]+pos[k-1]+1)>=0){
                         //   printf("3-1\n");
                            for(int l=0;l<k;l++)tmp[pos[l]]=dp[i-1][j-k][pos[l]];
                       //     printf("%s\n",tmp);
                            if(dp[i][j][0]==0||(dp[i][j][0]&&strcmp(dp[i][j],tmp)>0))strcpy(dp[i][j],tmp);
                        }else{
                        //    printf("3-2\n");
                            posn=pos[k-1];
                            while(posn>=0&&dp[i-1][j-k][posn]==57)posn--;
                         //   printf("9:%d\n",posn);
                            if(posn>=0){
                              //  printf("pass\n");
                                int cnt=0;
                                tmp[posn]=dp[i-1][j-k][posn]+1;
                                if(tmp[posn]!=in[i][posn])cnt++;
                                for(int l=0;l<posn;l++)if(tmp[l]!=dp[i-1][j-k][l])cnt++,tmp[l]=dp[i-1][j-k][l];
                                for(int l=posn+1;l<m;l++)if(tmp[l]!=0&&cnt<k)tmp[l]=48,cnt++;
                              //  printf("%s\n",tmp);
                                if((strcmp(dp[i][j],tmp)>0&&dp[i][j][0])||dp[i][j][0]==0)strcpy(dp[i][j],tmp);
                            }
                        }
                    }
                }
            }
        }
     /*   for(int i=0;i<n;i++){
            for(int j=0;j<en;j++){
                printf("%2d-%2d-%2d ",dp[i][j][0],dp[i][j][1],dp[i][j][2]);
            }
            printf("\n");
        }*/
        for(posn=0;posn<=en;posn++)if(dp[n-1][posn][0])break;
        ans[n-1]=posn;
        for(int i=n-1;i>0;i--){
            int cnt=0;
            for(int j=0;j<m;j++)if(in[i][j]!=dp[i][posn][j])cnt++;
            posn-=cnt;
            ans[i-1]=posn;
        }
        for(int i=0;i<n;i++)printf("%s\n",dp[i][ans[i]]);
    }
    return 0;
}
/*
5 3
111
001
000
111
000
*/
/*
111 011 001 000 000 000 000 000 000 000 000 000 000 000 000
--- 101 001 001 000 000 000 000 000 000 000 000 000 000 000
--- --- 100 001 000 000 000 000 000 000 000 000 000 000 000
--- --- 111 101 011 001 001 001 001 001 001 001 001 001 001
--- --- --- 100 100 010 001 001 001 001 001 001 001 001 001
*/

