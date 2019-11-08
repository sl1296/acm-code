
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[100100];
int t[100100];
int l[100100];
int r[100100];
int c[100100];
int max,min;
int ma,mi;
int count;
int e[30];
int cmax[30];
int cmin[30];
int main(){
    int n,i,p,p2,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    max=min=a[0];
    for(i=1;i<n;i++){
            if(a[i]>max){
                t[i]=ma;
                r[ma]=i;
                c[i]=c[ma]+1;
                ma=i;
                max=a[i];
            }else if(a[i]<min){
                t[i]=mi;
                l[mi]=i;
                c[i]=c[mi]+1;
                mi=i;
                min=a[i];
            }else{
        p=0;
            if(count){
                for(j=count-1;j>-1;j--){
                    if(a[i]>cmin[j] && a[i]<=cmax[j]){
                        p=e[j];
                        break;
                    }
                }
            }
        while(1){
        //    printf("p%d",p);getchar();
            if(a[i]>a[p]){
                if(r[p]){
                    p=r[p];
                }else{
                    r[p]=i;
                    t[i]=p;
                    c[i]=c[p]+1;
                    break;
                }
            }else{
                if(l[p]){
                    p=l[p];
                }else{
                    l[p]=i;
                    t[i]=p;
                    c[i]=c[p]+1;
                    break;
                }
            }
        }
        }
        printf("%d",a[t[i]]);
        if(i<n)printf(" "); else printf("\n");
        if(c[i]%9000==0){
            e[count]=i;
            cmax[count]=100000010;
            cmin[count]=-1;
            p=i;
            while(p){
                p2=p;
             //   printf("%d",p);getchar();
                p=t[p];
                if(l[p]==p2){
                    if(cmax[count]>a[p])cmax[count]=a[p];
                }else{
                    if(cmin[count]<a[p])cmin[count]=a[p];
                }
            }
            count++;
        }
    }
    return 0;
}

