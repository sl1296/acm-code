
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
char in[20010];
char ans[1000010];
int ansc;
char word[20010];
char low[20010];
int wc;
string k1[25]={"zero","one","two","three","four","five","six","seven","eight","nine",
"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string k2[25]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string k3[25]={"hundred","thousand","million","and"};
int main(){
    map<string,int> ma;
    for(int i=0;i<20;i++){
        ma[k1[i]]=100+i;
    }
    for(int i=0;i<8;i++){
        ma[k2[i]]=120+i*10;
    }
    for(int i=0;i<4;i++){
        ma[k3[i]]=200+i;
    }
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w+",stdout);
    int pp=0;
    while(gets(&in[pp])!=NULL){
        pp+=strlen(&in[pp]);
        in[pp++]='\n';
        in[pp]=0;
    }
    int pre=0;
    bool isdoing=false;
    bool isspace=true;
    bool ismillion=false;
    bool isthousand=false;
    bool ishundred=false;
    bool ishunand=false;
    bool ishunnum=false;
    bool havehun=true;
    bool iszero=false;
    bool havezero=false;
    bool havenum=true;
    int now,all;
    for(int i=0;i<pp;i++){
        if(in[i]<'A'||in[i]>'Z'&&in[i]<'a'||in[i]>'z'){
            if(isdoing==false){
                ans[ansc++]=in[i];
            }else if(in[i]!=' '&&in[i]!='\n'){
                isspace=false;
            }
        }else{
            bool reset=true;
            int from=i;
            wc=0;
            while(in[i]>='A'&&in[i]<='Z'||in[i]>='a'&&in[i]<='z')word[wc++]=in[i++];
            for(int j=0;j<wc;j++){
                if(word[j]<'a'){
                    low[j]=word[j]+32;
                }else{
                    low[j]=word[j];
                }
            }
            word[wc]=low[wc]=0;
            i--;
            int id=ma[low];
            gt:
            if((isspace==false||id==0)&&isdoing==true){
                int add=now+all,cc=0;
                char ad[15];
                while(add){
                    ad[cc++]=add%10;
                    add/=10;
                }
                for(int j=cc-1;j>=0;j--){
                    ans[ansc++]=ad[j]+48;
                }
                for(int j=pre;j<from;j++){
                    ans[ansc++]=in[j];
                }
                isdoing=false;
                reset=true;
            }
            if(id==0){
                for(int j=0;j<wc;j++){
                    ans[ansc++]=word[j];
                }
            }else{
                if(isdoing==false){
                    if(id>199){
                        for(int j=0;j<wc;j++){
                            ans[ansc++]=word[j];
                        }
                    }else if(id==100){
                        ans[ansc++]='0';
                    }else{
                        isdoing=true;
                        ismillion=isthousand=ishundred=ishunand=ishunnum=iszero=false;
                        havehun=true;
                        havezero=false;
                        havenum=true;
                        all=0;
                        now=id-100;
                    }
                }else{
                    bool en=false;
                    if(id==200){
                        if(havehun&&ishundred==false){
                            ishundred=true;
                            reset=false;
                        }else{
                            en=true;
                        }
                    }else if(id==203){
                        if(ishundred&&ishunand==false){
                            ishunand=true;
                            reset=false;
                            havezero=true;
                        }else{
                            en=true;
                        }
                    }else{
                        if(ishundred&&ishunand&&ishunnum==false){
                            if(id==201||id==202){
                                en=true;
                            }else{
                                now*=100;
                                ishunnum=true;
                            }
                        }else if(ishundred&&ishunand==false){
                            en=true;
                        }else if(ishundred==false){
                            if(id<101||id>109&&id<200)havehun=false;
                        }
                        if(en==false){
                            if(id==202){
                                if(ismillion||isthousand){
                                    en=true;
                                }else{
                                    ismillion=true;
                                    all+=now*1000000;
                                    now=0;
                                    ishunand=ishundred=ishunnum=false;
                                    havehun=true;
                                    iszero=false;
                                    havezero=false;
                                    havenum=true;
                                }
                            }else if(id==201){
                                if(isthousand){
                                    en=true;
                                }else{
                                    isthousand=true;
                                    all+=now*1000;
                                    now=0;
                                    ishunand=ishundred=ishunnum=false;
                                    havehun=true;
                                    iszero=false;
                                    havezero=false;
                                    havenum=true;
                                }
                            }else if(id==100){
                                if(havezero&&iszero==false){
                                    iszero=true;
                                    havenum=false;
                                }else{
                                    en=true;
                                }
                            }else{
                                if(havenum==false){
                                    en=true;
                                }else{
                                    int nn=now%100;
                                    if(nn==0){
                                        now+=id-100;
                                    }else if(nn<20){
                                        en=true;
                                    }else{
                                        if(nn%10==0&&id<110){
                                            now+=id-100;
                                        }else{
                                            en=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(en){
                        isspace=false;
                        goto gt;
                    }
                }
            }
            isspace=true;
            if(reset)pre=i+1;
        }
    }
    if(isdoing){
        int add=now+all,cc=0;
        char ad[15];
        while(add){
            ad[cc++]=add%10;
            add/=10;
        }
        for(int j=cc-1;j>=0;j--){
            ans[ansc++]=ad[j]+48;
        }
        for(int j=pre;j<pp;j++){
            ans[ansc++]=in[j];
        }
    }
    ans[ansc]=0;
    printf("%s",ans);
    return 0;
}


