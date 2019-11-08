
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int mid[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        ll a=0,b=0,m=0;
        for(int i=0;i<n;i++){
            int c;
            scanf("%d",&c);
            for(int i=1;i<=c;i++){
                int t;
                scanf("%d",&t);
                if(i<=c/2)a+=t;
                else if(i>c-c/2)b+=t;
                else mid[m++]=t;
            }
        }
        sort(mid,mid+m,cmp);
        for(int i=0;i<m;i++){
            if(i%2==0)a+=mid[i];else b+=mid[i];
        }
        printf("%lld %lld\n",a,b);
    }
    return 0;
}

