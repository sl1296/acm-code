
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
char get(){
    char s=getchar();
    printf("s=%d\n",s);
    return s;
}
inline bool rea(int & x)
{
    char c=getchar();x=0;
    if(c==EOF)return false;
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=getchar());
    return true;
}
int a[50010],n,ans[50010],m,t;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))a[i]+=v;
}
int query(int x){
    int re=0;
    for(int i=x;i>0;i=i-lowbit(i))re+=a[i];
    return re;
}
int main(){
   // freopen("1.txt","r",stdin);
    while(rea(n)){
     //   printf("n=%d\n",n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)update(i,1);
        for(int i=0;i<n;i++){
            rea(t);
            int l=1,r=n;
            while(r>l){
                int m=l+(r-l)/2;
                int re=query(m);
                if(re>t){
                    r=m-1;
                }else if(re<t){
                    l=m+1;
                }else{
                    r=m;
                }
            }
            update(l,-1);
            ans[i+1]=l;
        }
        rea(m);
        for(int i=0;i<m;i++){
            rea(t);
            if(i)printf(" ");
            printf("%d",ans[t]);
        }
        printf("\n");
    }
    return 0;
}

