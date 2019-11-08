
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
double h[1010];
int num[1010],cnt;
int main(){
    int m,n;
    int cas=1;
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0)break;
        int cc=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[cc++]);
            }
        }
        sort(a,a+cc);
        cnt=0;
        int xx=0;
        for(int i=0;i<cc;i++){
            xx++;
            while(i+1<cc&&a[i]==a[i+1]){
                i++;
                xx++;
            }
            num[cnt]=xx;
            h[cnt++]=a[i];
        }
        bool is=false;
        double ans,an,v;
        scanf("%lf",&v);
        for(int i=1;i<cnt;i++){
            double need=(h[i]-h[i-1])*num[i-1]*100;
            if(v>need)v-=need;
            else{
                an=num[i-1];
                ans=h[i-1]+v/100/num[i-1];
                is=true;
                break;
            }
        }
        if(v==0){
            an=ans=0;
        }
        if(!is){
            ans=h[cnt-1]+v/100/cc;
            an=cc;
        }
        printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n",cas++,ans,an*100/cc);
    }
    return 0;
}

