
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
inline ll cal(ll x){
    ll r=1;
    ll t=1;
    for(ll i=1;i<=x;i*=2,t++){
        ll ss=i,ee=x-x%(i*2)+i;
        if(ee>x)ee-=(i*2);
        r+=((ee-ss)/(i*2)+1)*t;
    }
    return r;
}
inline ll cc(ll x){
    ll r=1;
    ll t=1;
    for(ll i=1;i<=x;i*=2,t++){
        ll ss=i,ee=x-x%(i*2)+i;
        if(ee>x)ee-=(i*2);
        ll sum1=ss+ee,sum2=(ee-ss)/(i*2)+1;
        if(sum1&1)sum2>>=1;else sum1>>=1;
        ll sum=(sum1%mod)*(sum2%mod)%mod*t%mod;
        r+=sum;
        if(r>=mod)r-=mod;
    }
    return r;
}
ll aa[100]={1};
int main(){
    for(int i=1;i<61;i++)aa[i]=aa[i-1]*2;
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll s=max(1LL,n/2-2);
        ll now=cal(s);
        while(now<n){
            s++;
            if(s%aa[30]==0){//31-60
                if(s%aa[45]==0){//46-60
                    if(s%aa[52]==0){//53-60
                        if(s%aa[56]==0){//57-60
                            if(s%aa[58]==0){//59-60
                                if(s%aa[59]==0){
                                    now+=60;//60
                                }else{
                                    now+=59;//59
                                }
                            }else{//57-58
                                if(s%aa[57]==0){
                                    now+=58;//58
                                }else{
                                    now+=57;//57
                                }
                            }
                        }else{//53-56
                            if(s%aa[54]==0){//55-56
                                if(s%aa[55]==0){
                                    now+=56;//56
                                }else{
                                    now+=55;//55
                                }
                            }else{//53-54
                                if(s%aa[53]==0){
                                    now+=54;//54
                                }else{
                                    now+=53;//53
                                }
                            }
                        }
                    }else{//46-52
                        if(s%aa[49]==0){//50-52
                            if(s%aa[51]==0){
                                now+=52;//52
                            }else if(s%aa[50]==0){
                                now+=51;//51
                            }else{
                                now+=50;//50
                            }
                        }else{//46-49
                            if(s%aa[47]==0){//48-49
                                if(s%aa[48]==0){
                                    now+=49;//49
                                }else{
                                    now+=48;//48
                                }
                            }else{//46-47
                                if(s%aa[46]==0){
                                    now+=47;//47
                                }else{
                                    now+=46;//46
                                }
                            }
                        }
                    }
                }else{//31-45
                    if(s%aa[37]==0){//38-45
                        if(s%aa[41]==0){//42-45
                            if(s%aa[43]==0){//44-45
                                if(s%aa[44]==0){
                                    now+=45;//45
                                }else{
                                    now+=44;//44
                                }
                            }else{//42-43
                                if(s%aa[42]==0){
                                    now+=43;//43
                                }else{
                                    now+=42;//42
                                }
                            }
                        }else{//38-41
                            if(s%aa[39]==0){//40-41
                                if(s%aa[40]==0){
                                    now+=41;//41
                                }else{
                                    now+=40;//40
                                }
                            }else{//38-39
                                if(s%aa[38]==0){
                                    now+=39;//39
                                }else{
                                    now+=38;//38
                                }
                            }
                        }
                    }else{//31-37
                        if(s%aa[34]==0){//35-37
                            if(s%aa[36]==0){
                                now+=37;//37
                            }else if(s%aa[35]==0){
                                now+=36;//36
                            }else{
                                now+=35;//35
                            }
                        }else{//31-34
                            if(s%aa[32]==0){//33-34
                                if(s%aa[33]==0){
                                    now+=34;//34
                                }else{
                                    now+=33;//33
                                }
                            }else{//31-32
                                if(s%aa[31]==0){
                                    now+=32;//32
                                }else{
                                    now+=31;//31
                                }
                            }
                        }
                    }
                }
            }else{
                if(s%aa[15]==0){
                    if(s%aa[22]==0){//23-30
                        if(s%aa[26]==0){//27-30
                            if(s%aa[28]==0){//29-30
                                if(s%aa[29]==0){
                                    now+=30;//30
                                }else{
                                    now+=29;//29
                                }
                            }else{//27-28
                                if(s%aa[27]==0){
                                    now+=28;//28
                                }else{
                                    now+=27;//27
                                }
                            }
                        }else{//23-26
                            if(s%aa[24]==0){//25-26
                                if(s%aa[25]==0){
                                    now+=26;//26
                                }else{
                                    now+=25;//25
                                }
                            }else{//23-24
                                if(s%aa[23]==0){
                                    now+=24;//24
                                }else{
                                    now+=23;//23
                                }
                            }
                        }
                    }else{//16-22
                        if(s%aa[19]==0){//20-22
                            if(s%aa[21]==0){
                                now+=22;//22
                            }else if(s%aa[20]==0){
                                now+=21;//21
                            }else{
                                now+=20;//20
                            }
                        }else{//16-19
                            if(s%aa[17]==0){//18-19
                                if(s%aa[18]==0){
                                    now+=19;//19
                                }else{
                                    now+=18;//18
                                }
                            }else{//16-17
                                if(s%aa[16]==0){
                                    now+=17;//17
                                }else{
                                    now+=16;//16
                                }
                            }
                        }
                    }
                }else{
                    if(s%aa[7]==0){//8-15
                        if(s%aa[11]==0){//12-15
                            if(s%aa[13]==0){//14-15
                                if(s%aa[14]==0){
                                    now+=15;//15
                                }else{
                                    now+=14;//14
                                }
                            }else{//12-13
                                if(s%aa[12]==0){
                                    now+=13;//13
                                }else{
                                    now+=12;//12
                                }
                            }
                        }else{//8-11
                            if(s%aa[9]==0){//10-11
                                if(s%aa[10]==0){
                                    now+=11;//11
                                }else{
                                    now+=10;//10
                                }
                            }else{//8-9
                                if(s%aa[8]==0){
                                    now+=9;//9
                                }else{
                                    now+=8;//8
                                }
                            }
                        }
                    }else{//1-7
                        if(s%aa[4]==0){//5-7
                            if(s%aa[6]==0){
                                now+=7;//7
                            }else if(s%aa[5]==0){
                                now+=6;//6
                            }else{
                                now+=5;//5
                            }
                        }else{//1-4
                            if(s%aa[2]==0){//3-4
                                if(s%aa[3]==0){
                                    now+=4;//4
                                }else{
                                    now+=3;//3
                                }
                            }else{//1-2
                                if(s%aa[1]==0){
                                    now+=2;//2
                                }else{
                                    now+=1;//1
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans=cc(s)-(now-n)*s%mod;
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
    return 0;
}

