# include <stdio.h>
main()
{
  int a[10],i,j,t;
  printf("Please input 10 numbers: ");
  /*输入源数据*/
  for(i=0;i<10;i++)
    scanf("%d",&a[i]);
  /*排序*/
  for(j=0;j<9;j++)   	/*外循环控制排序趟数，n个数排n-1趟*/
    for(i=0;i<9-j;i++)  	/*内循环每趟比较的次数，第j趟比较n-j次*/
      if(a[i]>a[i+1])   	/*相邻元素比较，逆序则交换*/
      { t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
      }
  /*输出排序结果*/
  printf("The sorted numbers: ");
  for(i=0;i<10;i++)
    printf("%d   ",a[i]);
  printf("\n");
}
