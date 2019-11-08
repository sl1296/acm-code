
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int s[100100];
int x[10010];
int co[100100];
int main(){
    int n;
        for(int i=2;i<500;i++){
            for(int j=i*i;j<100100;j+=i){
                s[j]=1;
            }
        }
        int c=0;
        for(int i=2;i<100100;i++){
            if(s[i]==0){
                x[c]=i;
                c++;
            }
        }
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        memset(co,0,sizeof(co));
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        if(n==1){printf("1\n");continue;}
        for(int i=0;i<n;i++){
            int tmp=sqrt(a[i]);
            for(int j=0;x[j]<=tmp;j++){
                if(a[i]%x[j]==0){
                    co[x[j]]++;
                    while(a[i]%x[j]==0)a[i]/=x[j];
                }
            }
            if(a[i]>1)co[a[i]]++;
        }
        sort(co,co+100010);
        printf("%d\n",co[100009]);
    }
    return 0;
}

