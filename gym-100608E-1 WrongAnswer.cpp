
#include<cstdio>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
ll ans[35][35][35];
const int maxn=10000;
int isp[maxn] ;
int prime[maxn];
int c;
void init(){
    //memset(isp,0,sizeof(isp));
    for(int i=1;i<maxn;i++){
        isp[i]=1 ;
    }
    isp[0]=0 ;
    isp[1]=0 ;
    //isp[2]=1 ;
    for(int i=2;i*i<maxn;i++){
        if(isp[i]){
            for(int j=2;i*j<maxn;j++){
                isp[i*j]=0 ;
            }
        }
    }
    for(int i=1;i<maxn;i++){
        //printf("i=%d %d\n",i,isp[i]);
        if(isp[i]){
            prime[c++] = i ;
        }
    }
}
ll pre[35];
ll make1[35][35];
ll make2[35][35];
ll make3[35][35];
ll p4[35][35]={
    {1,11*13,5*7,2*3},
    {7*13,2,3,5*11},
    {3*11,5,2*13,7},
    {2*5,3*7,11,13}
};
int used[50];
int main(){
    init();
   /* printf("c=%d\n",c);
    for(int i=0;i<c;i++){
        printf("%d ",prime[i]);
    }*/

  //  int use=6;
    int use;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ans[4][i][j]=p4[i][j];
        }
    }
    used[4]=6;
    for(int n=3;n<31;n++){
        if(n==4)continue;
        if(n&1){
            use=0;
            for(int i=0;i<n;i++)pre[i]=prime[use++];
            for(int i=0;i<n;i++){
                for(int j=i,k=0;k<n;k++,j=(j+1)%n){
                    make1[i][j]=pre[k];
                }
            }
            for(int i=0;i<n;i++)pre[i]=prime[use++];
            for(int i=0;i<n;i++){
                for(int j=(n-i)%n,k=0;k<n;k++,j=(j+1)%n){
                    make2[i][j]=pre[k];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ans[n][i][j]=make1[i][j]*make2[i][j];
                }
            }
            used[n]=use;
        }else{
            int di=2;
            if(n%4==0&&n/4>=3)di=4;
            if(n%8==0&&n/8>=3)di=8;
            if(n%16==0&&n/16>=3)di=16;
            use=used[n/di];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    make1[i][j]=ans[n/di][i/di][j/di];
                }
            }
            for(int i=0;i<n;i++)pre[i]=prime[use++];
            for(int i=0;i<n;i++){
                for(int j=i,k=0;k<n;k++,j=(j+1)%n){
                    make2[i][j]=pre[k];
                }
            }
            for(int i=0;i<n;i++)pre[i]=prime[use++];
            for(int i=0;i<n;i++){
                for(int j=(n-i)%n,k=0;k<n;k++,j=(j+1)%n){
                    make3[i][j]=pre[k];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ans[n][i][j]=make1[i][j]*make2[i][j]*make3[i][j];
                }
            }
            used[n]=use;
        }
    }
    /*    for(int i=3;i<31;i++){
            printf("i=%d\n",i);
            map<ll,int> ma;
            for(int j=0;j<i;j++){
                for(int k=0;k<i;k++){
                  //  printf("%lld ",ans[i][j][k]);
                    if(ma[ans[i][j][k]])printf("eer");
                    ma[ans[i][j][k]]=1;
                }
           //     printf("\n");
            }
         //   printf("\n");
        }*/

        int nn;
    while(cin>>nn){
        for(int i=0;i<nn;i++){
            for(int j=0;j<nn;j++){
                if(j)cout<<' ';
                cout<<ans[nn][i][j];
            }
            cout<<endl;
        }
    }
}

