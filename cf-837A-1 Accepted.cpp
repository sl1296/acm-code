
#include<cstdio>
char s[300];
int main(){
    int n;
    while(~scanf("%d",&n)){
        gets(s);
        gets(s);
        int re=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]<='Z'&&s[i]>='A')cnt++;
            else if(s[i]==' '){
                if(re<cnt)re=cnt;
                cnt=0;
            }
        }
        if(re<cnt)re=cnt;
        printf("%d\n",re);
    }
    return 0;
}

