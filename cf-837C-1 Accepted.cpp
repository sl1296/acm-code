
#include<cstdio>
#include<algorithm>
using namespace std;
int u[110],v[110];
int main(){
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b)){
        if(a<b)swap(a,b);
        for(int i=0;i<n;i++){
            scanf("%d%d",&u[i],&v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool is=false;
                int t1=u[i]+u[j];
                int t2=max(v[i],v[j]);
                if(max(t1,t2)<=a&&min(t1,t2)<=b)is=true;
                t1=u[i]+v[j];
                t2=max(v[i],u[j]);
                if(max(t1,t2)<=a&&min(t1,t2)<=b)is=true;
                t1=v[i]+v[j];
                t2=max(u[i],u[j]);
                if(max(t1,t2)<=a&&min(t1,t2)<=b)is=true;
                t1=v[i]+u[j];
                t2=max(u[i],v[j]);
                if(max(t1,t2)<=a&&min(t1,t2)<=b)is=true;
                if(is){
                    ans=max(ans,u[i]*v[i]+u[j]*v[j]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

