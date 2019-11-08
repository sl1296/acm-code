
/*
0_0_20619008_20810.cpp:49:5: error: expected unqualified-id before 'while'
     while(scanf("%d",&n)!=EOF){
     ^
0_0_20619008_20810.cpp:53:5: error: expected unqualified-id before 'return'
     return 0;
     ^
0_0_20619008_20810.cpp:54:1: error: expected declaration before '}' token
 }
 ^
*/
#include<cstdio>
#include<algorithm>
using namespace std;
bool use[30][30][30][30];
char s[500010];
int main(){
   /* int n;
    use[0][0][0][0]=true;
    for(int i=4;i<500000;i++){
  //      if(i<450000){
       /*     for(int j=((i<450000)?25:15);j>-1;j--){
                if(use[s[i-3]][s[i-2]][s[i-1]][j]==false){
                    use[s[i-3]][s[i-2]][s[i-1]][j]=true;
                    s[i]=j;
                   // printf("%d ",j);
                    break;
                }
                if(j==0){
                    printf("i=%d",i);
                    getchar();
                }
            }*/
      /*  int k=0;
        while(1){
            int j=rand()%26;
            if(use[s[i-3]][s[i-2]][s[i-1]][j]==false){
                s[i]=j;break;
            }
            k++;
            if(k>10){
                printf("i=%d",i);getchar();
            }
        }
      //  }else{
       /*     for(int j=0;j<26;j++){
                if(use[s[i-3]][s[i-2]][s[i-1]][j]==false){
                    use[s[i-3]][s[i-2]][s[i-1]][j]=true;
                    s[i]=j;
                 //   printf("%d ",j);
                    break;
                }
                if(j==25){
                    printf("i=%d",i);
                    getchar();
                }
            }*/
      //  }
    }
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)printf("a");
        printf("\n");
    }
    return 0;
}

