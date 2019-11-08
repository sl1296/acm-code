
#include <bits/stdc++.h>
using namespace std;
inline void print(__int128 x){
    if(x<0){
        printf("-");
        x=-x;
    }
    if(x>9)print(x/10);
    printf("%c",x%10+'0');
}
__int128 xc[200010],yc[200010];
__int128 xs[200010],ys[200010];
__int128 addx,addy;
map<pair<int,int>,bool> ma;
int main(){
    addx=addy=0;
    int n,k,q,x,y;
    scanf("%d%d%d",&n,&k,&q);
    __int128 all=n*2-1,ans=all*all*n*n;
    for(int i=1;i<=n;++i){
        xc[i]=yc[i]=n;
        xs[i]=ys[i]=all*n;
    }
    while(k--){
        scanf("%d%d",&x,&y);
        __int128 cp=xc[x]+yc[y]-1;
        ans=ans-2*(xs[x]+addx+ys[y]+addy-cp)+all;
        ma[make_pair(x,y)]=true;
        --xc[x];--yc[y];
        xs[x]-=n-1;ys[y]-=n-1;
        --addx;--addy;
    }
    print(ans);
    printf("\n");
    while(q--){
        scanf("%d%d",&x,&y);
        if(!ma[make_pair(x,y)]){
            __int128 cp=xc[x]+yc[y]-1;
            ans=ans-2*(xs[x]+addx+ys[y]+addy-cp)+all;
            ma[make_pair(x,y)]=true;
            --xc[x];--yc[y];
            xs[x]-=n-1;ys[y]-=n-1;
            --addx;--addy;
        }else{
            __int128 cp=xc[x]+yc[y];
            ans=ans+2*(xs[x]+addx+ys[y]+addy-cp)+all;
            ma[make_pair(x,y)]=false;
            ++xc[x];++yc[y];
            xs[x]+=n-1;ys[y]+=n-1;
            ++addx;++addy;
        }
        print(ans);
        printf("\n");
    }
    return 0;
}

