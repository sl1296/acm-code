
/*
F:\temp\17163977.41653\Main.cc:1:24: error: bits/stdc++.h: No such file or directory
F:\temp\17163977.41653\Main.cc: In function 'int main()':
F:\temp\17163977.41653\Main.cc:5: error: 'scanf' was not declared in this scope
F:\temp\17163977.41653\Main.cc:9: error: 'printf' was not declared in this scope
*/
#include<bits/stdc++.h>
int main(){
    long long n,k;
    while(1){
        scanf("%I64d%I64d",&n,&k);
        if(n==0&&k==0)break;
        long long ans=1;
        for(int i=1;i<=k;i++)ans=ans*(n-i+1)/i;
        printf("%I64d\n",ans);
    }
    return 0;
}

