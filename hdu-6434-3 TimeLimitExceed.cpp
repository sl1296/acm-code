
#include<cstdio>
namespace IO {
    const int MX = 4e7; //1e7Õ¼ÓÃÄÚ´æ11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
#define ll long long
int euler[40000001];
ll ans[20000001];
int main(){
    for(int i=1;i<40000001;i++)euler[i]=i;
    for(int i=2;i<40000001;i++)if(euler[i]==i)for(int j=i;j<40000001;j+=i)euler[j]=euler[j]/i*(i-1);
    for(int i=1;i<20000001;i++){
        ans[i]=ans[i-1]+euler[i*2]/2;
    }
    IO::begin();
    int t,n;
    IO::read(t);
//    scanf("%d",&t);
    while(t--){
//        scanf("%d",&n);
        IO::read(n);
        printf("%lld\n",ans[n]);
    }
}

