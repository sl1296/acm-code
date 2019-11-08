
/*
Main.cc: In function 'void dfs(int, int, int)':
Main.cc:18: error: '__int64' was not declared in this scope
Main.cc:18: error: expected ';' before 'j'
Main.cc:29: error: 'j' was not declared in this scope
Main.cc:29: error: 'sum' was not declared in this scope
Main.cc: In function 'int main()':
Main.cc:33: warning: unused variable 'sum'
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int zs[45000],zsn;
int a[45000],an;
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
bool judge(int x){
    int i;
    if(x==1)return false;
    for(i=0;zs[i]*zs[i]<=x;i++)if(x%zs[i]==0)return false;
    return true;
}
void dfs(int now,int pos,int rest){
    int i;
    __int64 j,sum;
    if(rest==1){
        a[an]=now;
        an++;
        return;
    }
    if(rest-1>=zs[pos] && judge(rest-1)){
        a[an]=(rest-1)*now;
        an++;
    }
    for(i=pos;zs[i]*zs[i]<=rest;i++)
        for(j=zs[i],sum=j+1;sum<=rest;j*=zs[i],sum+=j)
            if(rest%sum==0)dfs(now*j,i+1,rest/sum);
}
int main(){
    int k,sum,i,j;
    for(i=2;i<45000;i++){
        if(!zs[i]){
            for(j=i+i;j<45000;j+=i)zs[j]=1;
            zs[zsn]=i;
            zsn++;
        }
    }
    while(scanf("%d",&k)!=EOF){
        an=0;
        dfs(1,0,k);
        qsort(a,an,sizeof(int),*cmp);
        printf("%d\n",an);
        for(i=0;i<an;i++){
            printf("%d",a[i]);
            if(i<an-1)printf(" ");
        }
        if(an)printf("\n");
    }
    return 0;
}

