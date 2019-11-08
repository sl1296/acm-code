
#include<cstdio>
char s[4][5][4]={
    {
        "ooo",
        "..o",
        "ooo",
        "o..",
        "ooo"
    },
    {
        "ooo",
        "o.o",
        "o.o",
        "o.o",
        "ooo"
    },
    {
        "ooo",
        ".o.",
        ".o.",
        ".o.",
        "ooo"
    },
    {
        "ooo",
        "o.o",
        "ooo",
        "o.o",
        "ooo"
    }
};
int main(){
    int w;
    scanf("%d",&w);
    for(int i=0;i<5;++i){
        for(int j=0;j<4;++j){
            if(j){
                for(int ii=0;ii<w;++ii)printf(".");
            }
            for(int k=0;k<3;++k)printf("%c",s[j][i][k]);
        }
        printf("\n");
    }
    return 0;
}

