
#include<cstdio>
char s[6][6]={
"  +-+",
" /./|",
"+-+.+",
"|.|/ ",
"+-+  "
};
char r[1010][1010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int x=1+2*c+2*b,y=1+2*a+b*2;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                r[i][j]='.';
            }
        }
        int sx=x-2*b-3,sy=2*b-2;
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
                for(int k=0;k<c;k++){
                    int xx=sx+i*2-k*2;
                    int yy=sy-i*2+j*2;
                    for(int ii=0;ii<5;ii++){
                        for(int jj=0;jj<5;jj++){
                            if(s[ii][jj]!=' '){
                                r[xx+ii][yy+jj]=s[ii][jj];
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                printf("%c",r[i][j]);
            }
            printf("\n");
        }


    }
}

