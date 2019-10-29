
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    set<int> s;
    scanf("%d",&n);
    bool hv=false;
    int mi=0;
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(hv || a<mi){
            printf("NO\n");
        }else if(a==mi){
            if(s.size()==mi){
                hv=true;
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else{
            while(1){
                auto x=s.find(a);
                if(x!=s.end())s.erase(x);
                else break;
                --a;
            }
//            printf("a=%d\n",a);
            s.insert(a);
            if(a==mi+1){
                mi=a;
                while(s.count(mi+1))++mi;
            }
            else if(a==0)hv=true;
            printf("YES\n");
        }
//        for(auto i:s){
//            printf("%d ",i);
//        }
//        printf("\n");
    }
    return 0;
}

