
#include<cstdio>
char s[1000010];
int r[1000010];
int c[200];
int main(){
    int n,m;
    scanf("%d%d%s",&n,&m,s);
    for(int i=0;i<n;++i){
        ++c[s[i]];
        r[i+1]=c[s[i]];
    }
    while(m--){
        int q;
        scanf("%d",&q);
        printf("%d\n",r[q]);
    }
    return 0;
}

