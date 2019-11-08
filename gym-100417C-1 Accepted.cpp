
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 105
int a[maxn],b[maxn];
multiset<ll> st;
multiset<ll>::iterator it;
int main(){
    freopen("budget.in","r",stdin);
    freopen("budget.out","w",stdout);
    int m,n,p;
    while(scanf("%d%d%d",&m,&n,&p)!=EOF){
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            a[i]=p/a[i]+(p%a[i]?1:0);
        }
        sort(a,a+m,greater<int>());
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        ll l=1,r=1e12;
        while(l<r){
            ll mid=(l+r)/2;
//            printf("%lld\n",mid);
            st.clear();
            for(int i=0;i<n;i++)
                st.insert(b[i]);
            for(int i=0;i<m;i++){
                ll en=mid;
                while(true){
                    it=st.upper_bound(en-a[i]+1);
                    if(it==st.begin()) break;
//                    printf("%d : %d\n",i,*(--it));
                    st.erase(--it);
                    en-=a[i];
                }
            }
            if(st.empty()) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}

