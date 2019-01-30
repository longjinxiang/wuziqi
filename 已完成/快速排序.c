#include<stdio.h>
void quicksort(int a[],int left,int right)
{
    int i,j,temp;
    i=left;
    j=right;
    temp=a[left];
    if(left>right)
        return;
    while(i!=j)
    {
        while(a[j]>=temp&&j>i)
            j--;
        if(j>i)
            a[i++]=a[j];
        while(a[i]<=temp&&j>i)
            i++;
        if(j>i)
            a[j--]=a[i];
    }
    a[i]=temp;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
void main()
{
  int a[10],i,j,t;
  printf("Please input 10 numbers:\n ");
  for(i=0;i<10;i++)
        scanf("%d",&a[i]);
  for(i=1;i<10;i++) /*外循环控制趟数，n个数从第2个数开始到最后共进行n-1次插入*/
    {
    t=a[i];     /*将待插入数暂存于变量t中*/
    }
    quicksort(a,0,9);
    /*排好序的结果*/
    for(i=0;i<10;i++)
        printf("%d\t",a[i]);
}
