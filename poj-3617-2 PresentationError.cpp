
#include<cstdio>
char ss[2010],r[2010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)scanf("%s",&ss[i]);
        int s=0,e=n-1;
        for(int i=0;i<n;i++){
            int j;
            bool is=true;
            for(j=0;s+j<e-j;j++){
                if(ss[s+j]>ss[e-j]){
                    r[i]=ss[e];
                    e--;
                    is=false;
                    break;
                }else if(ss[s+j]<ss[e-j]){
                    r[i]=ss[s];
                    s++;
                    is=false;
                    break;
                }
            }
            if(is)r[i]=ss[s],s++;
          //  printf("%d %d\n",s,e);
        }
        r[n]=0;
        printf("%s\n",r);
    }
    return 0;
}

