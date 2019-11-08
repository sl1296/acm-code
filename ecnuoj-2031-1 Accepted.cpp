
#include<cstdio>
int a[110];
int abs(int x){
    return x>0?x:-x;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(a[i])>abs(a[j])){
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}

