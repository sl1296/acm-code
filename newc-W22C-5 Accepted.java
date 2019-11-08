
import java.math.BigInteger;
import java.util.Scanner;
class node{
    BigInteger x;
    int c;
    public void add(node b) {
        if(b.c<c)return;
        if(b.c>c) {
            x=b.x;
            c=b.c;
        }else {
            x=x.add(b.x);
        }
    }
    public void mul(node b) {
        x=x.multiply(b.x);
        c+=b.c;
    }
}
public class Main {
    public static node cal(String x) {
        node num[]=new node[1010];
        int op[]=new int[1010];
        int sz=x.length(),now=0,opn=0;
        for(int i=0;i<1010;++i)num[i]=new node();
        for(int i=0;i<sz;++i) {
            if(x.charAt(i)=='x') {
                num[now].x=BigInteger.ONE;
                num[now].c=1;
                ++now;
            }else if(x.charAt(i)=='+') {
                while(opn>0 && op[opn-1]==2) {
                    num[now-2].mul(num[now-1]);
                    --now;
                    --opn;
                }
                op[opn]=1;
                ++opn;
            }else if(x.charAt(i)=='*') {
                op[opn]=2;
                ++opn;
            }else if(x.charAt(i)=='(') {
                op[opn]=3;
                ++opn;
            }else if(x.charAt(i)==')') {
                while(opn>0 && op[opn-1]!=3) {
                    if(op[opn-1]==1) {
                        num[now-2].add(num[now-1]);
                    }else {
                        num[now-2].mul(num[now-1]);
                    }
                    --now;
                    --opn;
                }
                --opn;
            }
        }
        while(opn>0) {
            if(op[opn-1]==1) {
                num[now-2].add(num[now-1]);
            }else {
                num[now-2].mul(num[now-1]);
            }
            --now;
            --opn;
        }
        return num[0];
         
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in=new Scanner(System.in);
        String a=in.nextLine(),b=in.nextLine();
        node la=cal(a);
        node lb=cal(b);
        if(la.c>lb.c) {
            System.out.println("1/0");
        }else if(la.c<lb.c) {
            System.out.println("0/1");
        }else {
            BigInteger gcd=la.x.gcd(lb.x);
            System.out.println(la.x.divide(gcd)+"/"+lb.x.divide(gcd));
        }
    }
 
}

