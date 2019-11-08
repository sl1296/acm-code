
#include <stdio.h>
char x[5010],y[5010];
int n;
int fx(){
    int *pre,*next,*t,i,j,dp[2][5010];
    pre=dp[0];next=dp[1];
    for(i=0;i<n;i++){
        next[0]=0;
        for(j=0;j<n;j++){
            if(x[i]==y[j])next[j+1]=pre[j]+1;
            else next[j+1]=pre[j+1]>next[j]?pre[j+1]:next[j];
        }
        t=pre;pre=next;next=t;
    }
    return pre[n];
}
int main(){
    int i;
    scanf("%d%s",&n,x);
    for(i=0;i<n;i++)y[i]=x[n-i-1];
    printf("%d\n",n-fx());
    return 0;
}

