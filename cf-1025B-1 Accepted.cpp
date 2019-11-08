
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[150010],b[150010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i],&b[i]);
    }
    vector<int> ve;
    for(int i=2;i*i<=a[0];++i){
        if(a[0]%i==0){
            ve.push_back(i);
            while(a[0]%i==0)a[0]/=i;
        }
    }
    if(a[0]>1)ve.push_back(a[0]);
    for(int i=2;i*i<=b[0];++i){
        if(b[0]%i==0){
            ve.push_back(i);
            while(b[0]%i==0)b[0]/=i;
        }
    }
    if(b[0]>1)ve.push_back(b[0]);
    sort(ve.begin(),ve.end());
    int sz=unique(ve.begin(),ve.end())-ve.begin();
    ve.resize(sz);
    for(int i=1;i<n;++i){
        for(int j=ve.size()-1;j>=0;--j){
            if(a[i]%ve[j]!=0&& b[i]%ve[j]!=0){
                ve.erase(ve.begin()+j);
            }
        }
    }
    if(ve.size()>0){
        printf("%d\n",ve[0]);
    }else{
        printf("-1\n");
    }
    return 0;
}

