
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int T[maxn],f[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--)
        scanf("%d",&T[i]);
    int k=n-1,p=1;
    f[0]=f[1]=0;
    for(int i=1;i<=n;i++){
        int j=f[i];
        if(j>0){
            int nk=n-i,np=i-j;
            if(nk+np<k+p||nk+np==k+p&&np<p){
                k=nk;p=np;
            }
        }
        while(j&&T[i]!=T[j]) j=f[j];
        f[i+1]=T[i]==T[j]?j+1:0;
    }
    printf("%d %d\n",k,p);
    return 0;
}

