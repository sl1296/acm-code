
#include<cstdio>
#include<cstring>
int cc[5];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(cc,0,sizeof(cc));
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            cc[a]++;
        }
        int ans=cc[4]+cc[3]+(cc[2]+1)/2;
        cc[1]-=cc[3];
        if(cc[2]&1)cc[1]-=2;
        if(cc[1]>0)ans+=(cc[1]+3)/4;
        printf("%d\n",ans);
    }
    return 0;
}

