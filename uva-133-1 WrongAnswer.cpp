
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
vector<int> ve;
int main(){
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m),n+k+m){
        ve.clear();
        for(int i=1;i<=n;i++)ve.push_back(i);
        int p=-1,q=n;
        int cas=0;
        while(ve.size()){
            p=(p+k)%ve.size();
            q=((q-m)%ve.size()+ve.size())%ve.size();
            if(cas)printf(",");
            cas++;
            if(p==q){
                printf("%3d",ve[p]);
                ve.erase(ve.begin()+p);
                p--;
            }else{
                printf("%3d%3d",ve[p],ve[q]);
                ve.erase(ve.begin()+p);
                if(p<q)q--;
                p--;
                ve.erase(ve.begin()+q);
                if(q<p)p--;
            }
        }
        printf("\n");
    }
    return 0;
}

