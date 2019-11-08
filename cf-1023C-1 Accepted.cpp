
#include<cstdio>
char s[200010];
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,s);
    int now=0,num=k/2,left=0,right=0;
    for(int i=0;i<n;++i){
        if(s[i]=='('){
            if(left<num){
                ++left;
                ++now;
                printf("(");
            }
        }else{
            if(right<num&&now>0){
                ++right;
                --now;
                printf(")");
            }
        }
    }
    printf("\n");
    return 0;
}

