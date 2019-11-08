
#include <cstdio>
int euler[1000100];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int a,b,i,j,c,d,e;
    for(i=1;i<1000001;i++)euler[i]=i;
    for(i=2;i<1000001;i++)if(euler[i]==i)for(j=i;j<1000001;j+=i)euler[j]=euler[j]/i*(i-1);
    while(scanf("%d%d",&a,&b)!=EOF){
       // printf("%d ",euler[a]);
        c=b%euler[a];
        d=b/euler[a];
        if(c==0){
            c=euler[a];
            d--;
        }
        e=0;
        for(i=1;i<a;i++){
            if(gcd(i,a)==1)e++;
            if(e==c)break;
        }
        printf("%d\n",i+d*a);
    }
    return 0;
}

