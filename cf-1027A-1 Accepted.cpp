
#include<cstdio>
char s[1010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d%s",&n,s);
        int nn=n/2;
        bool ans=true;
        for(int i=0;i<nn;++i){
            int tmp=s[i]-s[n-i-1];
            if(tmp!=0&&tmp!=2&&tmp!=-2){
                ans=false;
                break;
            }
        }
        if(ans)printf("YES\n");else printf("NO\n");
    }
    return 0;
}

