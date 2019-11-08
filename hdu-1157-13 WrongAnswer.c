
#include<stdio.h>
#include<stdlib.h>
void creatheap(int *heap,int root,int len)
{
int done;
int j;
int temp;
j=2*root;
temp=heap[root];
done=0;
while(j<=len&&!done)
{
if(j<len)
if(heap[j]<heap[j+1])
j++;
if(temp>=heap[j])
done=1;
else
{
heap[j/2]=heap[j];
j=2*j;
}
}
heap[j/2]=temp;
}
void heap(int *heap,int len)
{
int i;
int temp;
for(i=(len/2);i>=1;i--)
creatheap(heap,i,len);
for(i=len-1;i>=1;i--)
{
temp=heap[i+1];
heap[i+1]=heap[1];
heap[1]=temp;
creatheap(heap,1,i);


}


}
void main()
{
int data[10000] ;
   int i,n; 
   scanf("%d",&n);
   for (i =1; i<=n;i++ )     
   scanf("%d",&data[i]);
   heap(data,n);    
      printf("%d ",data[(n+1)/2]);
   printf("\n");                
}

