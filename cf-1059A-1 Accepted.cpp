
#include<cstdio>
int main()
{
    int n,l,a,pre=0,ans=0;
    scanf("%d%d%d",&n,&l,&a);
    for(int i=0;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        ans+=(x-pre)/a;
        pre=x+y;
    }
    ans+=(l-pre)/a;
    printf("%d\n",ans);
    return 0;
}

