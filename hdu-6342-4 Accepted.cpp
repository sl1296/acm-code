
#include<cstdio>
#include<cstring>
char s[510];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        bool check=true;
        for(int i=0;i<len;i++){
            if(s[i]=='?'){
                if(i==1&&s[0]=='0')s[i]='+';
                else if(i-2>=0&&s[i-1]=='0'&&(s[i-2]=='+'||s[i-2]=='*'))s[i]='+';
                else s[i]='1';
            }
            if(i&&((s[i-1]=='*'||s[i-1]=='+')&&(s[i]=='*'||s[i]=='+'))){
                check=false;
                break;
            }
        }
        if(s[0]=='+'||s[0]=='*')check=false;
        if(s[len-1]=='+'||s[len-1]=='*')check=false;
        if(!check){
            printf("IMPOSSIBLE\n");
            continue;
        }
        int pre=0;
        for(int i=0;i<=len;i++){
            if(s[i]=='*'||s[i]=='+'||s[i]==0){
                if(pre!=i-1&&s[pre]=='0'){
                    check=false;
                    break;
                }
                pre=i+1;
            }
        }
        if(!check){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%s\n",s);
        }
    }
    return 0;
}

