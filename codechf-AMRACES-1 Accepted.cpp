
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define maxn 505
int ans[maxn];
int dp[21][maxn][maxn];
vector<int> vec[maxn];
vector<int> tmp;
void dfs(int pre,int k,int s,int sum){
    if(dp[pre][k][s]<sum) return;
    dp[pre][k][s]=sum;
    for(int i=pre;i<=20;i++){
        if(k+s*i>500) break;
        tmp.push_back(i);
        if(ans[k+s*i]>sum+1+i){
            ans[k+s*i]=sum+1+i;
            vec[k+s*i]=tmp;
        }
        dfs(i,k+s*i,s+i,sum+1+i);
        tmp.erase(--tmp.end());
    }
}
int main(){
    memset(ans,inf,sizeof(ans));
    memset(dp,inf,sizeof(dp));
    for(int i=1;i<=20;i++){
        tmp.clear();
        tmp.push_back(i);
        dfs(i,0,i,2+i);
    }
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int k;
        scanf("%d",&k);
        if(k==1){
            printf("2\n1 2\n");
            continue;
        }
        int i,res=ans[k];
        for(i=2;;i++)
            if(i*(i-1)/2>=k) break;
        int ty=3,a,b;
        if(i*(i-1)/2==k&&res>i+1){
            res=i+1;
            ty=1;
            a=i;
        }
        for(i=1;i<k;i++){
            if(k%i==0&&i+2+k/i<res){
                res=i+2+k/i;
                a=i;b=k/i;
                ty=2;
            }
        }
        if(ty==1){
            printf("%d\n",res);
            for(i=1;i<=a;i++)
                printf("%d %d\n",1,i+1);
        }else if(ty==2){
            printf("%d\n",res);
            printf("%d %d\n",1,2);
            for(int i=1;i<=a;i++)
                printf("%d %d\n",1,i+2);
            for(int i=1;i<=b;i++)
                printf("%d %d\n",2,i+a+2);
        }else{
            printf("%d\n",res);
            int id=1;
            for(int i=1;i<=vec[k].size();i++)
                printf("%d %d\n",1,++id);
            for(int i=0;i<vec[k].size();i++){
                for(int j=0;j<vec[k][i];j++)
                    printf("%d %d\n",i+2,++id);
            }
        }
    }
    return 0;
}

