
#include<bits/stdc++.h>
using namespace std;
double a[50][50],x[50];
int n;
vector<int> ans;
int Gauss(){
    int i,j,k,col,max_r;
    for(k=0,col=0;k<n&&col<n;k++,col++){
        max_r = k;
        for(i=k+1;i<n;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r = i;
        if(fabs(a[max_r][col])<1e-6) return 0; //无解,有自由变元
        if(k != max_r){
            for(j=col;j<n;j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<n;j++)a[k][j]/=a[k][col];
        a[k][col] = 1;
        for(i=0;i<n;i++)
            if(i!=k){
                x[i] -= x[k]*a[i][k];
                for(j=col+1;j<n;j++)a[i][j]-=a[k][j]*a[i][col];
                a[i][col]=0;
            }
    }
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lf",&a[i][j]);
            }
            a[i][i]-=1;
        }
        if(Gauss())ans.push_back(0);
        else ans.push_back(1);
    }
    for(int i=0;i<ans.size();i++){
        printf("%d%c",ans[i],(i%5==4||i==ans.size()-1)?'\n':' ');
    }
    return 0;
}

