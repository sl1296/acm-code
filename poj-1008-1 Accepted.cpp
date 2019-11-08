
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s1[22][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char s2[22][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main(){
    int t,d,y,mf,num,ra,rb,rc,i;
    char m[10];
    scanf("%d",&t);
    printf("%d\n",t);
    while(t--){
        scanf("%d",&d);
        getchar();
        scanf("%s%d",m,&y);
        for(i=0;i<19;i++)if(strcmp(s1[i],m)==0)break;
        mf=i;
        num=y*365+mf*20+d+1;
        rc=num/260;
        num=num-260*rc;
        if(!num){
            num+=260;
            rc--;
        }
        ra=num%13;
        if(!ra)ra=13;
        rb=num%20;
        if(!rb)rb=20;
        rb--;
        printf("%d %s %d\n",ra,s2[rb],rc);
    }
    return 0;
}

