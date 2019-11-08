
#include<bits/stdc++.h>
using namespace std;
char s[55][55];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=99999999;
        for(int i=0;i<n;i++)scanf("%s",s[i]);
        int len=strlen(s[0]);
        for(int i=1;i<n;i++)if(strlen(s[i])!=len)ans=-1;
        if(ans==-1){
            printf("-1\n");continue;
        }
        for(int i=0;i<n;i++){
            int re=0;
            for(int j=0;j<n;j++){
            //    printf("%d %d\n",i,j);
                bool is=false;
                if(j==i)continue;
                for(int ps=0;ps<len;ps++){
                    int p=ps;
                    int k;
                    for(k=0;k<len;k++){
                        if(s[i][k]!=s[j][p])break;
                        p++;
                        if(p==len)p=0;
                    }
                //    printf("ps=%d k=%d\n",ps,k);
                    if(k==len){
                        re+=ps;
                        is=true;
                        break;
                    }
                }
                if(is==false){
                    ans=-1;
                    break;
                }
            }
            if(ans==-1)break;
            ans=min(ans,re);
        }
        printf("%d\n",ans);
    }
    return 0;
}

