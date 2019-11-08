
#include<cstdio>
int main(){
    char s[10];
    scanf("%s",s);
    int n=0,a[110];
    while(~scanf("%d",&a[n]))n++;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    int c=0,b[110];
    for(int i=0;i<n;i++){
        while(i+1<n&&a[i]==a[i+1])i++;
        b[c]=a[i];
        c++;
    }
    if(s[0]=='A'){
        for(int i=0;i<c;i++){
            printf("%d ",b[i]);
        }
    }else{
        for(int i=c-1;i>=0;i--){
            printf("%d ",b[i]);
        }
    }
    return 0;
}

