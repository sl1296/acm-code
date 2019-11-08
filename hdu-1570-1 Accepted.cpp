
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[5];
        int n,m;
        scanf("%s%d%d",c,&n,&m);
        int ans=1;
        if(c[0]=='A'){
            for(int i=0;i<m;i++)ans*=(n-i);
        }else{
            for(int i=1;i<=m;i++)ans=ans*(n-i+1)/i;
        }
        printf("%d\n",ans);
    }
    return 0;
}

