
/*
0_0_16685077_5665.c
LIBCMT.lib(crt0.obj) : error LNK2019: �޷��������ⲿ���� _main���÷����ں��� ___tmainCRTStartup �б�����
0_0_16685077_5665.exe : fatal error LNK1120: 1 ���޷��������ⲿ����
*/
#include <stdio.h>   #define MAXLEN 100     void main(){       int cows;       int i=0,j;       int milk[MAXLEN];       int count,med;       scanf("%d",&cows);       med=cows/2; //Ϊ�±�         while(cows--)   scanf("%d",&milk[i++]); //0��Ҫʹ��.beakʱ,cows==-1,iΪţ��       for(cows=i,i=0;i<cows;i++){ //MARK!   ����        for(j=0,count=0;j<cows;j++){               if(milk[i]>milk[j])  count++;           }//for           if(count==med)  break;       }//for       printf("%d",milk[i]);     }

