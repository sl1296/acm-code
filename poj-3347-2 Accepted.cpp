
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[55],pos[55];
int ans[55],ansc;
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        pos[0]=a[0];
        int pre=a[0];
        for(int i=1;i<n;i++){
            pos[i]=0;
            for(int j=0;j<i;j++){
                pos[i]=max(pos[i],pos[j]+min(a[j],a[i])*2);
            }
        }
        ansc=0;
        for(int i=0;i<n;i++){
            int left=pos[i]-a[i],right=pos[i]+a[i];
            for(int j=0;j<i;j++){
                left=max(left,pos[j]+a[j]);
            }
            for(int j=i+1;j<n;j++){
                right=min(right,pos[j]-a[j]);
            }
            if(left<right)ans[ansc++]=i+1;
        }
        for(int i=0;i<ansc;i++){
            if(i)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

