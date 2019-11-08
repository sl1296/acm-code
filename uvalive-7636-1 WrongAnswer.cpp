
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[100];
char op[100];
int main(){
    int a,n;
    while(~scanf("%s%d",str,&n)){
        if((strlen(str)==1&&str[0]=='0'&&n==0)||n==0)break ;
        if(str[0]=='0'&&str[1]=='x'){
            sscanf(str+2,"%x",&a);
        }else if(str[0]=='0'){
            sscanf(str+1,"%o",&a) ;
        }else{
            sscanf(str,"%d",&a) ;
        }
        //printf("%d %d\n",a,n);

        int sum = 0 ;
        int pre = a ;
        for(int i=0;i<n;i++){
            int b ;
            scanf("%s%d",op,&b) ;
            if(strcmp("++i",op)==0){
                if(pre+1==b)sum++ ;
                pre = b ;
            }else if(strcmp("i++",op)==0){
                if(pre==b)sum++ ;
                pre = b+1 ;
            }else if(strcmp("i--",op)==0){
                if(pre==b)sum++;
                pre = b-1 ;
            }else if(strcmp("--i",op)==0){
                if(pre-1==b)sum++ ;
                pre = b ;
            }
        }
        printf("%d\n",sum) ;
    }
    return 0;
}


