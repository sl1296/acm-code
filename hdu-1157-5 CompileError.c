
/*
0_0_16685078_23935.c
LIBCMT.lib(crt0.obj) : error LNK2019: 无法解析的外部符号 _main，该符号在函数 ___tmainCRTStartup 中被引用
0_0_16685078_23935.exe : fatal error LNK1120: 1 个无法解析的外部命令
*/
#include <stdio.h>   #define MAXLEN 10010     void main(){       int cows;       int i=0,j;       int milk[MAXLEN];       int count,med;       scanf("%d",&cows);       med=cows/2; //为下标         while(cows--)   scanf("%d",&milk[i++]); //0号要使用.beak时,cows==-1,i为牛数       for(cows=i,i=0;i<cows;i++){ //MARK!   搜索        for(j=0,count=0;j<cows;j++){               if(milk[i]>milk[j])  count++;           }//for           if(count==med)  break;       }//for       printf("%d",milk[i]);     }

