
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[100100];
int t[100100];
int l[100100];
int r[100100];
int max,min;
int ma,mi;
int main(){
    int n,i,p;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    max=min=a[0];
    for(i=1;i<n;i++){
        p=0;
        while(1){
            if(a[i]>max){
                t[i]=ma;
                r[ma]=i;
                ma=i;
                max=a[i];
                break;
            }else if(a[i]<min){
                t[i]=mi;
                l[mi]=i;
                mi=i;
                min=a[i];
                break;
            }else{
            if(a[i]>a[p]){
                if(r[p]){
                    p=r[p];
                }else{
                    r[p]=i;
                    t[i]=p;
                    break;
                }
            }else{
                if(l[p]){
                    p=l[p];
                }else{
                    l[p]=i;
                    t[i]=p;
                    break;
                }
            }
            }
        }
        printf("%d",a[t[i]]);
        if(i<n)printf(" "); else printf("\n");
    }
    return 0;
}

