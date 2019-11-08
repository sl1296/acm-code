
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
char s[110][110];
int main(){
    map<char,int> ma;
    ma['R']=0;ma['G']=1;ma['B']=2;
    int x,y;
    while(~scanf("%d%d",&x,&y)){
        for(int i=0;i<x;i++)scanf("%s",s[i]);
        bool is=true;
        for(int i=0;i<x;i++){
            if(s[i][0]!=s[0][0]){
                is=false;
                break;
            }
        }
        if(is){
            int use[3]={0,0,0};
            if(y%3)printf("NO\n");
            else{
                int t=y/3;
                use[ma[s[0][0]]]=1;
                for(int i=0;i<t;i++){
                    if(i&&s[0][i]!=s[0][i-1]){
                        is=false;
                        break;
                    }
                    for(int j=0;j<x;j++){
                        if(s[j][i]!=s[0][i]){
                            is=false;
                            break;
                        }
                    }
                    if(!is)break;
                }
                if(!is){
                    printf("NO\n");
                    continue;
                }
                if(use[ma[s[0][t]]]){
                    printf("NO\n");
                    continue;
                }
                use[ma[s[0][t]]]=1;
                for(int i=t;i<2*t;i++){
                    if(i>t&&s[0][i]!=s[0][i-1]){
                        is=false;
                        break;
                    }
                    for(int j=0;j<x;j++){
                        if(s[j][i]!=s[0][i]){
                            is=false;
                            break;
                        }
                    }
                    if(!is)break;
                }
                if(!is){
                    printf("NO\n");
                    continue;
                }
                if(use[ma[s[0][t*2]]]){
                    printf("NO\n");
                    continue;
                }
                for(int i=t*2;i<y;i++){
                    if(i>t*2&&s[0][i]!=s[0][i-1]){
                        is=false;
                        break;
                    }
                    for(int j=0;j<x;j++){
                        if(s[j][i]!=s[0][i]){
                            is=false;
                            break;
                        }
                    }
                    if(!is)break;
                }
                if(!is){
                    printf("NO\n");
                    continue;
                }
                printf("YES\n");
            }
        }else{
            is=true;
            for(int i=0;i<y;i++){
                if(s[0][i]!=s[0][0]){
                    is=false;
                    break;
                }
            }
            if(is){


                int use[3]={0,0,0};
                if(x%3)printf("NO\n");
                else{
                    int t=x/3;
                    use[ma[s[0][0]]]=1;
                    for(int i=0;i<t;i++){
                        if(i&&s[i][0]!=s[i-1][0]){
                            is=false;
                            break;
                        }
                        for(int j=0;j<y;j++){
                            if(s[i][j]!=s[i][0]){
                                is=false;
                                break;
                            }
                        }
                        if(!is)break;
                    }
                    if(!is){
                        printf("NO\n");
                        continue;
                    }
                    if(use[ma[s[t][0]]]){
                        printf("NO\n");
                        continue;
                    }
                    use[ma[s[t][0]]]=1;
                    for(int i=t;i<2*t;i++){
                        if(i>t&&s[i][0]!=s[i-1][0]){
                            is=false;
                            break;
                        }
                        for(int j=0;j<y;j++){
                            if(s[i][j]!=s[i][0]){
                                is=false;
                                break;
                            }
                        }
                        if(!is)break;
                    }
                    if(!is){
                        printf("NO\n");
                        continue;
                    }
                    if(use[ma[s[t*2][0]]]){
                        printf("NO\n");
                        continue;
                    }
                    for(int i=t*2;i<x;i++){
                        if(i>t*2&&s[i][0]!=s[i-1][0]){
                            is=false;
                            break;
                        }
                        for(int j=0;j<y;j++){
                            if(s[i][j]!=s[i][0]){
                                is=false;
                                break;
                            }
                        }
                        if(!is)break;
                    }
                    if(!is){
                        printf("NO\n");
                        continue;
                    }
                    printf("YES\n");
                }



            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}

