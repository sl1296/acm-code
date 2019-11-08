
#include<bits/stdc++.h>
using namespace std;
int v[10010];
int main(){
    int x1=0,x2=1,y1=0,y2=0;
    int n;
    scanf("%d",&n);
    int a,b;
    int op=0;
    int x=1,y=0;
    int k=0;
    v[k++]=1;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(b==0) break;
        op=(op+b+4)%4;
        if(op==0){
            x2++;
            v[k++]=x2-x;
            x=x2;
        }else if(op==1){
            y2++;
            v[k++]=y2-y;
            y=y2;
        }else if(op==2){
            x1--;
            v[k++]=x-x1;
            x=x1;
        }else{
            y1--;
            v[k++]=y-y1;
            y=y1;
        }
    }
    for(int i=0;i<n;i++)
        printf("%d%c",v[i],i==n-1?'\n':' ');
    return 0;
}


