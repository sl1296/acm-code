
//Memory Time   
//452K 0MS   
  
/*DFS*/  
  
#include<iostream>  
using namespace std;  
  
int n[7];  //��ֵΪi����Ʒ�ĸ���  
int SumValue;  //��Ʒ�ܼ�ֵ  
int HalfValue;  //��Ʒƽ�ּ�ֵ  
bool flag;    //����Ƿ���ƽ��SumValue  
  
void DFS(int value,int pre)  
{  
    if(flag)  
        return;  
  
    if(value==HalfValue)  
    {  
        flag=true;  
        return;  
    }  
  
    for(int i=pre;i>=1;i--)  
    {  
        if(n[i])  
        {  
            if(value+i<=HalfValue)  
            {  
                n[i]--;  
                DFS(value+i,i);  
  
                if(flag)  
                    break;  
            }  
        }  
    }  
    return;  
}  
  
int main(int i)  
{  
    int test=1;  
    while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6])  
    {  
        SumValue=0;  //��Ʒ�ܼ�ֵ  
  
        for(i=1;i<=6;i++)  
            SumValue+=i*n[i];  
  
        if(SumValue==0)  
            break;  
  
        if(SumValue%2)    //sumΪ�������޷�ƽ��  
        {  
            cout<<"Collection #"<<test++<<':'<<endl;  
            cout<<"Can't be divided."<<endl<<endl;    //ע���п���  
            continue;  
        }  
  
        HalfValue=SumValue/2;  
        flag=false;  
  
        DFS(0,6);  
  
        if(flag)  
        {  
            cout<<"Collection #"<<test++<<':'<<endl;  
            cout<<"Can be divided."<<endl<<endl;  
            continue;  
        }  
        else  
        {  
            cout<<"Collection #"<<test++<<':'<<endl;  
            cout<<"Can't be divided."<<endl<<endl;  
            continue;  
        }  
    }  
    return 0;  
}  

