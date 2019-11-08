
#include<cstdio>
using namespace std;
char x[10][7000];
char r[70000];
char ty[3];
int main(){
    int d,s,b;
    int cas=1;
    while(1){
        scanf("%d",&d);
        if(!d)break;
        int p=0,rn=0;
        scanf("%d%d%s",&s,&b,ty);
        ty[0]=ty[0]=='E'?0:1;
        for(int i=0;i<d;i++){
            scanf("%s",x[i]);
        }
        bool ch=true;
        for(int i=0;i<b;i++){
            for(int j=0;j<s;j++){
                int tmp=i*s+j;
                int pos=-1;
                bool ans=false;
                for(int k=0;k<d;k++){
                    if(x[k][tmp]=='x'){
                        if(pos>-1){
                            ch=false;
                            break;
                        }else{
                            pos=k;
                        }
                    }else{
                        ans^=(x[k][tmp]-'0');
                    }
                }
                if(!ch)break;
                if(pos==-1){
                    if(ans!=ty[0]){
                        ch=false;
                        break;
                    }
                }else{
                    x[pos][tmp]=ty[0]^ans+'0';
                }
            }
            if(!ch)break;
            for(int k=0;k<d;k++){
                for(int j=0;j<s;j++){
                    if(k!=p)r[rn++]=x[k][i*s+j]-'0';
                }
            }
            p++;
            if(p==d)p=0;
        }
        if(ch){
            printf("Disk set %d is valid, contents are: ",cas);
            while(rn%4)r[rn++]=0;
            for(int i=0;i<rn;i+=4){
                int tt=(r[i]<<3)+(r[i+1]<<2)+(r[i+2]<<1)+r[i+3];
                printf("%X",tt);
            }
        }else{
            printf("Disk set %d is invalid.",cas);
        }
        printf("\n");
        cas++;
    }
}

