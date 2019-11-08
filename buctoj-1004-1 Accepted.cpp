
#include<cstdio>
#include<cstring>
char m[10],l[10];
void cal(int a,int b,int c,int d){
    printf("%c",l[d]);
    int pos;
    for(int i=a;i<=b;++i){
        if(m[i]==l[d]){
            pos=i;
            break;
        }
    }
    if(pos>a)cal(a,pos-1,c,c+pos-1-a);
    if(pos<b)cal(pos+1,b,d-(b-(pos+1))-1,d-1);
}
int main(){
    while(~scanf("%s%s",m,l)){
        int len=strlen(m);
        cal(0,len-1,0,len-1);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1004
    User: asdcvbn
    Language: C++
    Result: ÕýÈ·
    Time:3 ms
    Memory:1120 kb
****************************************************************/

