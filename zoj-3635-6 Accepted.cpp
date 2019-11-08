
    #include<iostream>  
    #include<cstring>  
    #include<string>  
    #include<cstdio>  
    #define sca(a) scanf("%d",&a)  
    #define mem(a,b) memset(a,b,sizeof(a))  
    using namespace std;  
    int c[50005],a[50005],b,n;  
    void update(int x,int num)  
    {  
        for(int i=x; i<=n; i+=i&(-i))  
            c[i]+=num;  
    }  
    int sum(int x)  
    {  
        int ans=0;  
        for(int i=x; i>=1; i-=i&(-i))  
            ans+=c[i];  
        return ans;  
    }  
    int main()  
    {  
        int i,j,m;  
        while(~sca(n))  
        {  
            mem(c,0);  
            for(i=1; i<=n; i++)  
                update(i,1);  
            for(i=1; i<=n; i++)  
            {  
                sca(m);  
                int l=1,r=n;  
                while(l<=r)  
                {  
                    int mid=(l+r)/2,s=sum(mid);  
                    if(s>=m) r=mid-1;  
                    else l=mid+1;  
                }  
                a[i]=l;  
                update(l,-1);  
            }  
            sca(m);  
            for(i=0; i<m-1; i++)  
            {  
                sca(b);  
                printf("%d ",a[b]);  
            }  
            sca(b);  
            printf("%d\n",a[b]);  
        }  
        return 0;  
    }  

