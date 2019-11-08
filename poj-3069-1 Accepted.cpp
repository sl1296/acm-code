
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
int main(){
    int r,n;
    while(1){
        scanf("%d%d",&r,&n);
        if(r==-1&&n==-1)break;
        int cnt=0;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++){
            int s=i;
            while(i+1<n&&a[i+1]-a[s]<=r)i++;
            cnt++;
            s=i;
            while(i+1<n&&a[i+1]-a[s]<=r)i++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

