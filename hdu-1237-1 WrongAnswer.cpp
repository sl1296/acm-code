
#include<cstdio>
#include<cstring>
double k1[210];
char k2[210];
int kn1,kn2;
char s[210];
int main(){
    while(1){
        gets(s);
        if(strcmp(s,"0")==0)break;
        kn1=kn2=0;
        int l=strlen(s);
        bool is=true;
        for(int i=0;i<l;i++){
            if(is){
                double add=0;
                while(s[i]!=' '&&s[i]){
                    add=add*10+s[i]-48;
                    i++;
                }
                k1[kn1++]=add;
                is=false;
            }else{
                if(kn2==0)k2[kn2++]=s[i];
                else if(s[i]=='*'||s[i]=='/'){
                    if(k2[kn2-1]=='+'||k2[kn2-1]=='-'){
                        k2[kn2++]=s[i];
                    }else{
                        kn2--;
                        if(k2[kn2]=='*'){
                            k1[kn1-2]*=k1[kn1-1];
                        }else{
                            k1[kn1-2]/=k1[kn1-1];
                        }
                        kn1--;
                        k2[kn2++]=s[i];
                    }
                }else{
                    kn2--;
                    if(k2[kn2]=='+'){
                        k1[kn1-2]+=k1[kn1-1];
                    }else if(k2[kn2]=='-'){
                        k1[kn1-2]-=k1[kn1-1];
                    }else if(k2[kn2]=='*'){
                        k1[kn1-2]*=k1[kn1-1];
                    }else{
                        k1[kn1-2]/=k1[kn1-1];
                    }
                    kn1--;
                    k2[kn2++]=s[i];
                }
                is=true;
                i++;
            }
        }
        while(kn2){
            kn2--;
            if(k2[kn2]=='+'){
                k1[kn1-2]+=k1[kn1-1];
            }else if(k2[kn2]=='-'){
                k1[kn1-2]-=k1[kn1-1];
            }else if(k2[kn2]=='*'){
                k1[kn1-2]*=k1[kn1-1];
            }else{
                k1[kn1-2]/=k1[kn1-1];
            }
            kn1--;
        }
        printf("%.2f\n",k1[0]);
    }
    return 0;
}

