
/*
0_0_21129349_30141.cpp
0_0_21129349_30141.cpp(17) : error C3861: ��__gcd��:  �Ҳ�����ʶ��
*/
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[15];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        ll ans=0;
        n--;
        for(int i=0;i<m;i++)scanf("%lld",&a[i]);
        for(int i=1;i<(1<<m);i++){
            ll cnt=1;
            int num=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    cnt=cnt*a[j]/__gcd(cnt,a[j]);
                    num++;
                }
            }
            num=num&1?1:-1;
            ans=ans+n/cnt*num;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

