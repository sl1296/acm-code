


#include<cstdio>
#include<cstring>
#define LL long long
const LL mod= 1000000007;
char s[1000010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        LL tmp=0;
        for(int i=0;i<len;i++){
            if(s[i]!='('){
                tmp=tmp*10+s[i]-48;
                if(tmp>=mod)tmp%=mod;
            }else{
                i++;
                int from=i;
                while(s[i]!=')'){
                    i++;
                }
                int to=i;
                i+=3;
                LL bs=0;
                while(s[i]!=')'){
                    bs=bs*10+s[i]-48;
                    i++;
                }
                for(int j=0;j<bs;j++){
                    for(int k=from;k<to;k++){
                        tmp=tmp*10+s[k]-48;
                        if(tmp>=mod)tmp%=mod;
                    }
                }
            }
        }
        printf("%I64d\n",tmp);
    }
    return 0;
}



