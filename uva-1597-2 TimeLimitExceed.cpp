
#include<cstdio>
#include<cstring>
char ar[110][1510][85];
int line[110];
char in[1010];
int out[100],outc;
bool pp(char *s,int from,int to){
    if(from>=to)return false;
  /*  printf("find:|");
    for(int i=from;i<to;i++)printf("%c",in[i]);
    printf("|\n");*/
    for(int i=0;s[i];i++){
        bool pd=true;
        for(int j=from,k=0;j<to;j++,k++){
            char tmp1=s[i+k],tmp2=in[j];
            if(tmp1>='A'&&tmp1<='Z')tmp1+=32;
            if(tmp2>='A'&&tmp2<='Z')tmp2+=32;
            if(tmp1!=tmp2){
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
        gets(ar[0][0]);
        memset(line,0,sizeof(line));
        for(int i=0;i<n;i++){
            while(1){
                gets(ar[i][line[i]]);
                if(strcmp(ar[i][line[i]],"**********")==0)break;
                line[i]++;
            }
        }
        int q;
        scanf("%d",&q);
        gets(in);
        for(int i=0;i<q;i++){
            if(i)printf("==========\n");
            gets(in);
            int len=strlen(in);
            while(len-1>=0&&in[len-1]==' ')len--;
            int type=0;
            int pos;
            int st=0;
            while(in[st]==' ')st++;
            if(in[st]=='N'&&in[st+1]=='O'&&in[st+2]=='T'){
                type=1;
                pos=st;
            }else{
                for(int i=0;i<len;i++){
                    if(in[i]=='A'&&in[i+1]=='N'&&in[i+2]=='D'){
                        type=2;
                        pos=i;
                    }else if(in[i]=='O'&&in[i+1]=='R'){
                        type=3;
                        pos=i;
                    }
                }
            }
            int cnt=0;
            if(type==0){
                for(int i=0;i<n;i++){
                    outc=0;
                    for(int j=0;j<line[i];j++){
                        if(pp(ar[i][j],st,len))out[outc++]=j;
                    }
                    if(outc){
                        if(cnt)printf("----------\n");
                        for(int xx=0;xx<outc;xx++){
                            printf("%s\n",ar[i][out[xx]]);
                        }
                        cnt++;
                    }
                }
            }else if(type==1){
                st+=3;
                while(in[st]==' ')st++;
                for(int i=0;i<n;i++){
                    bool ans=false;
                    for(int j=0;j<line[i];j++){
                        if(pp(ar[i][j],st,len)){
                            ans=true;
                            break;
                        }
                    }
                    if(ans==false){
                        if(cnt)printf("----------\n");
                        for(int j=0;j<line[i];j++){
                            printf("%s\n",ar[i][j]);
                        }
                        cnt++;
                    }
                }
            }else if(type==2){
                int tmp=pos;
                while(tmp-1>=0&&in[tmp-1]==' ')tmp--;
                pos+=3;
                while(in[pos]==' ')pos++;
                for(int i=0;i<n;i++){
                    bool r1=false,r2=false;
                    outc=0;
                    for(int j=0;j<line[i];j++){
                        if(pp(ar[i][j],st,tmp))r1=true;
                        if(pp(ar[i][j],pos,len))r2=true;
                        if(pp(ar[i][j],st,tmp)||pp(ar[i][j],pos,len))out[outc++]=j;
                    }
                    if(r1&&r2){
                        if(cnt)printf("----------\n");
                        for(int j=0;j<outc;j++){
                            printf("%s\n",ar[i][out[j]]);
                        }
                        cnt++;
                    }
                }
            }else{
                int tmp=pos;
                while(tmp-1>=0&&in[tmp-1]==' ')tmp--;
                pos+=2;
                while(in[pos]==' ')pos++;
                for(int i=0;i<n;i++){
                    outc=0;
                    for(int j=0;j<line[i];j++){
                        if(pp(ar[i][j],st,tmp)||pp(ar[i][j],pos,len))out[outc++]=j;
                    }
                    if(outc){
                        if(cnt)printf("----------\n");
                        for(int j=0;j<outc;j++){
                            printf("%s\n",ar[i][out[j]]);
                        }
                        cnt++;
                    }
                }
            }
        }
    }
    return 0;
}

