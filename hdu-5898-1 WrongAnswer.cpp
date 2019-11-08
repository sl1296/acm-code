
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ull unsigned long long
using namespace std;
int dig[25];
bool odd[25];
ull ans;
void dfs(int know,int n,int p,bool last,int lastc){
   // printf("Dfs:%d %d %d %d %d\n",know,n,p,last,lastc);
    int i;
    if(know==n){
        bool zt=odd[n-1];
        int c=1;
        for(i=n-2;i>-1;i--){
            if(odd[i]==zt){
                c++;
            }else{
                if((zt==true && c%2==0) || (zt==false && c%2==1))return;
                zt=odd[i];
                c=1;
            }
        }
        if((zt==true && c%2==0) || (zt==false && c%2==1))return;
        ans++;
        return;
    }
    if(p==-1){
        int xx=1;
        if((last==true && lastc%2==1) || (last==false && lastc%2==0)){
            for(int y=0;y<n-know;y++)xx*=5;
            if(know==0 && odd[n-1]==true)xx=xx/5*4;
            ans+=xx;
        }
        return;
    }
    if(p==n-know-1){
        if(know>0){
            bool zt=odd[n-1];
            int c=1;
            for(i=n-2;i>p;i--){
                if(odd[i]==zt){
                    c++;
                }else{
                    if((zt==true && c%2==0) || (zt==false && c%2==1))return;
                    zt=odd[i];
                    c=1;
                }
            }
            odd[p]=zt;
            dfs(know,n,p-1,zt,c+1);
            if(zt==true && c%2==1){
                odd[p]=false;
                dfs(know,n,p-1,false,1);
            }else if(zt==false && c%2==0){
                odd[p]=true;
                dfs(know,n,p-1,true,1);
            }
            return;
        }else{
            odd[p]=false;
            dfs(know,n,p-1,false,1);
            odd[p]=true;
            dfs(know,n,p-1,true,1);
            return;
        }
    }
    odd[p]=last;
    dfs(know,n,p-1,last,lastc+1);
    if(last==true && lastc%2==1){
        odd[p]=false;
        dfs(know,n,p-1,false,1);
    }else if(last==false && lastc%2==0){
        odd[p]=true;
        dfs(know,n,p-1,true,1);
    }
}
ull cal(ull x){
    int i,j,n=0;
    ull xx=x,r=0;
    while(xx){
        dig[n]=xx%10;
        xx/=10;
        n++;
    }
    for(i=1;i<n;i++){
        ans=0;
        dfs(0,i,i-1,0,0);
        r+=ans;
      //  printf("ans=%d\n",ans);
    }
    for(i=n-1;i>-1;i--){
        for(j=0;j<=dig[i];j++){
            if(i==n-1 && j==0)continue;
            odd[i]=(j%2==0);
            if(i && j==dig[i])break;
            ans=0;
            dfs(n-i,n,i-1,0,0);
            r+=ans;
       //     printf("ans=%d\n",ans);
        }
    }
    return r;
}
int main(){
    int t,z;
    ull l,r;
    scanf("%d",&t);
    for(z=1;z<=t;z++){
        scanf("%I64u%I64u",&l,&r);
        printf("Case #%d: %I64u\n",z,cal(r)-cal(l-1));
    }
    return 0;
}

