
#include<bits/stdc++.h>
using namespace std;
#define maxn 50
const double eps=1e-6;
double a[maxn][maxn],x[maxn];
int equ,var;
int Gauss(){
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++){
        max_r = k;
        for(i=k+1;i<equ;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r = i;
        if(fabs(a[max_r][col])<eps) return 0; //无解,有自由变元
        if(k != max_r){
            for(j=col;j<var;j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col] = 1;
        for(i=0;i<equ;i++)
            if(i!=k){
                x[i] -= x[k]*a[i][k];
                for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
                a[i][col]=0;
            }
    }
    return 1;
}
vector<int> ans;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&equ);
		var=equ;
        for(int i=0;i<equ;i++){
            for(int j=0;j<var;j++){
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

