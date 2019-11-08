
#include<cstdio>
int a[1000010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        if(i&&a[i]==a[i-1]){
            i--;
            n--;
        }
    }
    int ans=0;
    for(int i=1;i<n-1;++i){
        if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
    }
    printf("%d\n",ans);
    return 0;
}

