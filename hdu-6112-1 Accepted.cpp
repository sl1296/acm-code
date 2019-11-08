


#include<cstdio>
bool pd(int x){
    if((x%4==0&&x%100!=0)||x%400==0)return true;
    return false;
}
char s[15];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int y=(s[0]-48)*1000+(s[1]-48)*100+(s[2]-48)*10+(s[3]-48);
        int m=(s[5]-48)*10+(s[6]-48);
        int d=(s[8]-48)*10+(s[9]-48);
        int ans;
        if(m==2&&d==29){
            int cnt=1;
            int day=0;
            int st=y+1;
            while(pd(st)==false)st++,cnt++;
            day+=(365*cnt+1);
            while(day%7){
                cnt=1;
                st++;
                while(pd(st)==false)st++,cnt++;
                day+=(365*cnt+1);
            }
            ans=st;
        }else{
            int st;
            if(m>2)st=y+1;else st=y;
            int cnt=1;
            int day=pd(st)?366:365;
            while(day%7){
                st++;
                day+=pd(st)?366:365;
                cnt++;
            }
            ans=cnt+y;
        }
        printf("%d\n",ans);
    }
    return 0;
}



