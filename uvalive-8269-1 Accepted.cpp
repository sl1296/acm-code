
#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
int w[maxn],a[maxn];
struct node{
    int id,d;
    bool operator <(const node &rhs)const{
        return d<rhs.d||d==rhs.d&&id<rhs.id;
    }
};
set<node> st;
set<node>::iterator it;
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int l=0,r=2000000000;
        while(l<r){
            int mid=((long long)l+r)/2;
            st.clear();
            for(int i=0;i<n;i++)
                st.insert((node){i,a[i]});
            for(int i=0;i<n;i++){
                bool flag=false;
                while(!st.empty()){
                    it=--st.end();
                    node e=*it;
                    if(w[i]*(a[i]+e.d)>mid){
                        st.erase(it);
                        if(e.id==i) flag=true;
                    }else break;
                }
                if(flag) st.insert((node){i,a[i]});
            }

            if(st.size()<k) l=mid+1;
            else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
/*
1
3 2
5 1 10
5 9 9
*/

