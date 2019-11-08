
#include <stdio.h>
unsigned long long euler[5000010];
int main(){
    int t,i,a,b,j;
    euler[1]=1;
    for(i=2;i<5000001;i++)euler[i]=i;
    for(i=2;i<5000001;i++)if(euler[i]==i)for(j=i;j<5000001;j+=i)euler[j]=euler[j]/i*(i-1);
    for(i=2;i<5000001;i++)euler[i]=euler[i-1]+euler[i]*euler[i];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",i+1,euler[b]-euler[a-1]);
    }
    return 0;
}

