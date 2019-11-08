
#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[100010],g[100010],f[100010];
LL al[100010];
bool l[100010],r[100010];
bool ll[100010],rl[100010];
int re;
vector<int> rs,rt,rsl,rtl;
void out(){
    printf("YES\n%d\n",re);
    for(int i=0;i<re;i++)printf("%d %d\n",rs[i],rt[i]);
}
int main(){
    int t,n;
    LL sum,k;
    scanf("%d",&t);
    while(t--){
        rs.clear();
        rt.clear();
        re=0;
        memset(l,false,sizeof(l));
        memset(r,false,sizeof(r));
        sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        bool is=true;
        if(sum%n){
            printf("NO\n");
            continue;
        }
        if(n==1){
            printf("YES\n0\n");
            continue;
        }
        k=sum/n;
        int s;
        for(int i=0;i<n;i++){
            if(a[i]-k>2 || k-a[i]>2){
                is=false;
                break;
            }
            if(a[i]-k==2){
                s=i-1;
                if(s==-1)s=n-1;
                rs.push_back(i);
                rt.push_back(s);
                re++;
                while(1){
                    if(a[s]>k || l[s]){
                        is=false;
                        break;
                    }else if(a[s]<k){
                        a[s]++;
                        break;
                    }
                    l[s]=true;
                    rs.push_back(s);
                    s--;
                    if(s==-1)s=n-1;
                    rt.push_back(s);
                    re++;
                }
                if(!is)break;
                s=i+1;
                if(s==n)s=0;
                rs.push_back(i);
                rt.push_back(s);
                re++;
                while(1){
                    if(a[s]>k || l[s]){
                        is=false;
                        break;
                    }else if(a[s]<k){
                        a[s]++;
                        break;
                    }
                    r[s]=true;
                    rs.push_back(s);
                    s++;
                    if(s==n)s=0;
                    rt.push_back(s);
                    re++;
                }
                a[i]-=2;
                if(!is)break;
            }
        }
        if(!is){
            printf("NO\n");
            continue;
        }
        for(int i=0;i<n;i++){
            if(k-a[i]==2){
                s=i-1;
                if(s==-1)s=n-1;
                while(a[s]<=k){
                    s--;
                    if(s==-1)s=n-1;
                    if(r[s]){
                        is=false;
                        break;
                    }
                    r[s]=true;
                }
                if(r[s])is=false;
                if(!is)break;
                r[s]=true;
                a[s]--;
                while(s!=i){
                    rs.push_back(s);
                    s++;
                    if(s==n)s=0;
                    rt.push_back(s);
                    re++;
                }
                s=i+1;
                if(s==n)s=0;
                while(a[s]<=k){
                    s++;
                    if(s==n)s=0;
                    if(l[s]){
                        is=false;
                        break;
                    }
                    l[s]=true;
                }
                if(l[s])is=false;
                if(!is)break;
                l[s]=true;
                a[s]--;
                while(s!=i){
                    rs.push_back(s);
                    s--;
                    if(s==-1)s=n-1;
                    rt.push_back(s);
                    re++;
                }
                a[i]+=2;
            }
        }
        if(!is){
            printf("NO\n");
            continue;
        }
        for(int i=0;i<n;i++){
            if(a[s]!=k){s=i;is=false;break;}
        }
        if(is){
            out();
            continue;
        }
        is=true;
        bool en=false;
        a[n]=a[s];
        int qf=-1;
        for(int i=s;i<=n;i++){
            if(a[i]==k+1){
                if(!en)s=i;
                else {
                    qf=i;
                    break;
                }
            }else if(a[i]==k-1){
                en=false;
            }
        }
        if(qf==-1){
            int rel;
            rsl=rs;
            rtl=rt;
            rel=re;
            for(int i=0;i<n;i++)ll[i]=l[i],rl[i]=r[i],al[i]=a[i];
            for(int i=0;i<n;i++){
                if(a[i]==k+1){
                    s=i;
                    while(a[s]!=k-1){
                        if(r[s]){
                            is=false;
                            break;
                        }
                        r[s]=true;
                        rs.push_back(s);
                        s++;
                        if(s==n)s=0;
                        rt.push_back(s);
                        re++;
                    }
                    if(!is)break;
                    a[s]++;
                    a[i]--;
                }
            }
            if(is){
                out();
                continue;
            }
            is=true;
            rs=rsl;
            rt=rtl;
            re=rel;
            for(int i=0;i<n;i++)l[i]=ll[i],r[i]=rl[i],a[i]=al[i];
            for(int i=0;i<n;i++){
                if(a[i]==k+1){
                    s=i;
                    while(a[s]!=k-1){
                        if(l[s]){
                            is=false;
                            break;
                        }
                        l[s]=true;
                        rs.push_back(s);
                        s--;
                        if(s==-1)s=n-1;
                        rt.push_back(s);
                        re++;
                    }
                    if(!is)break;
                    a[s]++;
                    a[i]--;
                }
            }
            if(is){
                out();
                continue;
            }else{
                printf("NO\n");
                continue;
            }
        }else{
            if(qf!=n){
                for(int i=0;i<n;i++)al[i]=a[(i+qf)%n];
                for(int i=0;i<n;i++)a[i]=al[i];
            }
            for(int i=0;i<n;i++){
                if(a[i]==k+1){
                    s=i;
                    while(a[s]!=k-1){
                        if(l[s]){
                            is=false;
                            break;
                        }
                        s--;
                        if(s==-1)s=n-1;
                    }
                    if(is){
                        a[i]--;
                        a[s]++;
                        int tmp=i;
                        while(tmp!=s){
                            rs.push_back(tmp);
                            l[tmp]=true;
                            tmp--;
                            if(tmp==-1)tmp=n-1;
                            rt.push_back(tmp);
                            re++;
                        }
                    }else{
                        is=true;
                        s=i;
                        while(a[s]!=k-1){
                            if(r[s]){
                                is=false;
                                break;
                            }
                            s++;
                            if(s==n)s=0;
                        }
                        if(!is)break;
                        int tmp=i;
                        while(tmp!=s){
                            rs.push_back(tmp);
                            r[tmp]=true;
                            tmp++;
                            if(tmp==n)tmp=0;
                            rt.push_back(tmp);
                            re++;
                        }
                    }
                }
            }
            if(is){
                out();
                continue;
            }else{
                printf("NO\n");
                continue;
            }
        }
    }
    return 0;
}

