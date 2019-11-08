
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
map<char,int> s1;
map<int,int> s2;
int re[100010],rn;
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n,z,i,j,l;
    char s[100];
    s1['A']=s1['B']=s1['C']=s1['2']=2;
    s1['D']=s1['E']=s1['F']=s1['3']=3;
    s1['G']=s1['H']=s1['I']=s1['4']=4;
    s1['J']=s1['K']=s1['L']=s1['5']=5;
    s1['M']=s1['N']=s1['O']=s1['6']=6;
    s1['P']=s1['R']=s1['S']=s1['7']=7;
    s1['T']=s1['U']=s1['V']=s1['8']=8;
    s1['X']=s1['Y']=s1['W']=s1['9']=9;
    s1['0']=0;
    s1['1']=1;
    scanf("%d",&n);
    for(z=0;z<n;z++){
        scanf("%s",s);
        l=strlen(s);
        j=0;
        for(i=0;i<l;i++){
            if(s[i]=='-')continue;
            j=j*10+s1[s[i]];
        }
        if(s2.find(j)==s2.end()){
            s2[j]=1;
        }else{
            s2[j]++;
            if(s2[j]==2){
                re[rn]=j;
                rn++;
            }
        }
    }
    qsort(re,rn,sizeof(int),*cmp);
    for(i=0;i<rn;i++){
        printf("%03d-%04d %d\n",re[i]/10000,re[i]%10000,s2[re[i]]);
    }
    if(!rn)printf("No duplicates.\n");
    return 0;
}

