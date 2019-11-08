
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a[200],b[200],c[310],d[310];
int main(){
	while(scanf("%s%s",a,b)!=EOF){
        memset(c,0,sizeof(c));
		int la=strlen(a);
		int lb=strlen(b);
		for(int i=0;i<la;i++)a[i]-='0';
		for(int i=0;i<lb;i++)b[i]-='0';
		strcpy(&c[la],b);
		int mmin=la+lb;
        for(int i=0;i<la+lb;i++){
            memset(d,0,sizeof(d));
            strcpy(&d[i],a);
            int start=min(la,i);
            int eend=max(la+lb,i+la);
            int len=eend-start;
            int j;
            for(j=start;j<eend;j++){
                if(c[j]+d[j]>3)break;
            }
            if(j>=eend && len<mmin)mmin=len;
        }
        printf("%d\n",mmin);
	}
	return 0;
}

