
#include<cstdio>
#include<cstring>
char s[110][110];
char tmp[10010];
char t[110][110];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            scanf("%s",s[i]);
        }
        int tc=0;
        for(int i=0;i<2*n-1;++i){
            for(int j=0;j<=i;++j){
                if(j>=n || i-j>=n || j<0 || i-j<0)continue;
                if(i&1){
                    tmp[tc++]=s[j][i-j];
                }else{
                    tmp[tc++]=s[i-j][j];
                }
            }
        }
        memset(t,0,sizeof(t));
        int px=0,py=0,td=1;
        t[0][0]=tmp[0];
        while(1){
            while(py+1<n && t[px][py+1]==0){
                ++py;
                t[px][py]=tmp[td++];
            }
            while(px+1<n && t[px+1][py]==0){
                ++px;
                t[px][py]=tmp[td++];
            }
            while(py-1>=0 && t[px][py-1]==0){
                --py;
                t[px][py]=tmp[td++];
            }
            while(px-1>=0 && t[px-1][py]==0){
                --px;
                t[px][py]=tmp[td++];
            }
            if(td==tc)break;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                printf("%c",t[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

