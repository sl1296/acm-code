
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ll{
int a,b;
char c[3];
}ll;
ll tt[1100];
ll ls[1100];
int cmp(const void *a,const void *b){
    ll *x,*y;
    x=(ll*)a;
    y=(ll*)b;
    if(x->c[0]!=y->c[0]){
        return y->c[0]-x->c[0];
    }else{
        if(x->c[0]=='B'){
            return y->a-x->a;
        }else{
            return x->a-y->a;
        }
    }
}
int main(){
    int n,s,i,cc,d=0;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++)scanf("%s%d%d",tt[i].c,&tt[i].a,&tt[i].b);
    qsort(tt,n,sizeof(ll),*cmp);
    cc=0;
    for(i=0;;){
        if(tt[i].c[0]=='B')break;
        while(tt[i+1].c[0]==tt[i].c[0] && tt[i+1].a==tt[i].a){
            tt[i+1].b+=tt[i].b;
            i++;
        }
        strcpy(ls[d].c,tt[i].c);
        ls[d].a=tt[i].a;
        ls[d].b=tt[i].b;
        d++;
        cc++;
        if(cc==s || tt[i+1].c[0]=='B')break;
        if(tt[i+1].c[0]=='S')i++;

    }
    for(d=d-1;d>-1;d--){
        printf("%s %d %d\n",ls[d].c,ls[d].a,ls[d].b);
    }
    while(tt[i].c[0]=='S')i++;
    cc=0;
    for(;;){
        while(tt[i+1].c[0]==tt[i].c[0] && tt[i+1].a==tt[i].a && i<n-1){
            tt[i+1].b+=tt[i].b;
            i++;
        }
        printf("%s %d %d\n",tt[i].c,tt[i].a,tt[i].b);
        cc++;
        if(cc==s || i>n-2)break;
        if(i<n-1)i++;
    }
    return 0;
}

