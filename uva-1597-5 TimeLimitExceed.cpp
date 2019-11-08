
#include<cstdio>
#include<cstring>
char art[2000][100];
char low[2000][100];
int len[2000];
int from[100],to[100];
char in[2000],inl[2000];
int out[2000],outc;
bool pp(int id,int ff,int tt){
    if(ff>=tt)return false;
    for(int i=0;i<len[id];i++){
        bool pd=true;
        for(int j=ff,k=0;j<tt;j++,k++){
            if(low[id][i+k]!=inl[j]){
                pd=false;
                break;
            }
        }
        if(pd)return true;
    }
    return false;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        gets(in);
        int line=0;
        for(int i=0;i<n;i++){
            from[i]=line;
            while(1){
                gets(art[line]);
                if(strcmp(art[line],"**********")==0)break;
                len[line]=strlen(art[line]);
                strcpy(low[line],art[line]);
                for(int j=0;j<len[line];j++){
                    if(low[line][j]>='A'&&low[line][j]<='Z')low[line][j]+=32;
                }
                line++;
            }
            to[i]=line;
        }
        int m;
        scanf("%d",&m);
        gets(in);
        for(int i=0;i<m;i++){
            bool oo=false;
            gets(in);
            int en=strlen(in);
            strcpy(inl,in);
            for(int j=0;j<en;j++){
                if(inl[j]>='A'&&inl[j]<='Z')inl[j]+=32;
            }
            int st=0;
            while(in[st]==' '&&st<en)st++;
            while(en-1>=0&&in[en-1]==' ')en--;
            int type=0,pos;
            if(in[st]=='N'&&in[st+1]=='O'&&in[st+2]=='T')type=1;
            for(int j=st;j<en;j++){
                if(in[j]=='A'&&in[j+1]=='N'&&in[j+2]=='D'){
                    type=2;
                    pos=j;
                    break;
                }
                if(in[j]=='O'&&in[j+1]=='R'){
                    type=3;
                    pos=j;
                    break;
                }
            }
            if(type==0){
                int cnt=0;
                for(int j=0;j<n;j++){
                    int cc=0;
                    for(int k=from[j];k<to[j];k++){
                        if(pp(k,st,en)){
                            if(cnt&&cc==0)printf("----------\n");
                            printf("%s\n",art[k]);
                            cc++;
                        }
                    }
                    if(cc)cnt++;
                }
                if(cnt)oo=true;
            }else if(type==1){
                st+=3;
                while(st<en&&in[st]==' ')st++;
                int cnt=0;
                for(int j=0;j<n;j++){
                    bool pd=true;
                    for(int k=from[j];k<to[j];k++){
                        if(pp(k,st,en)){
                            pd=false;
                            break;
                        }
                    }
                    if(pd){
                        if(cnt)printf("----------\n");
                        for(int k=from[j];k<to[j];k++){
                            printf("%s\n",art[k]);
                        }
                        cnt++;
                    }
                }
                if(cnt)oo=true;
            }else if(type==2){
                int left=pos;
                while(left-1>=0&&in[left-1]==' ')left--;
                int right=pos+3;
                while(right<en&&in[right]==' ')right++;
                int cnt=0;
                for(int j=0;j<n;j++){
                    bool f1=false,f2=false;
                    outc=0;
                    for(int k=from[j];k<to[j];k++){
                        bool t1=pp(k,st,left),t2=pp(k,right,en);
                        if(t1)f1=true;
                        if(t2)f2=true;
                        if(t1||t2)out[outc++]=k;
                    }
                    if(f1&&f2){
                        if(cnt)printf("----------\n");
                        for(int k=0;k<outc;k++){
                            printf("%s\n",art[out[k]]);
                        }
                        cnt++;
                    }
                }
                if(cnt)oo=true;
            }else{
                int left=pos;
                while(left-1>=0&&in[left-1]==' ')left--;
                int right=pos+2;
                while(right<en&&in[right]==' ')right++;
                int cnt=0;
                for(int j=0;j<n;j++){
                    int cc=0;
                    for(int k=from[j];k<to[j];k++){
                        if(pp(k,st,left)||pp(k,right,en)){
                            if(cnt&&cc==0)printf("----------\n");
                            printf("%s\n",art[k]);
                            cc++;
                        }
                    }
                    if(cc)cnt++;
                }
                if(cnt)oo=true;
            }
            if(oo==false){
                printf("Sorry, I found nothing.\n");
            }
            printf("==========\n");
        }
    }
    return 0;
}

