
#include<bits/stdc++.h>
using namespace std;
int s[110],h[110],a[110],v[110],id[110];
bool is[110];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&s[i],&h[i]);--s[i];
        is[s[i]]=true;
        v[s[i]]=h[i];
        id[s[i]]=i+1;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    bool ans=true;
    int outt[110],otn;
    for(int i=0;i<n;++i){
//        printf("i=%d\n",i);
        bool fin=true;
        int from=i+1;
        otn=0;
        if(is[i]){
            outt[otn++]=id[i];
//            printf("add %d\n",id[i]);
        }
        while(1){
            int cc=0;
            int ths=-1;
//            printf("from=%d\n",from);
            for(int j=from-1;j>=0;--j){
                if(is[j]){
//                    printf("j=%d\n",j);
                    if(j!=i)++cc;
                    int nn=v[j];
                    bool ch=true;
                    for(int k=j;k<from;++k){
                        nn+=a[k];
                        if(nn<0){
                            ch=false;
                            break;
                        }
                    }
                    if(ch)ths=j;
                }
            }
            if(cc==0)break;
            if(ths==-1){
                fin=false;
                break;
            }
            outt[otn++]=id[ths];
//            printf("add %d\n",id[ths]);
            for(int k=ths+1;k<from;++k){
                if(is[k]){
                    outt[otn++]=id[k];
//                    printf("add %d\n",id[ths]);
                }
            }
            from=ths;
        }
        if(fin==false)continue;
        from=i;
        bool hv=false;
        for(int j=i;j>=0;--j){
            if(is[j])hv=true;
        }
        if(hv==false)--from;
        while(1){
            int cc=0;
            int ths=-1;
            for(int j=from+1;j<n;++j){
                if(is[j]){
//                    printf("j=%d\n",j);
                    if(j!=i)++cc;
                    int nn=v[j];
                    bool ch=true;
                    for(int k=j;k>from;--k){
                        nn+=a[k];
                        if(nn<0){
                            ch=false;
                            break;
                        }
                    }
                    if(ch)ths=j;
                }
            }
            if(cc==0)break;
            if(ths==-1){
                fin=false;
                break;
            }
            outt[otn++]=id[ths];
            for(int k=ths-1;k>from;--k){
                if(is[k])outt[otn++]=id[k];
            }
            from=ths;
        }
        if(fin==false)continue;
//        printf("--1--");
        printf("%d\n",i+1);
        for(int i=0;i<m;++i){
            if(i)printf(" ");
            printf("%d",outt[i]);
        }
        printf("\n");
        return 0;
    }
//    printf("---mid---\n");
    for(int i=0;i<n;++i){
        bool fin=true;
        int from=i-1;
        otn=0;
        if(is[i])outt[otn++]=id[i];
        while(1){
            int cc=0;
            int ths=-1;
            for(int j=from+1;j<n;++j){
                if(is[j]){
                    if(j!=i)++cc;
                    int nn=v[j];
                    bool ch=true;
                    for(int k=j;k>from;--k){
                        nn+=a[k];
//                        printf("nn=%d\n",nn);
                        if(nn<0){
                            ch=false;
                            break;
                        }
                    }
                    if(ch)ths=j;
                }
            }
            if(cc==0)break;
            if(ths==-1){
                fin=false;
                break;
            }
            outt[otn++]=id[ths];
            for(int k=ths-1;k>from;--k){
                if(is[k])outt[otn++]=id[k];
            }
            from=ths;
        }
        if(fin==false)continue;
        from=i;
        bool hv=false;
        for(int j=i;j<n;++j){
            if(is[j])hv=true;
        }
        if(hv==false)from=i+1;
        while(1){
            int cc=0;
            int ths=-1;
            for(int j=from-1;j>=0;--j){
                if(is[j]){
                    if(j!=i)++cc;
                    int nn=v[j];
                    bool ch=true;
                    for(int k=j;k<from;++k){
                        nn+=a[k];
                        if(nn<0){
                            ch=false;
                            break;
                        }
                    }
                    if(ch)ths=j;
                }
            }
            if(cc==0)break;
            if(ths==-1){
                fin=false;
                break;
            }
            outt[otn++]=id[ths];
            for(int k=ths+1;k<from;++k){
                if(is[k])outt[otn++]=id[k];
            }
            from=ths;
        }
        if(fin==false)continue;

        printf("%d\n",i+1);
        for(int i=0;i<m;++i){
            if(i)printf(" ");
            printf("%d",outt[i]);
        }
        printf("\n");
        return 0;
    }
    printf("-1\n");
    return 0;
}
/*
8 3
8 2
1 3
4 9
0 3 -5 0 -5 -4 -1 0
*/

