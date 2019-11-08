
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[600],b[600];
int le[600],co[600],pon,ma[600];
int main(){
    int n1,n2;
    ll sum1,sum2;
    while(scanf("%d",&n1)!=EOF){
        sum1=sum2=0;
        for(int i=0;i<n1;i++){scanf("%I64d",&a[i]);sum1+=a[i];}
        scanf("%d",&n2);
        for(int i=0;i<n2;i++){scanf("%I64d",&b[i]);sum2+=b[i];}
        if(sum1!=sum2){
            printf("NO\n");
        }else{
            bool ans=true;
            int p=0;
            ll tmp=0;
            ll va;
            int cnt=0;
            bool ch=false;
            bool st=false;
            pon=0;
            for(int i=0;i<n2;i++){
                int sp=p,xm=a[p],pos=p;
                while(tmp<b[i]){
                    cnt++;
                    if(xm<a[p]){
                        xm=a[p];
                        pos=p;
                    }
                    if(st==false){
                        st=true;
                        va=a[p];
                    }else{
                        if(va!=a[p])ch=true;
                    }
                    tmp+=a[p];
                    p++;
                }
                if(tmp>b[i]){
                    ans=false;
                    break;
                }
                if(cnt>1 && ch==false){
                    ans=false;
                    break;
                }
                co[pon]=sp+1;
                le[pon]=p+1;
                ma[pon]=pos+1;
                pon++;
                cnt=0;
                ch=st=false;
                tmp=0;
            }
            if(ans==false){
                printf("NO\n");
            }else{
                printf("YES\n");
               // printf("pon=%d\n",pon);
                for(int i=pon-1;i>-1;i--){
                    bool is=false;
                    while(a[ma[i]]==a[ma[i]-1] && ma[i]+1<le[i])ma[i]++;
                    if(ma[i]==le[i]-1){
                        while(a[ma[i]-1]==a[ma[i]-2] && ma[i]-2>=co[i])ma[i]--;
                        is=true;
                    }
                  //  printf("%d %d %d %d is=%d\n",i,co[i],ma[i],le[i],is);
                    if(is==false){
                        for(int j=ma[i]+1;j<le[i];j++){
                            printf("%d R\n",ma[i]);
                        }
                        for(int j=ma[i];j>co[i];j--){
                            printf("%d L\n",j);
                        }
                    }else{
                        for(int j=ma[i];j>co[i];j--){
                            printf("%d L\n",j);
                        }
                        for(int j=ma[i]+1;j<le[i];j++){
                            printf("%d R\n",co[i]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

