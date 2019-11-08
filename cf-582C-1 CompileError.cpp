
/*
"Can\u0027t compile file:
program.cpp: In function \u0027int cmp(const void*, const void*)\u0027:
program.cpp:12:12: error: invalid conversion from \u0027const void*\u0027 to \u0027ff*\u0027 [-fpermissive]
     ff *aa\u003dx,*bb\u003dy;
            ^
program.cpp:12:18: error: invalid conversion from \u0027const void*\u0027 to \u0027ff*\u0027 [-fpermissive]
     ff *aa\u003dx,*bb\u003dy;
                  ^
"
*/
#include <stdio.h>
#include <string.h>
#include <Stdlib.h>
#include <math.h>
typedef struct ff{
    int a,i;
}ff;
ff a[200100];
int t,max,mm[200100],cm;
__int64 count,n;
int cmp(const void *x,const void *y){
    ff *aa=x,*bb=y;
    return bb->a-aa->a;
}
int f[500]={1},fc=1,is[200100]={0,1},in[400100],ss,cc[200100],ccc;
int main(){
    int i,j,k,l,ls,e,z;
    scanf("%I64d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i].a);
        a[i].i=i;
    }
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            f[fc]=i;
            is[i]=1;
            fc++;
            if(i*i<n){
                f[fc]=n/i;
                is[i]=1;
                fc++;
            }
        }
    }
    for(i=0;i<fc;i++){
        t=n/f[i];
        for(j=0;j<f[i];j++){
        //    printf("s %d %d\n",i,j);
            max=-1;
            e=j;
            for(k=0;k<t;k++){
                if(a[e].a>max){
                    cm=1;
                    max=a[e].a;
                    mm[0]=k;
                }else if(a[e].a==max){
                    mm[cm]=k;
                    cm++;
                }
                e+=f[i];
            }
            for(z=0;z<cm;z++){
           // printf("m %d %d\n",max,mm[z]);
            k=j+mm[z]*f[i];
            e=k+f[i];
            for(;k<e;k++){
                ls=k;
                for(l=1;l<t;l++){
                    ls=(ls+f[i])%n;
                   // printf("%d %d\n",ls,k);
                    if(a[ls].a>a[k%n].a)break;
                }
                if(l<t)break;
            }
            if(k>=e)count++;
            }
        }
    }
   // printf("c%d",count);
    //
    qsort(a,n,sizeof(ff),*cmp);
   // for(i=0;i<10;i++)printf("%d %d\n",a[i].a,a[i].i);
    i=0;

    while(a[i+1].a==a[i].a && i<n)i++;
  //  printf(" s %d %d",i,ss);
    for(ss=0;ss<=i;ss++)in[a[ss].i]=1;
  //  printf(" %d%d%d ",in[0],in[1],in[2]);
    for(i=0;i<n;ccc++){
        while(!in[i] && i<n){i++;/*printf("%d:",i,cc[0]);*/}
        while(in[i] && i<n){i++;cc[ccc]++;/*printf("%d %d:::",i,cc[0]);*/}
    }
    if(cc[0]==n){ccc=0;count=(n-1)*n;/*printf("!!");*/}
   // printf("%d %d!!",in[0],in[9]);
    if(in[0] && in[n-1]){cc[0]+=cc[ccc-1];ccc--;/*printf("?%d?ccc-1?",cc[ccc-1],ccc-1);*/}
    for(i=0;i<ccc;i++){
        for(j=1;j<=cc[i];j++){
            if(!is[j]){
           //     printf("%d %d %d ",j,is[j],count);
                count=count+cc[i]-j+1;
            }
        }
    }
     /*   printf("i=%d,zz=%d ",i,zz);
        ss=i;
        do{
            in[a[i].i]=zz;
            i++;
        }while(a[i+1].a==a[i].a);
        printf("i=%d\n",i);
        for(j=ss;j<i;j++){
            printf("j=%d:%d\n",j,in[a[j].i]);getchar();
            if(in[a[j].i]>zz)continue;
            next=(a[j].i+1)%n;
            pre=(a[j].i-1+n)%n;
            printf("%d %d %d %d\n",pre,next,in[pre],in[next]);
            if(!in[pre] && !in[next]){
                all++;
            }else if(in[pre]>zz && in[next]>zz){
                all--;
            }else if(!in[pre] && in[next]==zz){
                do{in[next]++;next++;if(next>=n)next-=n;}while(in[next]==zz);
                if(in[next]==0)all++;
            }else if(in[pre]==zz && !in[next]){
                do{in[pre]++;pre--;if(pre<0)pre+=n;}while(in[pre]==zz);
                if(in[pre]==0)all++;
            }else if(in[pre]==zz && in[next]>zz){
                do{in[pre]++;pre--;if(pre<0)pre+=n;}while(in[pre]==zz);
                if(in[pre]>zz)all--;
            }else if(in[pre]>zz && in[next]==zz){
                do{in[next]++;next++;if(next>=n)next-=n;}while(in[next]==zz);
                if(in[next]>zz)all--;
            }else if(in[pre]==zz && in[next]==zz){
                do{in[next]++;next++;if(next>=n)next-=n;}while(in[next]==zz);
                do{in[pre]++;pre--;if(pre<0)pre+=n;}while(in[pre]==zz);
                if(!in[pre] && !in[next]){
                    all++;
                }else if(in[pre]>zz && in [next]>zz){
                    all--;
                }
            }*/
           // if(all==1 && !is[i])count++;
           // printf("%d %d\n",all,count);
       // }
    //}
    printf("%d\n",count);
    return 0;
}

