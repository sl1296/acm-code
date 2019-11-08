
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long x[100010];
int len[100010];
int main(){
    int now=0;
    long long all=1;
    for(int i=1;i<100000;i++){
        if(i>99999)now+=6;
        else if(i>9999)now+=5;
        else if(i>999)now+=4;
        else if(i>99)now+=3;
        else if(i>9)now+=2;
        else now++;
        x[i]=all;
        len[i+1]=now;
        all+=now;
    }
//    for(int i=1;i<20;i++)printf("%lld ",x[i]);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int pos=upper_bound(x,x+100000,n)-x-1;
        int add=n-x[pos];
        int pp=upper_bound(len,len+100000,add)-len-1;
        int more=add-len[pp];
//        printf("%d %d %d\n",pos,pp,more);
        int tmp[20],tmpc=0;
        while(pp){
            tmp[tmpc++]=pp%10;
            pp/=10;
        }
        tmpc--;
        tmpc-=more;
        printf("%d\n",tmp[tmpc]);
    }
    return 0;
}

