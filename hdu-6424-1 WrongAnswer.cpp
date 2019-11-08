
#include<cstdio>
#include<algorithm>
using namespace std;
int x[5],y[5];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=0;i<a;++i)scanf("%d",&x[i]);
        for(int i=0;i<b;++i)scanf("%d",&y[i]);
        if(a==1){
            if(b==1){
                if(x[0]<y[0]){
                    printf("1\n");
                }else if(x[0]==y[0]){
                    printf("0\n");
                }else{
                    printf("-1\n");
                }
            }else if(b==2){
                if(x[0]+1<y[0]+1 && x[0]+1<y[1]){
                    printf("1\n");
                }else{
                    printf("-1\n");
                }
            }else{
                int c,d,e;
                if(y[0]+2<y[2] && y[0]+2<y[1]+1){
                    c=y[0]+2;d=1;
                }else{
                    c=y[1]+1;e=y[2];d=2;
                }
                if(d==1){
                    if(x[0]+2>c){
                        printf("1\n");
                    }else if(x[0]+2==c){
                        printf("0\n");
                    }else{
                        printf("-1\n");
                    }
                }else{
                    if(x[0]+2<c && x[0]+2<e){
                        printf("1\n");
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }else if(a==2){
            if(b==1){
                if(y[0]+1<x[0]+1 && y[0]+1<x[1]){
                    printf("-1\n");
                }else{
                    printf("1\n");
                }
            }else if(b==2){
                int c=min(x[0]+1,x[1]),d=min(y[0]+1,y[1]);
                if(c<d){
                    printf("1\n");
                }else if(c==d){
                    c=max(x[0]+1,x[1]);d=max(y[0]+1,y[1]);
                    if(c<d){
                        printf("1\n");
                    }else if(c==d){
                        printf("0\n");
                    }else{
                        printf("-1\n");
                    }
                }else{
                    printf("-1\n");
                }
            }else{
                int g=min(x[0]+2,x[1]+1);
                int c,d,e;
                if(y[0]+2<y[2] && y[0]+2<y[1]+1){
                    c=y[0]+2;d=1;
                }else{
                    c=y[1]+1;d=2;e=y[2];
                }
                if(d==1){
                    if(g<c){
                        printf("1\n");
                    }else if(g==c){
                        g=max(x[0]+2,x[1]+1);
                        c=y[1]+1;e=y[2];
                        if(g<c && g<e){
                            printf("1\n");
                        }else{
                            printf("-1\n");
                        }
                    }else{
                        printf("-1\n");
                    }
                }else{
                    if(g<c && g<e){
                        printf("1\n");
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }else{
            if(b==1){
                int c,d,e;
                if(x[0]+2<x[2] && x[0]+2<x[1]+1){
                    c=x[0]+2;d=1;
                }else{
                    c=x[1]+1;e=x[2];d=2;
                }
                if(d==1){
                    if(y[0]+2>c){
                        printf("-1\n");
                    }else if(y[0]+2==c){
                        printf("0\n");
                    }else{
                        printf("1\n");
                    }
                }else{
                    if(y[0]+2<c && y[0]+2<e){
                        printf("-1\n");
                    }else{
                        printf("1\n");
                    }
                }
            }else if(b==2){
                int g=min(y[0]+2,y[1]+1);
                int c,d,e;
                if(x[0]+2<x[2] && x[0]+2<x[1]+1){
                    c=x[0]+2;d=1;
                }else{
                    c=x[1]+1;d=2;e=x[2];
                }
                if(d==1){
                    if(g<c){
                        printf("-1\n");
                    }else if(g==c){
                        g=max(y[0]+2,y[1]+1);
                        c=x[1]+1;e=x[2];
                        if(g<c && g<e){
                            printf("-1\n");
                        }else{
                            printf("1\n");
                        }
                    }else{
                        printf("1\n");
                    }
                }else{
                    if(g<c && g<e){
                        printf("-1\n");
                    }else{
                        printf("1\n");
                    }
                }
            }else{
                int c,d,e,cc,dd,ee;
                if(x[0]+2<x[2] && x[0]+2<x[1]+1){
                    d=1;c=x[0]+2;
                }else{
                    d=2;c=x[1]+1;e=x[2];
                    if(c>e)swap(c,e);
                }
                if(y[0]+2<y[2] && y[0]+2<y[1]+1){
                    dd=1;cc=y[0]+2;
                }else{
                    dd=2;cc=y[1]+1;ee=y[2];
                    if(cc>ee)swap(cc,ee);
                }
                if(d==1 && dd==1){
                    if(c<cc){
                        printf("1\n");
                    }else if(c==cc){
                        c=x[1]+1;e=x[2];
                        if(c>e)swap(c,e);
                        cc=y[1]+1;ee=y[2];
                        if(cc>ee)swap(cc,ee);
                        if(c<cc){
                            printf("1\n");
                        }else if(c==cc){
                            if(e<ee){
                                printf("1\n");
                            }else if(e==ee){
                                printf("0\n");
                            }else{
                                printf("-1\n");
                            }
                        }else{
                            printf("-1\n");
                        }
                    }else{
                        printf("-1\n");
                    }
                }else if(d==1 && dd==2){
                    if(c<cc && c<ee){
                        printf("1\n");
                    }else{
                        printf("-1\n");
                    }
                }else if(d==2 && dd==1){
                    if(cc<c && cc<e){
                        printf("-1\n");
                    }else{
                        printf("1\n");
                    }
                }else{
                    if(c<cc){
                        printf("1\n");
                    }else if(c==cc){
                        if(e<ee){
                            printf("1\n");
                        }else if(e==ee){
                            c=x[0]+2;
                            cc=y[0]+2;
                            if(c<cc){
                                printf("1\n");
                            }else if(c==cc){
                                printf("0\n");
                            }else{
                                printf("-1\n");
                            }
                        }else{
                            printf("-1\n");
                        }
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }
    }
}

