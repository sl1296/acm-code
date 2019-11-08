
    #include <cstdio>  
    #include <cstring>  
    #include <iostream>  
      
    using namespace std;  
      
    typedef long long ll;  
    ll a[100000000];  
      
    int main()  
    {  
        ll n, m;  
        while (~scanf("%I64d%I64d", &n, &m) && (n || m)) {  
            if (n - m < m)  
                m = n - m;  
            a[0] = 1;  
            for (int i = 1; i <= m; i++) {  
                a[i] = (n - i + 1) * a[i - 1] / i;  
            }  
            printf("%d\n", a[m]);  
        }  
        return 0;  
    }  

