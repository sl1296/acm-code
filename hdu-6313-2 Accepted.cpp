
#include<bits/stdc++.h>
using namespace std;
int a[3000][3000];
int x[3000][3000];
int pre[3000][3000];
int main(){
    int cnt=0;
    for(int i=1;i<47;i++){
        for(int s=0;s<47;s++){
            int tt=s;
            bool check[100]={false};
            for(int n=0;n<47;n++){
                a[cnt][n*47+tt]=1;
//                printf("%d %d\n",cnt,n*46+tt);
                check[tt]=true;
                tt+=i;
                if(tt>=47)tt-=47;
            }
            for(int xx=0;xx<47;xx++){
                if(!check[xx]){
                    printf("check:i=%d s=%d xx=%d\n",i,s,xx);
                }
            }
            cnt++;
        }
    }
//    printf("%d\n",cnt);
    printf("2000\n");
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
//    int cc=0;
//    for(int i=0;i<2000;i++){
//        for(int j=0;j<2000;j++){
//            if(a[i][j]==1){
//                cc++;
//                for(int k=i+1;k<2000;k++){
//                    if(a[k][j]==1){
//                        ++x[min(k,i)][max(k,i)];
//                        if(x[min(k,i)][max(k,i)]>1){
//                            printf("%d %d %d %d\n",k,i,j,pre[min(k,i)][max(k,i)]);
//                        }
//                            pre[min(k,i)][max(k,i)]=j;
//                    }
//                }
//            }
//        }
//    }
//    printf("cc=%d\n",cc);
    return 0;
}

