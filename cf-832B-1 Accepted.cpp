
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int pd[200];
char good[100],bz[100010],x[100010];
int n;
int main(){
    while(~scanf("%s%s%d",good,bz,&n)){
        int i,len,isx=0,pos;
        memset(pd,0,sizeof(pd));
        for(i=0;good[i];i++)pd[good[i]]=1;
        for(i=0;bz[i];i++)if(bz[i]=='*')pos=i,isx=1;
        len=i;
        for(i=0;i<n;i++){
            scanf("%s",x);
            int j;
            if(isx){
                int ll=strlen(x);
                if(ll<len-1){
                    printf("NO\n");
                    continue;
                }
                for(j=0;j<pos;j++){
                    if(bz[j]==x[j]||(bz[j]=='?'&&pd[x[j]]==1));else break;
                }
                if(j<pos){
                    printf("NO\n");
                    continue;
                }
                int k;
                for(j=ll,k=len;k>pos;k--,j--){
                    if(bz[k]==x[j]||(bz[k]=='?'&&pd[x[j]]==1));else break;
                }
                if(k>pos){
                    printf("NO\n");
                    continue;
                }
                for(;j>=pos;j--){
                    if(pd[x[j]])break;
                }
                if(j>=pos){
                    printf("NO\n");
                }else{
                    printf("YES\n");
                }
            }else{
                for(j=0;j<len;j++){
                    if((bz[j]==x[j]||(bz[j]=='?'&&pd[x[j]]==1))&&x[j]);else break;
                }
                if(j<len||x[j]){
                    printf("NO\n");
                }else{
                    printf("YES\n");
                }
            }
        }
    }
}

