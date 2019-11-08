
#include<cstdio>
#include<cstring>
char s[500010];
bool val[500010],fan[500010];
int op[500010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s),vn=0,on=0;
        for(int i=0;i<len;++i){
            if(s[i]=='T'){
                val[vn]=true;
                fan[vn++]=true;
            }else if(s[i]=='F'){
                val[vn]=false;
                fan[vn++]=true;
            }else if(s[i]=='!'){
                op[on++]=s[i];
            }else if(s[i]=='('){
                op[on++]=s[i];
            }else if(s[i]=='&'){
                while(on>0 && op[on-1]=='!'){
                    val[vn-1]=!val[vn-1];
                    --on;
                }
                while(on>0 && op[on-1]=='&'){
                    bool tmp=val[vn-2]&&val[vn-1];
                    if(tmp){
                        fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                    }else{
                        fan[vn-2]=((val[vn-2] && fan[vn-1]) || (val[vn-1] && fan[vn-2]));
                    }
                    val[vn-2]=tmp;
                    --vn;
                    --on;
                }
                op[on++]=s[i];
            }else if(s[i]=='|'){
                while(on>0 && op[on-1]=='!'){
                    val[vn-1]=!val[vn-1];
                    --on;
                }
                while(on>0 && op[on-1]=='&'){
                    bool tmp=val[vn-2]&&val[vn-1];
                    if(tmp){
                        fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                    }else{
                        fan[vn-2]=((val[vn-2] && fan[vn-1]) || (val[vn-1] && fan[vn-2]));
                    }
                    val[vn-2]=tmp;
                    --vn;
                    --on;
                }
                while(on>0 && op[on-1]=='|'){
                    bool tmp=val[vn-2]||val[vn-1];
                    if(tmp){
                        fan[vn-2]=((!val[vn-2] && fan[vn-1]) || (!val[vn-1] && fan[vn-2]));
                    }else{
                        fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                    }
                    val[vn-2]=tmp;
                    --vn;
                    --on;
                }
                op[on++]=s[i];
            }else if(s[i]==')'){
                while(on>0 && op[on-1]=='!'){
                    val[vn-1]=!val[vn-1];
                    --on;
                }
                while(on>0 && op[on-1]=='&'){
                    bool tmp=val[vn-2]&&val[vn-1];
                    if(tmp){
                        fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                    }else{
                        fan[vn-2]=((val[vn-2] && fan[vn-1]) || (val[vn-1] && fan[vn-2]));
                    }
                    val[vn-2]=tmp;
                    --vn;
                    --on;
                }
                while(on>0 && op[on-1]=='|'){
                    bool tmp=val[vn-2]||val[vn-1];
                    if(tmp){
                        fan[vn-2]=((!val[vn-2] && fan[vn-1]) || (!val[vn-1] && fan[vn-2]));
                    }else{
                        fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                    }
                    val[vn-2]=tmp;
                    --vn;
                    --on;
                }
                --on;
                fan[vn-1]=true;
            }
//            printf("i=%d s=%c\n",i,s[i]);
//            printf("vn=%d on=%d\n",vn,on);
//            for(int i=0;i<vn;++i)printf("%d ",val[i]?1:0);printf("\n");
//            for(int i=0;i<vn;++i)printf("%d ",fan[i]?1:0);printf("\n");
//            for(int i=0;i<on;++i)printf("%c ",op[i]);printf("\n");
        }
        while(on>0){
            if(op[on-1]=='!'){
                val[vn-1]=!val[vn-1];
                --on;
            }
            else if(op[on-1]=='&'){
                bool tmp=val[vn-2]&&val[vn-1];
                if(tmp){
                    fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                }else{
                    fan[vn-2]=((val[vn-2] && fan[vn-1]) || (val[vn-1] && fan[vn-2]));
                }
                val[vn-2]=tmp;
                --vn;
                --on;
            }
            else if(op[on-1]=='|'){
                bool tmp=val[vn-2]||val[vn-1];
                if(tmp){
                    fan[vn-2]=((!val[vn-2] && fan[vn-1]) || (!val[vn-1] && fan[vn-2]));
                }else{
                    fan[vn-2]=(fan[vn-2] || fan[vn-1]);
                }
                val[vn-2]=tmp;
                --vn;
                --on;
            }
        }
//        printf("%d %d\n",val[0]?1:0,fan[0]?1:0);
        if(val[0]){
            printf("0\n");
        }else if(fan[0]){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }
    return 0;
}

