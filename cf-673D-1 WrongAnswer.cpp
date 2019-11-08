
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,a,b,c,d;
    while(scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d)!=EOF){
        int cnt=0;
        for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=c && i!=d)cnt++;
        if(a==c && b==c){
            if(k<n)printf("-1\n");
            else{
                printf("%d",a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b)printf(" %d",i);
                printf(" %d\n%d",b,a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b)printf(" %d",i);
                printf(" %d\n",b);
            }
        }else if(a==d && b==c){
            if(k<n)printf("-1\n");
            else{
                printf("%d",a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b)printf(" %d",i);
                printf(" %d\n%d",b,b);
                for(int i=n;i>0;i--)if(i!=a && i!=b)printf(" %d",i);
                printf(" %d\n",a);
            }
        }else if(a==c){
            if(k<=n || cnt==0)printf("-1\n");
            else{
                printf("%d",a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=d)printf(" %d",i);
                printf(" %d %d\n%d",d,b,a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=d)printf(" %d",i);
                printf(" %d %d\n",b,d);
            }
        }else if(a==d){
            if(k<=n || cnt==0)printf("-1\n");
            else{
                printf("%d",a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=c)printf(" %d",i);
                printf(" %d %d\n%d %d",c,b,c,b);
                for(int i=n;i>0;i--)if(i!=a && i!=b && i!=c)printf(" %d",i);
                printf(" %d\n",a);
            }
        }else if(b==c){
            if(k<=n || cnt==0)printf("-1\n");
            else{
                printf("%d %d",a,d);
                for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=d)printf(" %d",i);
                printf(" %d\n%d",b,b);
                for(int i=n;i>0;i--)if(i!=a && i!=b && i!=d)printf(" %d",i);
                printf(" %d %d\n",a,d);
            }
        }else if(b==d){
            if(k<=n || cnt==0)printf("-1\n");
            else{
                printf("%d %d",a,c);
                for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=c)printf(" %d",i);
                printf(" %d\n%d %d",b,c,a);
                for(int i=1;i<=n;i++)if(i!=a && i!=b && i!=c)printf(" %d",i);
                printf(" %d\n",b);
            }
        }else{
            if(k<n+2 || cnt==0)printf("-1\n");
            else{
                int p;
                printf("%d %d",a,c);
                for(p=1;p<=n;p++)if(p!=a && p!=b && p!=c && p!=d){printf(" %d",p);break;}
                printf(" %d",d);
                for(p++;p<=n;p++)if(p!=a && p!=b && p!=c && p!=d)printf(" %d",p);
                printf(" %d\n%d %d",b,c,a);
                for(p=1;p<=n;p++)if(p!=a && p!=b && p!=c && p!=d){printf(" %d",p);break;}
                printf(" %d",b);
                for(int i=n;i>p;i--)if(i!=a && i!=b && i!=c && i!=d)printf(" %d",i);
                printf(" %d\n",d);
            }
        }
    }
    return 0;
}

