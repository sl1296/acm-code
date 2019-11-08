
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int gt(char* s){
    if(s[0]=='M')return 0;
    if(s[2]=='E')return 1;
    if(s[0]=='W')return 2;
    if(s[1]=='H')return 3;
    if(s[0]=='F')return 4;
    if(s[1]=='A')return 5;
    return 6;
}
int a[500][500];
int x[500];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int exgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    int q=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
int inv(int a,int n) {
	int x,y;
	int d=exgcd(a,n,x,y);
	if(d==1) return (x%n+n)%n;
	else return -1;
}
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
    }
    int col=0,k;
    for(k=0;k<equ&&col<var;k++,col++){
        int mr=0;
        for(int i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[mr][col]))mr=i;
        }
        if(mr!=k){
            for(int i=col;i<=var;i++)swap(a[mr][i],a[k][i]);
        }
        if(a[k][col]==0){
            k--;
            continue;
        }
        for(int i=k+1;i<equ;i++){
            if(a[i][col]){
                int LCM=lcm(abs(a[i][col]),abs(a[k][col]));
                int ta=LCM/abs(a[i][col]);
                int tb=LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0)tb=-tb;
                for(int j=col;j<=var;j++){
                    a[i][j]=a[i][j]*ta-a[k][j]*tb;
                    a[i][j]=(a[i][j]%7+7)%7;
                }
            }
        }
    }
    for(int i=k;i<equ;i++){
        if(a[i][col])return -1;
    }
    if(k<var)return var-k;
    for(int i=var-1;i>=0;i--){
        x[i]=a[i][var];
        for(int j=i+1;j<var;j++){
            x[i]-=x[j]*a[i][j]%7;
            x[i]%=7;
        }
        x[i]=(x[i]*inv(a[i][i],7)%7+7)%7;
        if(x[i]<3)x[i]+=7;
    }
    return 0;
}
int main(){
    int n,m;
    while(1){
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++){
            int k;
            char s1[10],s2[10];
            scanf("%d%s%s",&k,s1,s2);
            int x=gt(s1);
            int y=gt(s2);
            a[i][n]=(y-x+1+7)%7;
            for(int j=0;j<k;j++){
                int w;
                scanf("%d",&w);
                a[i][w-1]=(a[i][w-1]+1)%7;
            }
        }
        int ans=Gauss(m,n);
        if(ans==-1){
            printf("Inconsistent data.\n");
        }else if(ans){
            printf("Multiple solutions.\n");
        }else{
            for(int i=0;i<n;i++){
                if(i)printf(" ");
                printf("%d",x[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

