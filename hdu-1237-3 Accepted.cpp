
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
        int i=0;
        while(s[i]==' ')i++;
        if(s[i]<'0' || s[i]>'9'){
            is=false;
            k1[kn1++]=0;
        }
        for(;i<l;i++){
            if(is){
                double add=0;
                while(s[i]!=' '&&s[i]){
                    add=add*10+s[i]-48;
                    i++;
                }
                k1[kn1++]=add;
                is=false;
            }else{
                st:
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
                        goto st;
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
                    goto st;
                }
                is=true;
                i++;
            }
            while(i+1<l&&s[i+1]==' ')i++;
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

