
#include<cstdio>
bool ch(int a,int b,int c,int x,int y){
    int u,v;
    u=c+b+c;
    v=c+a+c+a;
    if(u<=x&&v<=y||u<=y&&v<=x)return true;
    u=a+c+a;
    v=c+b+a+b;
    if(u<=x&&v<=y||u<=y&&v<=x)return true;
    u=b+a+c;
    v=b+a+c+a;
    if(u<=x&&v<=y||u<=y&&v<=x)return true;
    u=a+c+a+b+a;
    v=c+b;
    if(u<=x&&v<=y||u<=y&&v<=x)return true;
    u=a+b+c+a;
    v=b+a+c;
    if(u<=x&&v<=y||u<=y&&v<=x)return true;
    u=c+b+c;
    v=a+c+a+b;
    if(u<=x&&v<=y||u<=y&&v<=x)return true;
    return false;
}
int main(){
    int a,b,c,w,h;
    scanf("%d%d%d%d%d",&a,&b,&c,&w,&h);
    if(ch(a,b,c,w,h)||ch(a,c,b,w,h)||ch(b,a,c,w,h)||ch(b,c,a,w,h)||ch(c,a,b,w,h)||ch(c,b,a,w,h))printf("Yes\n");else printf("No\n");
    return 0;
}

